/* ***********************************************************
	scene.hpp
	
	The scene class definition - A class to handle information
	about the scene and rendering to an image.
	
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

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL2/SDL.h>
#include "qbImage.hpp"

namespace qbRT
{
	class Scene
	{
		public:
			// The default constructor.
			Scene();		
			
			// Function to perform the rendering.
			bool Render(qbImage &outputImage);
			
		// Private functions.
		private:
		
		// Private members.
		private:
			
			
	};
}

#endif
