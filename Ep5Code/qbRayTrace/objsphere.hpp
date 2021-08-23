/* ***********************************************************
	objectsphere.hpp
	
	The objectsphere class definition - A class to implement
	spheres. Inherits from objectbase.hpp
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 2 of the series,
	which may be found here:
	https://youtu.be/8fWZM8hCX5E
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett	
	
***********************************************************/

// objsphere.hpp

#ifndef OBJSPHERE_H
#define OBJSPHERE_H

#include "objectbase.hpp"
#include "gtfm.hpp"

namespace qbRT
{
	class ObjSphere : public ObjectBase
	{
		public:
			/* The default constructor.
				Note that this will define a unit sphere at the origin. */
			ObjSphere();
			
			// Override the destructor.
			virtual ~ObjSphere() override;
			
			// Override the function to test for intersections.
			virtual bool TestIntersection(const qbRT::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor) override;
			
		private:
		
		
	};
}

#endif
