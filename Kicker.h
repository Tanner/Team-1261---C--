#ifndef _KICKER_H_
#define _KICKER_H_

#include "Encoder.h"
#include "Victor.h"
#include "Solenoid.h"
#include "DigitalInput.h"
#include "Joystick.h"

class Kicker
{
	//Hardware
	Victor *winchMotor;
	Victor *rollerMotor;
	Solenoid *sailClutch_A;
	Solenoid *sailClutch_B;
	
	//Sensors
	Encoder *kickerEncoder;
	DigitalInput *rollerSwitch;
	DigitalInput *kickerSwitch;
	
	Joystick *kickerJoystick;
	
	bool kickerResetEncoder;
	bool kickerHitSwitch;
	bool kickerInPosition;
	bool rollerOn;
	double setPoint;
	int kickerMode;
	
	enum KickerModes
	{
		KICKER_MODE_STANDBY = 0,
		KICKER_MODE_ARMED = 1,
		KICKER_MODE_ARM = 2,
		KICKER_MODE_KICK = 3
	};
	
	const static int winchArmSpeed = 1;
	const static int winchBackwindSpeed = -1;
	const static int fullPowerBackwind = 1207;
	const static int slowPowerBackwind = 808;
	const static int minimumSetPoint = 300;
	
	const static int rollerOnSpeed = 1;
	const static double rollerReleaseBallSpeed = -0.2;
	
	const static int joystickKickButton = 1;
	const static int joystickEmergencyArmButton = 3;
	const static int joystickKickPowerAxis = 3;
	
public:
	//Public Methods
	Kicker();
	void Act();
	
private:
	//Private Methods
	void SailClutch(bool engage);
	void MoveRoller(bool rollerOn);
	void Backwind();
	void SetPower();
	
	void Arm();
	void Kick();
	void Armed();
};

#endif
