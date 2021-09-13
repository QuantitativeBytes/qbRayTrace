/* ***********************************************************
	camera.hpp
	
	The camera class implementation - A class to handle the camera
	and compute camera geometry.
	
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

// camera.cpp

#include "camera.hpp"
#include "ray.hpp"
#include <math.h>

qbRT::Camera::Camera()
{
	// The default constructor.
	m_cameraPosition = qbVector<double>	{std::vector<double> {0.0, -10.0, 0.0}};
	m_cameraLookAt = qbVector<double>		{std::vector<double> {0.0, 0.0, 0.0}};
	m_cameraUp = qbVector<double>				{std::vector<double> {0.0, 0.0, 1.0}};
	m_cameraLength = 1.0;
	m_cameraHorzSize = 1.0;
	m_cameraAspectRatio = 1.0;
}

void qbRT::Camera::SetPosition(const qbVector<double> &newPosition)
{
	m_cameraPosition = newPosition;
}

void qbRT::Camera::SetLookAt(const qbVector<double> &newLookAt)
{
	m_cameraLookAt = newLookAt;
}

void qbRT::Camera::SetUp(const qbVector<double> &upVector)
{
	m_cameraUp = upVector;
}

void qbRT::Camera::SetLength(double newLength)
{
	m_cameraLength = newLength;
}

void qbRT::Camera::SetHorzSize(double newHorzSize)
{
	m_cameraHorzSize = newHorzSize;
}

void qbRT::Camera::SetAspect(double newAspect)
{
	m_cameraAspectRatio = newAspect;
}

// Method to return the position of the camera.
qbVector<double> qbRT::Camera::GetPosition()
{
	return m_cameraPosition;
}

// Method to return the LookAt of the camera.
qbVector<double> qbRT::Camera::GetLookAt()
{
	return m_cameraLookAt;
}

// Method to return the up vector of the camera.
qbVector<double> qbRT::Camera::GetUp()
{
	return m_cameraUp;
}

// Method to return the length of the camera.
double qbRT::Camera::GetLength()
{
	return m_cameraLength;
}

// Method to return the horizontal size.
double qbRT::Camera::GetHorzSize()
{
	return m_cameraHorzSize;
}

// Method to return the camera aspect ratio.
double qbRT::Camera::GetAspect()
{
	return m_cameraAspectRatio;
}

// Method to return the U vector.
qbVector<double> qbRT::Camera::GetU()
{
	return m_projectionScreenU;
}

// Method to return the V vector.
qbVector<double> qbRT::Camera::GetV()
{
	return m_projectionScreenV;
}

// Method to return the projection screen centre.
qbVector<double> qbRT::Camera::GetScreenCentre()
{
	return m_projectionScreenCentre;
}

// Function to compute camera geometry.
void qbRT::Camera::UpdateCameraGeometry()
{
	// First, compute the vector from the camera position to the LookAt position.
	m_alignmentVector = m_cameraLookAt - m_cameraPosition;
	m_alignmentVector.Normalize();
	
	// Second, compute the U and V vectors.
	m_projectionScreenU = qbVector<double>::cross(m_alignmentVector, m_cameraUp);
	m_projectionScreenU.Normalize();
	m_projectionScreenV = qbVector<double>::cross(m_projectionScreenU, m_alignmentVector);
	m_projectionScreenV.Normalize();
	
	// Thirdly, compute the positon of the centre point of the screen.
	m_projectionScreenCentre = m_cameraPosition + (m_cameraLength * m_alignmentVector);
	
	// Modify the U and V vectors to match the size and aspect ratio.
	m_projectionScreenU = m_projectionScreenU * m_cameraHorzSize;
	m_projectionScreenV = m_projectionScreenV * (m_cameraHorzSize / m_cameraAspectRatio);
}

bool qbRT::Camera::GenerateRay(float proScreenX, float proScreenY, qbRT::Ray &cameraRay)
{
	// Compute the location of the screen point in world coordinates.
	qbVector<double> screenWorldPart1 = m_projectionScreenCentre + (m_projectionScreenU * proScreenX);
	qbVector<double> screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);
	
	// Use this point along with the camera position to compute the ray.
	cameraRay.m_point1 = m_cameraPosition;
	cameraRay.m_point2 = screenWorldCoordinate;
	cameraRay.m_lab = screenWorldCoordinate - m_cameraPosition;
	
	return true;
}


















