/* ***********************************************************
	ray.hpp
	
	The ray class implementation - A class to handle rays that can
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

#include "ray.hpp"

qbRT::Ray::Ray(const qbVector<double> &point1, const qbVector<double> &point2)
{
	m_point1 = point1;
	m_point2 = point2;
	m_lab = m_point2 - m_point1;
}

qbVector<double> qbRT::Ray::GetPoint1() const
{
	return m_point1;
}

qbVector<double> qbRT::Ray::GetPoint2() const
{
	return m_point2;
}
