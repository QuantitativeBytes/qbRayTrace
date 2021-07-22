/* ***********************************************************
	camera.hpp
	
	The camera class definition - A class to handle the camera
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

#ifndef CAMERA_H
#define CAMERA_H

#include "./qbLinAlg/qbVector.h"
#include "ray.hpp"

namespace qbRT
{
	class Camera
	{

	public:
		Camera();
	
		void SetPosition	(const qbVector<double> &newPosition);
		void SetLookAt		(const qbVector<double> &newLookAt);
		void SetUp				(const qbVector<double> &upVector);
		void SetLength		(double newLength);
		void SetHorzSize	(double newSize);
		void SetAspect		(double newAspectRatio);
	
		qbVector<double> 	GetPosition();
		qbVector<double> 	GetLookAt();
		qbVector<double>	GetUp();
		qbVector<double>	GetU();
		qbVector<double>	GetV();
		qbVector<double>	GetScreenCentre();
		double 						GetLength();
		double 						GetHorzSize();
		double						GetAspect();
	
		Ray GenerateRay(float proScreenX, float proScreenY);
	
		void UpdateCameraGeometry();
	
	private:
		qbVector<double> m_cameraPosition {3};
		qbVector<double> m_cameraLookAt		{3};
		qbVector<double> m_cameraUp				{3};
		double m_cameraLength;
		double m_cameraHorzSize;
		double m_cameraAspectRatio;
		
		qbVector<double> m_alignmentVector				{3};
		qbVector<double> m_projectionScreenU			{3};
		qbVector<double> m_projectionScreenV			{3};
		qbVector<double> m_projectionScreenCentre	{3};
	};
}

#endif // CAMERA_H
