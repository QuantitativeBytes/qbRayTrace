/* ***********************************************************
	qbImage.hpp
	
	The qbImage class definition - A simple class for 2D
	image handling.
	
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

#ifndef QBIMAGE_H
#define QBIMAGE_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class qbImage
{
	public:
		// The constructor.
		qbImage();
	
		// The destructor.
		~qbImage();
	
		// Function to initialise.
		void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);
		
		// Function to set the colour of a pixel.
		void SetPixel(const int x, const int y, const double red, const double green, const double blue);
		
		// Function to return the image for display.
		void Display();
		
		// Functions to return the dimensions of the image.
		int GetXSize();
		int GetYSize();
	
	private:
		Uint32 ConvertColor(const double red, const double green, const double blue);
		void InitTexture();
		void ComputeMaxValues();
		
	private:
		// Arrays to store image data.
		std::vector<std::vector<double>> m_rChannel;
		std::vector<std::vector<double>> m_gChannel;
		std::vector<std::vector<double>> m_bChannel;
		
		// Store the dimensions of the image.
		int m_xSize, m_ySize;
		
		// Store the maximum values.
		double m_maxRed, m_maxGreen, m_maxBlue, m_overallMax;
		
		// SDL2 stuff.
		SDL_Renderer *m_pRenderer;
		SDL_Texture *m_pTexture;

};

#endif

















