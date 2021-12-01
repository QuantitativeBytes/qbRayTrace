/* ***********************************************************
	image.cpp
	
	The image class implementation - A class to implement
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

#include "image.hpp"

// Constructor / destructor.
qbRT::Texture::Image::Image()
{

}

qbRT::Texture::Image::~Image()
{
	if (m_imageLoaded)
	{
		// Make sure that we free the image surface.
		SDL_FreeSurface(m_imageSurface);
		m_imageLoaded = false;
	}
}

qbVector<double> qbRT::Texture::Image::GetColor(const qbVector<double> &uvCoords)
{
	qbVector<double> outputColor {4};
	
	if (!m_imageLoaded)
	{
		/* If no image has been loaded yet,
			set the color to the default purple 
			regardless of the (u,v) position. */
		outputColor = qbVector<double>{std::vector<double>{1.0, 0.0, 1.0, 1.0}};
	}
	else
	{
		// Apply the local transform to the (u,v) coordinates.
		qbVector<double> inputLoc = uvCoords;
		qbVector<double> newLoc = ApplyTransform(inputLoc);		
		double u = newLoc.GetElement(0);
		double v = newLoc.GetElement(1);
		
		// Convert (u,v) to image dimensions (x,y).
		int x = static_cast<int>(round(((u + 1.0) / 2.0) * static_cast<double>(m_xSize)));
		int y = m_ySize - (static_cast<int>(round(((v + 1.0) / 2.0) * static_cast<double>(m_ySize))));
		
		/* Modulo arithmetic to account for possible tiling.
			For example:
			m_xSize = 10;
			x = 5 =>
				((5 % 10) + 10) % 10 = 5
				
			x = 10 =>
				((10 % 10) + 10) % 10 = 0
				
			x = 11 =>
				((11 % 10) + 10) % 10 = 1	
			
			x = -1 =>
				((-1 % 10) + 10) % 10 = 9
			
			x = -5 =>
				((-5 % 10) + 10) % 10 = 5
				
			x = -10 =>
				((-10 % 10) + 10) % 10 = 0
				
			x = -11 =>
				((-11 % 10) + 10) % 10 = 9  */
				
		x = ((x % m_xSize) + m_xSize) % m_xSize;
		y = ((y % m_ySize) + m_ySize) % m_ySize;
		
		// Verify that we are within the image.
		// Probably not necessary, but seems like a good idea just in case.
		if ((x >= 0) && (x < m_xSize) && (y >= 0) && (y < m_ySize))
		{
			// Convert (x,y) to a linear index.
			int pixelIndex = x + (y * (m_pitch / m_bytesPerPixel));
			
			// Get a pointer to the pixel data.
			uint32_t *pixels = (uint32_t *)m_imageSurface->pixels;
			
			// Extract the current pixel value.
			uint32_t currentPixel = pixels[pixelIndex];
			
			// Convert to RGB.
			uint8_t r, g, b, a;
			SDL_GetRGBA(currentPixel, m_imageSurface->format, &r, &g, &b, &a);
			
			// Set the outputColor vector accordingly.
			outputColor.SetElement(0, static_cast<double>(r) / 255.0);
			outputColor.SetElement(1, static_cast<double>(g) / 255.0);
			outputColor.SetElement(2, static_cast<double>(b) / 255.0);
			outputColor.SetElement(3, static_cast<double>(a) / 255.0);
		}
	}
	
	return outputColor;
}

bool qbRT::Texture::Image::LoadImage(std::string fileName)
{
	if (m_imageLoaded)
		SDL_FreeSurface(m_imageSurface);
	
	m_fileName = fileName;
	m_imageSurface = SDL_LoadBMP(fileName.c_str());
	
	if (!m_imageSurface)
	{
		std::cout << "Failed to load image. " << SDL_GetError() << "." << std::endl;
		m_imageLoaded = false;
		return false;
	}

	// Extract useful information.
	m_xSize = m_imageSurface->w;
	m_ySize = m_imageSurface->h;
	m_pitch = m_imageSurface->pitch;
	m_pixelFormat = m_imageSurface->format;
	m_bytesPerPixel = m_pixelFormat->BytesPerPixel;
	m_rMask = m_pixelFormat->Rmask;
	m_gMask = m_pixelFormat->Gmask;
	m_bMask = m_pixelFormat->Bmask;
	m_aMask = m_pixelFormat->Amask;
	
	std::cout << "Loaded " << m_imageSurface->w << " by " << m_imageSurface->h << "." << std::endl;
	std::cout << "Bytes per pixel = " << +m_bytesPerPixel << std::endl;
	std::cout << "Pitch = " << m_pitch << std::endl;

	m_imageLoaded = true;
	return true;
}


