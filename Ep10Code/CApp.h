
/* ***********************************************************
	CApp.h
	
	The application class definition.
	
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

#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include "./qbRayTrace/qbImage.hpp"
#include "./qbRayTrace/scene.hpp"
#include "./qbRayTrace/camera.hpp"
#include "./qbRayTrace/qbTextures/flat.hpp"
#include "./qbRayTrace/qbTextures/checker.hpp"
#include "./qbRayTrace/qbTextures/image.hpp"

class CApp
{
	public:
		CApp();
		
		int OnExecute();
		bool OnInit();
		void OnEvent(SDL_Event *event);
		void OnLoop();
		void OnRender();
		void OnExit();
		
	private:
		void PrintVector(const qbVector<double> &inputVector);
		
	private:
		// An instance of the qbImage class to store the image.
		qbImage m_image;
		
		// An instance of the scene class.
		qbRT::Scene m_scene;
		
		// SDL2 stuff.
		bool isRunning;
		SDL_Window *pWindow;
		SDL_Renderer *pRenderer;
		
};

#endif
