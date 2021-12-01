/* ***********************************************************
	objectbase.hpp
	
	The objectbase class definition - A base class from which
	all other object classes will inherit.
	
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

// objectbase.hpp

#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include <memory>
#include "../qbLinAlg/qbVector.h"
#include "../ray.hpp"
#include "../gtfm.hpp"

namespace qbRT
{
	/* Forward-declare the material base class. This will be
		overriden later. */
	class MaterialBase;

	class ObjectBase
	{
		public:
			// Constructor and destructor.
			ObjectBase();
			virtual ~ObjectBase();
			
			// Function to test for intersections.
			virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor);
			
			// Function to set the transform matrix.
			void SetTransformMatrix(const qbRT::GTform &transformMatrix);
			
			// Function to test whether two floating-point numbers are close to being equal.
			bool CloseEnough(const double f1, const double f2);
			
			// Function to assign a material.
			bool AssignMaterial(const std::shared_ptr<qbRT::MaterialBase> &objectMaterial);
			
		// Public member variables.
		public:
			// The base colour of the object.
			qbVector<double> m_baseColor {3};
			
			// The geometric transform applied to the object.
			qbRT::GTform m_transformMatrix;
			
			// A reference to the material assigned to this object.
			std::shared_ptr<qbRT::MaterialBase> m_pMaterial;
			
			// A flag to indicate whether this object has a material or not.
			bool m_hasMaterial = false;
			
			// Store the (u,v) coordinates from a detected intersection.
			qbVector<double> m_uvCoords {2};
	};
}

#endif
