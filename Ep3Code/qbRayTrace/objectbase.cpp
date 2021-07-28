/* ***********************************************************
	objectbase.cpp
	
	The objectbase class implementation - A base class from which
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

// objectbase.cpp

#include "objectbase.hpp"
#include <math.h>

#define EPSILON 1e-21f;

// Default constructor.
qbRT::ObjectBase::ObjectBase()
{

}

// The destructor.
qbRT::ObjectBase::~ObjectBase()
{

}

// Function to test for intersections.
bool qbRT::ObjectBase::TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor)
{
	return false;
}

// Function to test whether two floating-point numbers are close to being equal.
bool qbRT::ObjectBase::CloseEnough(const double f1, const double f2)
{
	return fabs(f1-f2) < EPSILON;
}
