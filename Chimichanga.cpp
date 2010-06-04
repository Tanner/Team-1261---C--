//#include "WPILib.h"

#include "Constants.h"

#include "IterativeRobot.h"
#include "RobotDrive.h"
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
		drivetrain = new RobotDrive(PWM_DRIVE_FL, PWM_DRIVE_RL, PWM_DRIVE_FR, PWM_DRIVE_RR);
		drivetrain->SetInvertedMotor(drivetrain->kFrontLeftMotor, true);
		drivetrain->SetInvertedMotor(drivetrain->kRearLeftMotor, true);
		
		joystick = new Joystick(1);
	}
	
	/********************************* INIT FUNCTIONS *********************************/
	void RobotInit(void) {
		//Stuff
	}
	
	void DisabledInit(void) {
		//Stop the presses...
		drivetrain->Drive(0, 0);
	}

	void AutonomousInit(void) {
		//Stuff
	}

	void TeleopInit(void) {
		//Stuff
	}
	
	/********************************* PERIODIC ROUTINES *********************************/
	void DisabledPeriodic(void) {
		//Don't go anywhere...
		drivetrain->Drive(0, 0);
	}
	
	void AutonomousPeriodic(void) {
		//Stuff
	}
	
	void TeleopPeriodic(void) {
		//Drive the robot
		drivetrain->ArcadeDrive(joystick->GetRawAxis(4),joystick->GetRawAxis(2));
	}
};

START_ROBOT_CLASS(Chimichanga);
