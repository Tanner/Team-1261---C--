#include "WPILib.h"

#include "robotDrive.h"
#include "Joystick.h"

/**
 * This is a copy of the robot of Team 1261's 2010 robot - the Chimichanga
 * 
 * Useful Link: http://www.chiefdelphi.com/forums/showthread.php?t=81064
 */

class Chimichanga : public IterativeRobot
{
	RobotDrive *drivetrain;
	Joystick *joystick;
	
public:
	Chimichanga(void)
	{
		drivetrain = new RobotDrive(1, 2, 3, 4);
		joystick = new Joystick(1);
	}
	
	/*** INIT FUNCTIONS ***/
	void RobotInit(void) {
		//Stuff
	}
	
	void DisabledInit(void) {
		//Stuff
	}

	void AutonomousInit(void) {
		//Stuff
	}

	void TeleopInit(void) {
		//Stuff
	}
	
	/*** PERIODIC ROUTINES ***/
	void DisabledPeriodic(void) {
		//Stuff
	}
	
	void AutonomousPeriodic(void) {
		//Stuff
	}
	
	void TeleopPeriodic(void) {
		//Stuff
	}
};

START_ROBOT_CLASS(Chimichanga);
