#include "DistanceEncoder.h"

/**
 * Make an encoder that I can use in a PID loop
 */
DistanceEncoder::DistanceEncoder(Encoder *baseEncoder)
{
	baseEncoder = baseEncoder;
}

double DistanceEncoder::PIDGet()
{
	return baseEncoder->GetDistance();
}
