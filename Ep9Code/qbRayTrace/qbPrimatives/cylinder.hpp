/* ***********************************************************
	cylinder.hpp
	
	The cylinder class definition - A class for creating 
	cylinder primitive shapes.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 6 of the series,
	which may be found here:
	https://youtu.be/UTz7ytMJ2yk
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

#ifndef CYLINDER_H
#define CYLINDER_H

#include "objectbase.hpp"
#include "../gtfm.hpp"

namespace qbRT
{
	class Cylinder : public ObjectBase
	{
		public:
			// Default constructor.
			Cylinder();
			
			// Override the destructor.
			virtual ~Cylinder() override;
			
			// Override the function to test for intersections.
			virtual bool TestIntersection(	const qbRT::Ray &castRay, qbVector<double> &intPoint,
																			qbVector<double> &localNormal, qbVector<double> &localColor) override;
	};
}

#endif
