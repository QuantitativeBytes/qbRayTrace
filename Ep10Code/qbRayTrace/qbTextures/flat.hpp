/* ***********************************************************
	flat.hpp
	
	The flat class definition - The simplest possible texture
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

#ifndef FLAT_H
#define FLAT_H

#include "texturebase.hpp"

namespace qbRT
{
	namespace Texture
	{
		class Flat : public TextureBase
		{
			public:
				// Constructor / destructor.
				Flat();
				virtual ~Flat() override;
				
				// Function to return the color.
				virtual qbVector<double> GetColor(const qbVector<double> &uvCoords) override;
				
				// Function to set the color.
				void SetColor(const qbVector<double> &inputColor);
				
			private:
				qbVector<double> m_color {4};
				
		};
	}
}

#endif
