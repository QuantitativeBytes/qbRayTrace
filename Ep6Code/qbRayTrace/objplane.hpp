/* ***********************************************************
	objectplane.hpp
	
	The ObjPlane class definition - A class derived from
	ObjectBase to implement finite planes.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 6 of the series,
	which may be found here:
	https://youtu.be/9K9ZYq6KgFY
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett	
	
***********************************************************/

// objplane.hpp

#ifndef OBJPLANE_H
#define OBJPLANE_H

#include "objectbase.hpp"
#include "gtfm.hpp"

namespace qbRT
{
	class ObjPlane : public ObjectBase
	{
		public:
			// Default constructor.
			ObjPlane();
		
			// Override the destructor.
			virtual ~ObjPlane() override;
		
			// Override the function to test for intersections.
			virtual bool TestIntersection(	const qbRT::Ray &castRay, qbVector<double> &intPoint,
																			qbVector<double> &localNormal, qbVector<double> &localColor) override;
																			
		private:
		
		
	};
}

#endif
