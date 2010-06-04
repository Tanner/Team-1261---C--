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
		
		//Stop the presses...
		drivetrain->Drive(0, 0);
		compressor->Stop();
	}
	
	void AutonomousContinuous(void) {
		printf("Running in autonomous continuous...\n");
		
		//Stuff
	}
	
	void TeleopContinuous(void) {
		printf("Running in teleop continuous...\n");
		
		GetWatchdog().Feed();
		
		//Drive the robot
		drivetrain->ArcadeDrive(driverJoystick->GetRawAxis(4),driverJoystick->GetRawAxis(2));
		
		//Run the kicker
		kicker->Act();
		
		printf("Left Side: %f \n", leftDrivetrainEncoder->GetRate());
		printf("Right Side: %f \n", rightDrivetrainEncoder->GetRate());
	}
};

START_ROBOT_CLASS(Chimichanga);
