/* ***********************************************************

	CApp.h
	
	The application class definition.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 1 of the series,
	which may be found here:
	https://youtu.be/JN5yUrJPThI
	
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
		// An instance of qbImage to store the image.
		qbImage m_image;
	
		// SDL2 stuff.
		bool isRunning;
		SDL_Window *pWindow;
		SDL_Renderer *pRenderer;

};

#endif
