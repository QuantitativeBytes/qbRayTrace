/* ***********************************************************
	lightbase.cpp
	
	The light base class implementation - A base class for handling
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

#include "lightbase.hpp"

// Constructor.
qbRT::LightBase::LightBase()
{

}

// Destructor.
qbRT::LightBase::~LightBase()
{

}

// Function to compute illumination.
bool qbRT::LightBase::ComputeIllumination(	const qbVector<double> &intPoint, const qbVector<double> &localNormal,
																						const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																						const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																						qbVector<double> &color, double &intensity)
{
	return false;
}
