/* ***********************************************************
	texturebase.hpp
	
	The texturebase class definition - a simple base class for
	handling textures.
	
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
#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include <memory>
#include "../qbLinAlg/qbMatrix.h"
#include "../qbLinAlg/qbVector.h"
#include "../ray.hpp"

namespace qbRT
{
	namespace Texture
	{
		class TextureBase
		{
			public:
				// Constructor / destructor.
				TextureBase();
				virtual ~TextureBase();
				
				// Function to retrun the color at a given point in the (u,v) coordinate system.
				// Note that the color is returned as a 4-dimensional vector (RGBA).
				virtual qbVector<double> GetColor(const qbVector<double> &uvCoords);
				
				// Function to set transform.
				void SetTransform(const qbVector<double> &translation, const double &rotation, const qbVector<double> &scale);
				
				// Function to blend RGBA colors, returning a 3-dimensional (RGB) result.
				static qbVector<double> BlendColors(const std::vector<qbVector<double>> &inputColorList);
				
				// Function to apply the local transform to the given input vector.
				qbVector<double> ApplyTransform(const qbVector<double> &inputVector);
				
			private:
			
			private:
				// Initialise the transform matrix to the identity matrix.
				qbMatrix2<double> m_transformMatrix {3, 3, std::vector<double>{1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0}};
				
		};
	}
}

#endif
