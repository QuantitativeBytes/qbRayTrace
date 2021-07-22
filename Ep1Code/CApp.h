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
