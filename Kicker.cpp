#include "Constants.h"
#include "Kicker.h"

#include "Encoder.h"
#include "Solenoid.h"
#include "DigitalInput.h"
#include "Joystick.h"

#include "Math.h"
#include <vxWorks.h>

/**
 * Code for the kicker... Yay!
 */
Kicker::Kicker()
{
	//Hardware
	winchMotor = new Victor(PWM_WINCH);
	rollerMotor = new Victor(PWM_ROLLER);
	sailClutch_A = new Solenoid(SOLENOID_SAIL_A);
	sailClutch_B = new Solenoid(SOLENOID_SAIL_B);
	
	//Sensors
	kickerEncoder = new Encoder(DIO_ENCODER_KICKER_A, DIO_ENCODER_KICKER_B);
	rollerSwitch = new DigitalInput(DIO_ROLLER_SWITCH);
	kickerSwitch = new DigitalInput(DIO_KICKER_SWITCH);
	
	kickerJoystick = new Joystick(JOYSTICK_KICK);
	
	//Other Stuff
	rollerOn = true;
	
	kickerMode = KICKER_MODE_ARMED;
	kickerHitSwitch = false;
	kickerInPosition = false;
	
	kickerEncoder->Start();
}

void Kicker::Act()
{
	//Arm/Kick depending on the fire button on the kicker joystick
	if (kickerJoystick->GetRawButton(joystickKickButton) == 1)
	{
		//If the kicker is in standby mode, who cares - life is over
		//If the kicker is in arm mode, do nothing
		//If the kicker is in kicking mode, let it continue
		if (kickerMode == KICKER_MODE_ARMED)
		{
			//It's armed you say? Fire it baby!
			kickerMode = KICKER_MODE_KICK;
		}
	} else {
		//If the kicker is in armed mode, do nothing
		//If the kicker is in arm mode, it's good to hear that it worked
		//If the kicker is in kicking mode, let it continue
		if (kickerMode == KICKER_MODE_STANDBY)
		{
			//If kicker is on standby, arm it
			kickerMode = KICKER_MODE_ARM;
		}
	}
	
	//Emergency armed button for those strange occations when things don't work right
	if (kickerJoystick->GetRawButton(joystickEmergencyArmButton) == 1)
	{
		//Don't care where we are, just do it. I hate you.
		kickerMode = KICKER_MODE_ARMED;
	}
	
	MoveRoller(rollerOn);
	
	//Set the power set point based on the buttons
	if (kickerJoystick->GetRawButton(joystickSlowPowerButton))
	{
		setPoint = slowPowerBackwind;
	} else if (kickerJoystick->GetRawButton(joystickMedPowerButton)) {
		setPoint = mediumPowerBackwind;
	} else if (kickerJoystick->GetRawButton(joystickFullPowerButton)) {
		setPoint = fullPowerBackwind;
	} else {
		//If not are pressed, retain the value or use the trigger pot.
		double manualValue = fabs(kickerJoystick->GetRawAxis(joystickKickManualPowerAxis));
		if (manualValue > joystickKickManualActivationValue)
		{
			//Use the trigger value instead
			setPoint = manualValue * minimumSetPoint;
		}
	}	
	printf("Set Point: %f\n", setPoint);
	
	switch(kickerMode)
	{
		case KICKER_MODE_ARM:
			Arm();
			break;
		case KICKER_MODE_KICK:
			Kick();
			break;
		case KICKER_MODE_ARMED:
			Armed();
			break;
		case KICKER_MODE_STANDBY:
		default:
			//Waiting for things to happen...
			break;
	}
}

void Kicker::Arm()
{
	lastSetPoint = setPoint;
	
	rollerOn = true;
	
	//Switch is false when pressed
	if (!kickerSwitch->Get())
	{
		//Turn the motor off if we haven't already
		if (!kickerHitSwitch)
		{
			winchMotor->Set(0);
		}
		kickerHitSwitch = true;
	}
	
	if (kickerHitSwitch)
	{
		//Finalize the arming process
		if (kickerInPosition)
		{
			//Backwind the kicker for the actual kicking part
			Backwind();
		} else {
			//Keep getting into position...
			SetPower();
		}
	} else {
		//Get the kicker into the armed position
		EngageSailClutch(true);
		winchMotor->Set(winchArmSpeed);
	}
}

