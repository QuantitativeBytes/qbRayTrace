/* ***********************************************************
	objectplane.cpp
	
	The ObjPlane class implementation - A class derived from
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

// objplane.cpp

#include "objplane.hpp"
#include <cmath>

// The default constructor.
qbRT::ObjPlane::ObjPlane()
{

}

// The destructor.
qbRT::ObjPlane::~ObjPlane()
{

}

// The function to test for intersections.
bool qbRT::ObjPlane::TestIntersection(	const qbRT::Ray &castRay, qbVector<double> &intPoint,
																				qbVector<double> &localNormal, qbVector<double> &localColor)
{
	// Copy the ray and apply the backwards transform.
	qbRT::Ray bckRay = m_transformMatrix.Apply(castRay, qbRT::BCKTFORM);
	
	// Copy the m_lab vector from bckRay and normalize it.
	qbVector<double> k = bckRay.m_lab;
	k.Normalize();
	
	/* Check if there is an intersection, ie. if the castRay is not parallel
		to the plane. */
	if (!CloseEnough(k.GetElement(2), 0.0))
	{
		// There is an intersection.
		double t = bckRay.m_point1.GetElement(2) / -k.GetElement(2);
		
		/* If t is negative, then the intersection point must be behind
			the camera and we can ignore it. */
		if (t > 0.0)
		{
			// Compute the values for u and v.
			double u = bckRay.m_point1.GetElement(0) + (k.GetElement(0) * t);
			double v = bckRay.m_point1.GetElement(1) + (k.GetElement(1) * t);
			
			/* If the magnitude of both u and v is less than or equal to one
				then we must be in the plane. */
			if ((abs(u) < 1.0) && (abs(v) < 1.0))
			{
				// Compute the point of intersection.
				qbVector<double> poi = bckRay.m_point1 + t * k;
				
				// Transform the intersection point back into world coordinates.
				intPoint = m_transformMatrix.Apply(poi, qbRT::FWDTFORM);
				
				// Compute the local normal.
				qbVector<double> localOrigin {std::vector<double> {0.0, 0.0, 0.0}};
				qbVector<double> normalVector {std::vector<double> {0.0, 0.0, -1.0}};
				qbVector<double> globalOrigin = m_transformMatrix.Apply(localOrigin, qbRT::FWDTFORM);
				localNormal = m_transformMatrix.Apply(normalVector, qbRT::FWDTFORM) - globalOrigin;
				localNormal.Normalize();
				
				// Return the base color.
				localColor = m_baseColor;
				
				// Store the (u,v) coordinates for possible later use.
				m_uvCoords.SetElement(0, u);
				m_uvCoords.SetElement(1, v);
				
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	return false;
}

















