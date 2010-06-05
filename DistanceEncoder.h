#ifndef _DIST_ENCODER_H_
#define _DIST_ENCODER_H_

#include "Encoder.h"
#include "PIDSource.h"

#include <vxWorks.h>

class DistanceEncoder : public PIDSource
{
	Encoder* baseEncoder;
	
public:
	DistanceEncoder(Encoder *baseEncoder);
	double PIDGet();
};

#endif
