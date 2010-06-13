#include "Constants.h"
#include "Kicker.h"

#include "IterativeRobot.h"
#include "RobotDrive.h"
#include "Joystick.h"
#include "Compressor.h"
#include "Encoder.h"

/**
 * This is a copy of the robot of Team 1261's 2010 robot - the Chimichanga
 * 
 * Useful Link: http://www.chiefdelphi.com/forums/showthread.php?t=81064
 */

class Chimichanga : public IterativeRobot
{
	RobotDrive *drivetrain;
	Compressor *compressor;
	
	Encoder *leftDrivetrainEncoder;
	Encoder *rightDrivetrainEncoder;
	
	Joystick *driverJoystick;
	
	Kicker *kicker;
	
	static const float autonomousForwardPower = -0.5;
	
public:
	Chimichanga(void)
	{
		//Hardware
		drivetrain = new RobotDrive(PWM_DRIVE_FL, PWM_DRIVE_RL, PWM_DRIVE_FR, PWM_DRIVE_RR);
		drivetrain->SetInvertedMotor(drivetrain->kFrontLeftMotor, false);
		drivetrain->SetInvertedMotor(drivetrain->kRearLeftMotor, false);
		drivetrain->SetInvertedMotor(drivetrain->kFrontRightMotor, true);
		drivetrain->SetInvertedMotor(drivetrain->kRearRightMotor, true);
		
		compressor = new Compressor(DIO_PRESSURE, RELAY_COMPRESSOR);
		
		//Sensors
		leftDrivetrainEncoder = new Encoder(DIO_ENCODER_DRIVE_LEFT_A, DIO_ENCODER_DRIVE_LEFT_B);
		rightDrivetrainEncoder = new Encoder(DIO_ENCODER_DRIVE_RIGHT_A, DIO_ENCODER_DRIVE_RIGHT_B);
		
		driverJoystick = new Joystick(JOYSTICK_DRIVE);
		
		//Systems
		kicker = new Kicker();
	}
	
	/********************************* INIT FUNCTIONS *********************************/
	void RobotInit(void) {
		printf("Robot initializing...\n");

		GetWatchdog().Feed();
		
		printf("Robot initialization complete.\n");
	}
	
	void DisabledInit(void) {
		printf("Robot disabled initializing...\n");

		GetWatchdog().Feed();
		
		//Stop the presses...
		drivetrain->Drive(0.0, 0.0);
		compressor->Stop();
		
		printf("Robot disabled initialization complete.\n");
	}

	void AutonomousInit(void) {
		printf("Robot autonomous initializing...\n");

		GetWatchdog().Feed();
		
		compressor->Start();
		kicker->Reset();
		
		printf("Robot autonomous initialization complete.\n");
	}

	void TeleopInit(void) {
		printf("Robot teleop initializing...\n");

		GetWatchdog().Feed();
		
		compressor->Start();
		kicker->SafeReset();
		
		leftDrivetrainEncoder->Start();
		rightDrivetrainEncoder->Start();
		
		printf("Robot teleop initialization complete.\n");
	}
	
	/********************************* PERIODIC ROUTINES *********************************/
	void DisabledPeriodic(void) {
		//Stuff
	}
	
	void AutonomousPeriodic(void) {
		//Stuff
	}
	
	void TeleopPeriodic(void) {
		//Stuff
	}
	
	/******************************** CONTINUOUS ROUTINES ********************************/
	void DisabledContinuous(void) {
		printf("Running in disabled continuous...\n");

		GetWatchdog().Feed();
		
		//Stop the presses...
		drivetrain->Drive(0.0, 0.0);
		compressor->Stop();
	}
	
	void AutonomousContinuous(void) {
		printf("Running in autonomous continuous...\n");

		GetWatchdog().Feed();
		
		if (kicker->HasBall())
		{
			//We have a ball, thus stop moving and kick the ball
			drivetrain->Drive(0.0, 0.0);
			kicker->SetKickerMode(KICKER_MODE_KICK);
		} else {
			//We do not have a ball
			if (kicker->IsKickerInPosition())
			{
				//Move forward!
				drivetrain->ArcadeDrive(autonomousForwardPower, 0.0);
			} else {
				//If not in position, wait for it to be there...
				drivetrain->ArcadeDrive(0.0, 0.0);
				kicker->SetKickerMode(KICKER_MODE_ARM);
			}
		}
		
		//Run the kicker
		kicker->Act();
	}
	
	void TeleopContinuous(void) {
		printf("Running in teleop continuous...\n");
		
		GetWatchdog().Feed();
		
		//Drive the robot
		drivetrain->ArcadeDrive(driverJoystick->GetRawAxis(4),driverJoystick->GetRawAxis(2));
		
		//Run the kicker
		kicker->Act();
	}
};

START_ROBOT_CLASS(Chimichanga);
