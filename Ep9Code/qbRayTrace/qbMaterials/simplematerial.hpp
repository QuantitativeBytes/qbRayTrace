/* ***********************************************************
	simplematerial.hpp
	
	The SimpleMaterial class definition - A class for handling 
	materials.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 7 of the series,
	which may be found here:
	https://youtu.be/F5vIgpRF_Qo
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

// simplematerial.hpp

#ifndef SIMPLEMATERIAL_H
#define SIMPLEMATERIAL_H

#include "materialbase.hpp"

namespace qbRT
{
	class SimpleMaterial : public MaterialBase
	{
		public:
			// Constructor / destructor.
			SimpleMaterial();
			virtual ~SimpleMaterial() override;
			
			// Function to return the color.
			virtual qbVector<double> ComputeColor(	const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																							const std::vector<std::shared_ptr<qbRT::LightBase>> &lightList,
																							const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																							const qbVector<double> &intPoint, const qbVector<double> &localNormal,
																							const qbRT::Ray &cameraRay) override;
																							
			// Function to compute specular highlights.
			qbVector<double> ComputeSpecular(	const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																				const std::vector<std::shared_ptr<qbRT::LightBase>> &lightList,
																				const qbVector<double> &intPoint, const qbVector<double> &localNormal,
																				const qbRT::Ray &cameraRay);
																				
		public:
			qbVector<double> m_baseColor {std::vector<double> {1.0, 0.0, 1.0}};
			double m_reflectivity = 0.0;
			double m_shininess = 0.0;
	};
}

#endif
