#include "PID.h"

#include <math.h>

PID::PID(float Kp, float Ki, float Kd, float period)
{
	P = Kp;
	I = Ki;
	D = Kd;
	
	maxOutput = 1.0;
	minOutput = -1.0;
	
	maxInput = 0;
	minInput = 0;
	
	continuous = false;
	enabled = false;
	setPoint = 0;
	
	prevError = 0;
	totalError = 0;
	tolerance = 0.05;
	
	result = 0;
	
	this->period = period;
	
	//Remove after done testing...
	enabled = true;
	continuous = true;
}

double PID::Calculate(double input)
{	
	if (enabled)
	{
		error = setPoint - input;
		if (continuous)
		{
			if (fabs(error) > 
				(maxInput - minInput) / 2)
			{
				if (error > 0)
					error = error  - maxInput + minInput;
				else
					error = error  +
					maxInput - minInput;
			}
		}
	
		if (((totalError + error) * I < maxOutput) &&
				((totalError + error) * I > minOutput))
			totalError += error;
		
		result = P * error + I * totalError + D * (error - prevError);
		prevError = error;
		
		if (result > maxOutput)
			result = maxOutput;
		else if (result < minOutput)
			result = minOutput;
		
		return result;
	} else {
		return 0;
	}
}

void PID::SetInputRange(double minInput, double maxInput)
{
	this->minInput = minInput;
	this->maxInput = maxInput;
}

void PID::SetOutputRange(double minOutput, double maxOutput)
{
	this->minOutput = minOutput;
	this->maxOutput = maxOutput;
}

void PID::SetSetPoint(double setPoint)
{
	if (maxInput > minInput)
	{
		if (setPoint > maxInput)
		{
			this->setPoint = maxInput;
		} else if (setPoint < minInput) {
			this->setPoint = minInput;
		} else {
			this->setPoint = setPoint;
		}
	} else {
		this ->setPoint = setPoint;
	}
}
