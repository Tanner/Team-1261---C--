//#include "WPILib.h"

#include "Constants.h"

#include "IterativeRobot.h"
#include "RobotDrive.h"
#include "Joystick.h"
#include "Compressor.h"

/**
 * This is a copy of the robot of Team 1261's 2010 robot - the Chimichanga
 * 
 * Useful Link: http://www.chiefdelphi.com/forums/showthread.php?t=81064
 */

class Chimichanga : public IterativeRobot
{
	RobotDrive *drivetrain;
	Compressor *compressor;
	
	Joystick *joystick;
	
public:
	Chimichanga(void)
	{
		drivetrain = new RobotDrive(PWM_DRIVE_FL, PWM_DRIVE_RL, PWM_DRIVE_FR, PWM_DRIVE_RR);
		drivetrain->SetInvertedMotor(drivetrain->kFrontLeftMotor, false);
		drivetrain->SetInvertedMotor(drivetrain->kRearLeftMotor, false);
		drivetrain->SetInvertedMotor(drivetrain->kFrontRightMotor, true);
		drivetrain->SetInvertedMotor(drivetrain->kRearRightMotor, true);
		
		compressor = new Compressor(DIO_PRESSURE, RELAY_COMPRESSOR);
		
		joystick = new Joystick(1);
	}
	
	/********************************* INIT FUNCTIONS *********************************/
	void RobotInit(void) {
		printf("Robot initializing...\n");
		
		//Stuff
		
		printf("Robot initialization complete.\n");
	}
	
	void DisabledInit(void) {
		printf("Robot disabled initializing...\n");
		
		//Stop the presses...
		drivetrain->Drive(0, 0);
		compressor->Stop();
		
		printf("Robot disabled initialization complete.\n");
	}

	void AutonomousInit(void) {
		printf("Robot autonomous initializing...\n");

		compressor->Start();
		
		printf("Robot autonomous initialization complete.\n");
	}

	void TeleopInit(void) {
		printf("Robot teleop initializing...\n");

		compressor->Start();
		
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
		//Stop the presses...
		drivetrain->Drive(0, 0);
		compressor->Stop();
	}
	
	void AutonomousContinuous(void) {
		//Stuff
	}
	
	void TeleopContinuous(void) {
		GetWatchdog().Feed();
		
		//Drive the robot
		drivetrain->ArcadeDrive(joystick->GetRawAxis(4),joystick->GetRawAxis(2));
	}
};

START_ROBOT_CLASS(Chimichanga);
