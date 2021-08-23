/* ***********************************************************
	pointlight.cpp
	
	The point light class implementation - A class for handling point
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

#include "pointlight.hpp"

// Default constructor.
qbRT::PointLight::PointLight()
{
	m_color = qbVector<double> {std::vector<double> {1.0, 1.0, 1.0}};
	m_intensity = 1.0;
}

// Destructor.
qbRT::PointLight::~PointLight()
{

}

// Function to compute illumination.
bool qbRT::PointLight::ComputeIllumination(	const qbVector<double> &intPoint, const qbVector<double> &localNormal,
																						const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																						const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																						qbVector<double> &color, double &intensity)
{
	// Construct a vector pointing from the intersection point to the light.
	qbVector<double> lightDir = (m_location - intPoint).Normalized();
	
	// Compute a starting point.
	qbVector<double> startPoint = intPoint;
	
	// Compute the angle between the local normal and the light ray.
	// Note that we assume that localNormal is a unit vector.
	double angle = acos(qbVector<double>::dot(localNormal, lightDir));
	
	// If the normal is pointing away from the light, then we have no illumination.
	if (angle > 1.5708)
	{
		// No illumination.
		color = m_color;
		intensity = 0.0;
		return false;
	}
	else
	{
		// We do have illumination.
		color = m_color;
		intensity = m_intensity * (1.0 - (angle / 1.5708));
		//intensity = 1.0;
		return true;
	}
	
	return true;
}
