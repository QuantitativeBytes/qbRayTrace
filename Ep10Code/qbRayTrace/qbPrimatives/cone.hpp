/* ***********************************************************
	cone.hpp
	
	The cone class definition - A class for creating cone 
	primitive shapes.
	
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

#ifndef CONE_H
#define CONE_H

#include "objectbase.hpp"
#include "../gtfm.hpp"

namespace qbRT
{
	class Cone : public ObjectBase
	{
		public:
			// Default constructor.
			Cone();
			
			// Override the destructor.
			virtual ~Cone() override;
			
			// Override the function to test for intersections.
			virtual bool TestIntersection(	const qbRT::Ray &castRay, qbVector<double> &intPoint,
																			qbVector<double> &localNormal, qbVector<double> &localColor) override;			
	};
}

#endif
