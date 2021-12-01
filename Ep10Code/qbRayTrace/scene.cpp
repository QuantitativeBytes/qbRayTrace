/* ***********************************************************
	scene.cpp
	
	The scene class implementation - A class to handle information
	about the scene and rendering to an image.
	
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

// scene.cpp

#include "scene.hpp"
#include "./qbMaterials/simplematerial.hpp"
#include "./qbMaterials/simplerefractive.hpp"
#include "./qbTextures/checker.hpp"
#include "./qbTextures/image.hpp"

// The constructor.
qbRT::Scene::Scene()
{
	// **************************************************************************************
	// Configure the camera.
	// **************************************************************************************	
	m_camera.SetPosition(	qbVector<double>{std::vector<double> {2.0, -5.0, 0.25}} );
	m_camera.SetLookAt	( qbVector<double>{std::vector<double> {0.0, 0.0, 0.0}} );
	m_camera.SetUp			( qbVector<double>{std::vector<double> {0.0, 0.0, 1.0}} );
	m_camera.SetHorzSize(1.0);
	m_camera.SetAspect(16.0 / 9.0);
	m_camera.UpdateCameraGeometry();
	
	// **************************************************************************************
	// Setup ambient lightling.
	// **************************************************************************************		
	qbRT::MaterialBase::m_ambientColor = std::vector<double>{1.0, 1.0, 1.0};
	qbRT::MaterialBase::m_ambientIntensity = 0.2;

	// **************************************************************************************
	// Create some textures.
	// **************************************************************************************	
	auto floorTexture = std::make_shared<qbRT::Texture::Checker> (qbRT::Texture::Checker());
	auto imageTexture = std::make_shared<qbRT::Texture::Image> (qbRT::Texture::Image());
	
	// **************************************************************************************	
	// Setup the textures.
	// **************************************************************************************	
	floorTexture -> SetTransform(	qbVector<double>{std::vector<double>{0.0, 0.0}},
																0.0,
																qbVector<double>{std::vector<double>{16.0, 16.0}} );
																
	imageTexture -> LoadImage("testImage.bmp");
	imageTexture -> SetTransform(	qbVector<double>{std::vector<double>{0.0, 0.0}},
																0.0,
																qbVector<double>{std::vector<double>{1.0, 1.0}}	);

	// **************************************************************************************
	// Create some materials.
	// **************************************************************************************
	auto floorMaterial = std::make_shared<qbRT::SimpleMaterial> (qbRT::SimpleMaterial());
	auto imageMaterial = std::make_shared<qbRT::SimpleMaterial> (qbRT::SimpleMaterial());
	auto sphereMaterial = std::make_shared<qbRT::SimpleMaterial> (qbRT::SimpleMaterial());
	auto sphereMaterial2 = std::make_shared<qbRT::SimpleMaterial> (qbRT::SimpleMaterial());
	auto sphereMaterial3 = std::make_shared<qbRT::SimpleMaterial> (qbRT::SimpleMaterial());
	auto glassMaterial = std::make_shared<qbRT::SimpleRefractive> (qbRT::SimpleRefractive());
	
	// **************************************************************************************	
	// Setup the materials.
	// **************************************************************************************
	floorMaterial -> m_baseColor = qbVector<double>{std::vector<double>{1.0, 1.0, 1.0}};
	floorMaterial -> m_reflectivity = 0.25;
	floorMaterial -> m_shininess = 0.0;
	floorMaterial -> AssignTexture(floorTexture);
	
	imageMaterial -> m_baseColor = qbVector<double>{std::vector<double>{1.0, 0.125, 0.125}};
	imageMaterial -> m_reflectivity = 0.0;
	imageMaterial -> m_shininess = 0.0;
	imageMaterial -> AssignTexture(imageTexture);
	
	sphereMaterial -> m_baseColor = qbVector<double>{std::vector<double>{1.0, 0.2, 0.2}};
	sphereMaterial -> m_reflectivity = 0.8;
	sphereMaterial -> m_shininess = 32.0;
	
	sphereMaterial2 -> m_baseColor = qbVector<double>{std::vector<double>{0.2, 1.0, 0.2}};
	sphereMaterial2 -> m_reflectivity = 0.8;
	sphereMaterial2 -> m_shininess = 32.0;
	
	sphereMaterial3 -> m_baseColor = qbVector<double>{std::vector<double>{0.2, 0.2, 1.0}};
	sphereMaterial3 -> m_reflectivity = 0.8;
	sphereMaterial3 -> m_shininess = 32.0;	
	
	glassMaterial -> m_baseColor = qbVector<double>{std::vector<double>{0.7, 0.7, 0.2}};
	glassMaterial -> m_reflectivity = 0.25;
	glassMaterial -> m_shininess = 32.0;
	glassMaterial -> m_translucency = 0.75;
	glassMaterial -> m_ior = 1.333;	
	
	// **************************************************************************************	
	// Create and setup objects.
	// **************************************************************************************
	auto floor = std::make_shared<qbRT::ObjPlane> (qbRT::ObjPlane());
	floor -> SetTransformMatrix(qbRT::GTform {	qbVector<double>{std::vector<double>{0.0, 0.0, 1.0}},
																							qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
																							qbVector<double>{std::vector<double>{16.0, 16.0, 1.0}}});
	floor -> AssignMaterial(floorMaterial);

	// **************************************************************************************
	auto imagePlane = std::make_shared<qbRT::ObjPlane> (qbRT::ObjPlane());
	imagePlane -> SetTransformMatrix(qbRT::GTform {	qbVector<double>{std::vector<double>{0.0, 5.0, -0.75}},
																									qbVector<double>{std::vector<double>{-M_PI/2.0, 0.0, 0.0}},
																									qbVector<double>{std::vector<double>{1.75, 1.75, 1.0}}}	);
	imagePlane -> AssignMaterial(imageMaterial);

	// **************************************************************************************	
	auto sphere = std::make_shared<qbRT::ObjSphere> (qbRT::ObjSphere());
	sphere -> SetTransformMatrix(qbRT::GTform	{	qbVector<double>{std::vector<double>{-2.0, -2.0, 0.25}},
																							qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
																							qbVector<double>{std::vector<double>{0.75, 0.75, 0.75}}}	);
	sphere -> AssignMaterial(sphereMaterial);
	
	// **************************************************************************************	
	auto sphere2 = std::make_shared<qbRT::ObjSphere> (qbRT::ObjSphere());
	sphere2 -> SetTransformMatrix(qbRT::GTform	{	qbVector<double>{std::vector<double>{-2.0, -0.5, 0.25}},
																							qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
																							qbVector<double>{std::vector<double>{0.75, 0.75, 0.75}}}	);
	sphere2 -> AssignMaterial(sphereMaterial2);
	
	// **************************************************************************************	
	auto sphere3 = std::make_shared<qbRT::ObjSphere> (qbRT::ObjSphere());
	sphere3 -> SetTransformMatrix(qbRT::GTform	{	qbVector<double>{std::vector<double>{-2.0, -1.25, -1.0}},
																							qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
																							qbVector<double>{std::vector<double>{0.75, 0.75, 0.75}}}	);
	sphere3 -> AssignMaterial(sphereMaterial3);		
	
	// **************************************************************************************	
	auto sphere4 = std::make_shared<qbRT::ObjSphere> (qbRT::ObjSphere());
	sphere4 -> SetTransformMatrix(qbRT::GTform	{	qbVector<double>{std::vector<double>{2.0, -1.25, 0.25}},
																							qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
																							qbVector<double>{std::vector<double>{0.75, 0.75, 0.75}}}	);
	sphere4 -> AssignMaterial(glassMaterial);		

	// **************************************************************************************
	// Put the objects into the scene.	
	// **************************************************************************************
	m_objectList.push_back(floor);
	m_objectList.push_back(imagePlane);
	m_objectList.push_back(sphere);
	m_objectList.push_back(sphere2);	
	m_objectList.push_back(sphere3);	
	m_objectList.push_back(sphere4);
	
	// **************************************************************************************	
	// Construct and setup the lights.
	// **************************************************************************************	
	m_lightList.push_back(std::make_shared<qbRT::PointLight> (qbRT::PointLight()));
	m_lightList.at(0) -> m_location = qbVector<double> {std::vector<double> {3.0, -10.0, -5.0}};
	m_lightList.at(0) -> m_color = qbVector<double> {std::vector<double> {1.0, 1.0, 1.0}};
	m_lightList.at(0) -> m_intensity = 4.0;
	
	m_lightList.push_back(std::make_shared<qbRT::PointLight> (qbRT::PointLight()));
	m_lightList.at(1) -> m_location = qbVector<double> {std::vector<double> {0.0, -10.0, -5.0}};
	m_lightList.at(1) -> m_color = qbVector<double> {std::vector<double> {1.0, 1.0, 1.0}};
	m_lightList.at(1) -> m_intensity = 2.0;

}

// Function to perform the rendering.
bool qbRT::Scene::Render(qbImage &outputImage)
{
	// Get the dimensions of the output image.
	int xSize = outputImage.GetXSize();
	int ySize = outputImage.GetYSize();
	
	// Loop over each pixel in our image.
	qbRT::Ray cameraRay;
	qbVector<double> intPoint			(3);
	qbVector<double> localNormal	(3);
	qbVector<double> localColor		(3);
	double xFact = 1.0 / (static_cast<double>(xSize) / 2.0);
	double yFact = 1.0 / (static_cast<double>(ySize) / 2.0);
	double minDist = 1e6;
	double maxDist = 0.0;
	for (int y=0; y<ySize; ++y)
	{
		// Display progress.
		std::cout << "Processing line " << y << " of " << ySize << "." << " \r";
		std::cout.flush();
		
		for (int x=0; x<xSize; ++x)
		{
			// Normalize the x and y coordinates.
			double normX = (static_cast<double>(x) * xFact) - 1.0;
			double normY = (static_cast<double>(y) * yFact) - 1.0;
			
			// Generate the ray for this pixel.
			m_camera.GenerateRay(normX, normY, cameraRay);
			
			// Test for intersections with all objects in the scene.
			std::shared_ptr<qbRT::ObjectBase> closestObject;
			qbVector<double> closestIntPoint		{3};
			qbVector<double> closestLocalNormal	{3};
			qbVector<double> closestLocalColor	{3};
			bool intersectionFound = CastRay(cameraRay, closestObject, closestIntPoint, closestLocalNormal, closestLocalColor);
			
			/* Compute the illumination for the closest object, assuming that there
				was a valid intersection. */
			if (intersectionFound)
			{
				// Check if the object has a material.
				if (closestObject -> m_hasMaterial)
				{
					// Use the material to compute the color.
					qbRT::MaterialBase::m_reflectionRayCount = 0;
					qbVector<double> color = closestObject -> m_pMaterial -> ComputeColor(	m_objectList, m_lightList,
																																									closestObject, closestIntPoint,
																																									closestLocalNormal, cameraRay);
					outputImage.SetPixel(x, y, color.GetElement(0), color.GetElement(1), color.GetElement(2));
				}
				else
				{
					// Use the basic method to compute the color.
					qbVector<double> matColor = qbRT::MaterialBase::ComputeDiffuseColor(m_objectList, m_lightList,
																																							closestObject, closestIntPoint,
																																							closestLocalNormal, closestObject->m_baseColor);
					outputImage.SetPixel(x, y, matColor.GetElement(0), matColor.GetElement(1), matColor.GetElement(2));
				}
			}
		}
	}
	
	std::cout << std::endl;
	return true;
}

// Function to cast a ray into the scene.
bool qbRT::Scene::CastRay(	qbRT::Ray &castRay, std::shared_ptr<qbRT::ObjectBase> &closestObject,
														qbVector<double> &closestIntPoint, qbVector<double> &closestLocalNormal,
														qbVector<double> &closestLocalColor)
{
	qbVector<double> intPoint			{3};
	qbVector<double> localNormal	{3};
	qbVector<double> localColor		{3};
	double minDist = 1e6;
	bool intersectionFound = false;
	for (auto currentObject : m_objectList)
	{
		bool validInt = currentObject -> TestIntersection(castRay, intPoint, localNormal, localColor);
		
		// If we have a valid intersection.
		if (validInt)
		{
			// Set the flag to indicate that we found an intersection.
			intersectionFound = true;
					
			// Compute the distance between the camera and the point of intersection.
			double dist = (intPoint - castRay.m_point1).norm();
					
			/* If this object is closer to the camera than any one that we have
				seen before, then store a reference to it. */
			if (dist < minDist)
			{
				minDist = dist;
				closestObject = currentObject;
				closestIntPoint = intPoint;
				closestLocalNormal = localNormal;
				closestLocalColor = localColor;
			}
		}
	}
	
	return intersectionFound;
}












