/* ***********************************************************
	checker.hpp
	
	The checker class definition - The 'classic' ray tracer
	checkerboard pattent.
	
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

#ifndef CHECKER_H
#define CHECKER_H

#include "texturebase.hpp"

namespace qbRT
{
	namespace Texture
	{
		class Checker : public TextureBase
		{
			public:
				// Constructor / destructor.
				Checker();
				virtual ~Checker() override;
			
				// Function to return the color.
				virtual qbVector<double> GetColor(const qbVector<double> &uvCoords) override;
			
				// Function to set the colors.
				void SetColor(const qbVector<double> &inputColor1, const qbVector<double> &inputColor2);
			
		private:
			qbVector<double> m_color1 {4};
			qbVector<double> m_color2 {4};
			
		};
	}
}

#endif
