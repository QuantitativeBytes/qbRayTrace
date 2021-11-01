/* ***********************************************************
	flat.cpp
	
	The flat class implementation - The simplest possible texture
	definition consisting of just a single color.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 9 of the series,
	which may be found here:
	https://youtu.be/d35gDi98gEY
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

#include "flat.hpp"

// Constructor / destructor.
qbRT::Texture::Flat::Flat()
{
	m_color = qbVector<double>{std::vector<double> {1.0, 0.0, 0.0, 1.0}};
}

qbRT::Texture::Flat::~Flat()
{

}

// Function to return the color.
qbVector<double> qbRT::Texture::Flat::GetColor(const qbVector<double> &uvCoords)
{
	return m_color;
}

// Function to set the color.
void qbRT::Texture::Flat::SetColor(const qbVector<double> &inputColor)
{
	m_color = inputColor;
}
