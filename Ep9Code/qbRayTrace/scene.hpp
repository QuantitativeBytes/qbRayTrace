
/* ***********************************************************
	scene.hpp
	
	The scene class definition - A class to handle information
	about the scene and rendering to an image.
	
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

// scene.hpp

#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "qbImage.hpp"
#include "camera.hpp"
#include "./qbPrimatives/objsphere.hpp"
#include "./qbPrimatives/objplane.hpp"
#include "./qbPrimatives/cylinder.hpp"
#include "./qbPrimatives/cone.hpp"
#include "./qbLights/pointlight.hpp"

namespace qbRT
{
	class Scene
	{
		public:
			// The default constructor.
			Scene();
			
			// Function to perform the rendering.
			bool Render(qbImage &outputImage);
			
			// Function to cast a ray into the scene.
			bool CastRay(	qbRT::Ray &castRay, std::shared_ptr<qbRT::ObjectBase> &closestObject,
										qbVector<double> &closestIntPoint, qbVector<double> &closestLocalNormal,
										qbVector<double> &closestLocalColor);
			
		// Private functions.
		private:
		
		// Private members.
		private:
			// The camera that we will use.
			qbRT::Camera m_camera;
			
			// The list of objects in the scene.
			std::vector<std::shared_ptr<qbRT::ObjectBase>> m_objectList;
	
			// The list of lights in the scene.
			std::vector<std::shared_ptr<qbRT::LightBase>> m_lightList;
	};
}

#endif
