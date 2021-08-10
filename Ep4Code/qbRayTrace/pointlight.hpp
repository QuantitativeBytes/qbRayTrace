/* ***********************************************************
	pointlight.hpp
	
	The pointlight class definition - A class to implement
	a very simple point light source.
	
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

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "lightbase.hpp"

namespace qbRT
{
	class PointLight : public LightBase
	{
		public:
			// The default constructor.
			PointLight();
			
			// Override the default destructor.
			virtual ~PointLight() override;
			
			// Function to compute illumination.
			virtual bool ComputeIllumination(	const qbVector<double> &intPoint, const qbVector<double> &localNormal,
																				const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																				const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																				qbVector<double> &color, double &intensity) override;
	};
}

#endif
