/* ***********************************************************
	scene.hpp
	
	The scene class implementation - A class to handle information
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

#include "Scene.hpp"

// The constructor.
qbRT::Scene::Scene()
{

}

// Function to perform the renderering.
bool qbRT::Scene::Render(qbImage &outputImage)
{
	// Get the dimensions of the output image.
	int xSize = outputImage.GetXSize();
	int ySize = outputImage.GetYSize();
	
		// Create some colour variations.
		for (int x=0; x<xSize; ++x)
		{
			for (int y=0; y<ySize; ++y)
			{
				double red = (static_cast<double>(x)/static_cast<double>(xSize)) * 255.0;
				double green = (static_cast<double>(y)/static_cast<double>(ySize)) * 255.0;
				outputImage.SetPixel(x, y, red, green, 0.0);
			}
		}	
	
	return true;
}
