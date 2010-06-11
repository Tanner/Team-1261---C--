#ifndef _1261_CONSTANTS_H_
#define _1261_CONSTANTS_H_

#include <vxWorks.h>

namespace
{
	//PWMs
	static const UINT32 PWM_DRIVE_FL = 2;
	static const UINT32 PWM_DRIVE_RL = 1;
	static const UINT32 PWM_DRIVE_FR = 4;
	static const UINT32 PWM_DRIVE_RR = 3;
	
	static const UINT32 PWM_ROLLER = 6;
	
	static const UINT32 PWM_WINCH = 5;
	
	//Relays
	static const UINT32 RELAY_COMPRESSOR = 1;
	
	//DIO
	static const UINT32 DIO_PRESSURE = 2;
	
	static const UINT32 DIO_ENCODER_DRIVE_LEFT_A = 7;
	static const UINT32 DIO_ENCODER_DRIVE_LEFT_B = 8;
	static const UINT32 DIO_ENCODER_DRIVE_RIGHT_A = 5;
	static const UINT32 DIO_ENCODER_DRIVE_RIGHT_B = 6;
	
	static const UINT32 DIO_ENCODER_KICKER_A = 4;
	static const UINT32 DIO_ENCODER_KICKER_B = 3;
	
	static const UINT32 DIO_ENCODER_ROLLER_A = 9;	//Change me
	static const UINT32 DIO_ENCODER_ROLLER_B = 10;	//Change me
	
	static const UINT32 DIO_ROLLER_SWITCH = 12;
	
	static const UINT32 DIO_KICKER_SWITCH = 1;
	
	//Solenoids
	static const UINT32 SOLENOID_SAIL_A = 3;
	static const UINT32 SOLENOID_SAIL_B = 4;
	
	//Joysticks
	static const UINT32 JOYSTICK_DRIVE = 1;
	static const UINT32 JOYSTICK_KICK = 2;
	
	//Kicker
	enum KickerModes
	{
		KICKER_MODE_STANDBY = 0,
		KICKER_MODE_ARMED = 1,
		KICKER_MODE_ARM = 2,
		KICKER_MODE_KICK = 3
	};
}

#endif
