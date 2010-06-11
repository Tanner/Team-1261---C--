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
	double setPoint, lastSetPoint;
	int kickerMode;
	
	const static int winchArmSpeed = 1;
	const static int winchBackwindSpeed = -1;
	
	const static int fullPowerBackwind = 1207;
	const static int slowPowerBackwind = 808;
	
	const static int fullPowerSetPoint = 0;
	const static int mediumPowerSetPoint = 150;
	const static int lowPowerSetPoint = 300;
	
	const static int minimumSetPoint = 300;
	
	const static int rollerOnSpeed = 1;
	const static double rollerReleaseBallSpeed = -0.2;
	
	const static int joystickKickButton = 5;
	const static int joystickSlowPowerButton = 3;
	const static int joystickMedPowerButton = 1;
	const static int joystickFullPowerButton = 2;
	
	const static int joystickEmergencyArmButton = 4;
	
	const static int joystickKickManualPowerAxis = 3;
	const static double joystickKickManualActivationValue = 0.01;
	
	const static double backwindTolerance = 0.1;
	
public:
	//Public Methods
	Kicker();
	void Act();
	void Reset();
	void SafeReset();
	
	bool HasBall();
	bool IsKickerInPosition();
	void SetKickerMode(int mode);
	
private:
	//Private Methods
	void EngageSailClutch(bool engage);
	void MoveRoller(bool rollerOn);
	void Backwind();
	void SetPower();
	
	void Arm();
	void Kick();
	void Armed();
};

#endif
