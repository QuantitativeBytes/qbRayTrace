/* ***********************************************************
	ray.hpp
	
	The ray class definition - A class to handle rays that can
	be cast around the scene.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 2 of the series,
	which may be found here:
	https://youtu.be/KBK6g6RFgdA
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

// ray.hpp

#ifndef RAY_H
#define RAY_H

#include "./qbLinAlg/qbVector.h"

namespace qbRT
{
	class Ray
	{
		public:
			Ray();
			Ray(const qbVector<double> &point1, const qbVector<double> &point2);
			
			qbVector<double> GetPoint1() const;
			qbVector<double> GetPoint2() const;
			
		public:
			qbVector<double> m_point1	{3};
			qbVector<double> m_point2 {3};
			qbVector<double> m_lab		{3};
			
	};
}

#endif
