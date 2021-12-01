/* ***********************************************************
	image.hpp
	
	The image class definition - A class to implement
	image based textures.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett	
	
***********************************************************/

#ifndef IMAGE_H
#define IMAGE_H

#include "texturebase.hpp"
#include <SDL2/SDL.h>

namespace qbRT
{
	namespace Texture
	{
		class Image : public TextureBase
		{
			public:
				Image();
				virtual ~Image() override;
				
				// Function to return the color.
				virtual qbVector<double> GetColor(const qbVector<double> &uvCoords) override;
			
				// Function to load the image to be used.
				bool LoadImage(std::string fileName);
				
			private:
				std::string m_fileName;
				SDL_Surface *m_imageSurface;
				SDL_PixelFormat *m_pixelFormat;
				bool m_imageLoaded = false;
				int m_xSize, m_ySize, m_pitch;
				uint8_t m_bytesPerPixel;
				uint32_t m_rMask, m_gMask, m_bMask, m_aMask;				
							
		};
	}
}

#endif
