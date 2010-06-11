#ifndef _PID_H_
#define _PID_H_

/**
 * PID Class
 * 
 * YAY
 */
class PID
{
private:
	float P, I, D, maxOutput, minOutput, maxInput, minInput, prevError, tolerance, setPoint, result, period;
	double totalError, error;
	bool continuous, enabled;
public:
	PID(float p, float i, float d, float period = 0.05);
	double Calculate(double input);
	void SetInputRange(double minInput, double maxInput);
	void SetOutputRange(double minOutput, double maxOutput);
	void SetSetPoint(double setPoint);
};

#endif
