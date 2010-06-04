#ifndef _1261_CONSTANTS_H_
#define _1261_CONSTANTS_H_

namespace
{
	//Drivetrain PWM Ports
	static const int PWM_DRIVE_FL = 2;
	static const int PWM_DRIVE_RL = 1;
	static const int PWM_DRIVE_FR = 4;
	static const int PWM_DRIVE_RR = 3;
	
	//Relays
	static const int RELAY_COMPRESSOR = 1;
	
	//DIO
	static const int DIO_PRESSURE = 2;
	static const int DIO_ENCODER_DRIVE_LEFT_A = 7;
	static const int DIO_ENCODER_DRIVE_LEFT_B = 8;
	static const int DIO_ENCODER_DRIVE_RIGHT_A = 5;
	static const int DIO_ENCODER_DRIVE_RIGHT_B = 6;
}

#endif
