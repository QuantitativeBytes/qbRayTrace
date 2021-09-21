/* ***********************************************************
	lightbase.hpp
	
	The light base class definition - A base class for handling
	lights.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 4 of the series,
	which may be found here:
	https://youtu.be/dUtkihuUvvo
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/
#ifndef LIGHTBASE_H
#define LIGHTBASE_H

#include <memory>
#include "../qbLinAlg/qbVector.h"
#include "../ray.hpp"
#include "../qbPrimatives/objectbase.hpp"

namespace qbRT
{
	class LightBase
	{
		public:
			// Constructor / destructor.
			LightBase();
			virtual ~LightBase();
			
			// Function to compute illumination contribution.
			virtual bool ComputeIllumination(	const qbVector<double> &intPoint, const qbVector<double> &localNormal,
																				const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																				const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																				qbVector<double> &color, double &intensity);
																				
		public:
			qbVector<double>	m_color			{3};
			qbVector<double>	m_location	{3};
			double						m_intensity;
	};
}

#endif