void Kicker::Kick()
{
	rollerOn = false;
	//Let the ball roll out a bit
	rollerMotor->Set(rollerReleaseBallSpeed);
	
	//In the words of Bethany Sumner, "Fire ze missiles!"
	EngageSailClutch(false);
	
	//And reset everything for another kick
	Reset();
}

void Kicker::Armed()
{
	//Stop the winch from winching and turn on the roller so we can get balls...
	winchMotor->Set(0);
	rollerOn = true;
}

void Kicker::Reset()
{
	//Reset everything for another run.
	kickerMode = KICKER_MODE_STANDBY;
	kickerHitSwitch = false;
	kickerInPosition = false;
	kickerResetEncoder = false;
}

void Kicker::SafeReset()
{
	//Do a safe reset (i.e. don't do anything when we're done with this)
	Reset();
	kickerMode = KICKER_MODE_ARMED;
}

void Kicker::SetPower()
{
	//Reset the encoder if we need to
	if (!kickerResetEncoder)
	{
		kickerEncoder->Reset();
		kickerResetEncoder = true;
	}
	
	if (lastSetPoint <= 0)
	{
		//Stop the kicker, even if we're at zero and supposed to be there (this comment makes no sense)
		EngageSailClutch(true);
		
		kickerResetEncoder = false;
		winchMotor->Set(0);
		kickerInPosition = true;
	} else {
		//Move the kicker to position (this is accurate enough)
		if (kickerEncoder->GetDistance() >= lastSetPoint)
		{
			//We MIGHT be in position... maybe... ish - lock the clutch and shut everything else off
			EngageSailClutch(true);
			
			kickerResetEncoder = false;
			winchMotor->Set(0);
			kickerInPosition = true;
		} else {
			//Move to position, sir yes sir!
			EngageSailClutch(false);
			winchMotor->Set(winchBackwindSpeed);
		}
	}
}

void Kicker::EngageSailClutch(bool engage)
{
	if (engage)
	{
		//Close the clutch (i.e. grip on the rope)
		sailClutch_A->Set(true);
		sailClutch_B->Set(false);
	} else {
		//Open the clutch
		sailClutch_A->Set(false);
		sailClutch_B->Set(true);
	}
}

void Kicker::MoveRoller(bool rollerOn)
{
	if (rollerOn)
	{
		if (rollerSwitch->Get())
		{
			rollerMotor->Set(rollerOnSpeed);
		} else {
			rollerMotor->Set(0);
		}
	} else {
		rollerMotor->Set(0);
	}
}

void Kicker::Backwind()
{
	EngageSailClutch(true);
	
	//Reset the encoder if we need to
	if (!kickerResetEncoder)
	{
		kickerEncoder->Reset();
		kickerResetEncoder = true;
	}
	
	double percentRelativeToLowPower = lastSetPoint / minimumSetPoint;
	double newBackwind = ((fullPowerBackwind - slowPowerBackwind) * (1 - percentRelativeToLowPower)) + slowPowerBackwind;
	
	//Backwind by using a PE loop
	double processVariable = fabs(kickerEncoder->GetDistance());
	double error = fabs(processVariable - newBackwind) / newBackwind;
	if (error <= backwindTolerance)
	{
		winchMotor->Set(0);
		kickerMode = KICKER_MODE_ARMED;
	} else {
		//Begin backwinding the motor to release tension...
		double motorSpeed = error * winchBackwindSpeed;
		winchMotor->Set(motorSpeed);
	}
}

bool Kicker::HasBall()
{
	return !rollerSwitch->Get();
}

bool Kicker::IsKickerInPosition()
{
	return kickerInPosition;
}

void Kicker::SetKickerMode(int mode)
{
	kickerMode = mode;
}
