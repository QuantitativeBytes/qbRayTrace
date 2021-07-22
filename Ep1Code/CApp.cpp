/* ***********************************************************

	CApp.cpp
	
	The application class implementation.
	
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
	
**********************************************************/

#include "CApp.h"

// The constructor (default)
CApp::CApp()
{
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
}

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}
	
	pWindow = SDL_CreateWindow("qbRayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	
	if (pWindow != NULL)
	{
		// Initialise the renderer.
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		
		// Initialise the qbImage instance.
		m_image.Initialize(1280, 720, pRenderer);
		
		// Create some colour variations.
		for (int x=0; x<1280; ++x)
		{
			for (int y=0; y<720; ++y)
			{
				double red = (static_cast<double>(x)/1280.0) * 255.0;
				double green = (static_cast<double>(y)/720.0) * 255.0;
				m_image.SetPixel(x, y, red, green, 0.0);
			}
		}
		
	}
	else
	{
		return false;
	}
	
	return true;
}

int CApp::OnExecute()
{
	SDL_Event event;
	
	if (OnInit() == false)
	{
		return -1;
	}
	
	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			OnEvent(&event);
		}
		
		OnLoop();
		OnRender();
	}
	
	OnExit();
	return 0;
}

void CApp::OnEvent(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void CApp::OnLoop()
{

}

void CApp::OnRender()
{
	// Set the background colour to white.
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(pRenderer);
	
	// Display the image.
	//m_image.Display();
	
	// Show the result.
	SDL_RenderPresent(pRenderer);
}

void CApp::OnExit()
{
	// Tidy up SDL2 stuff.
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}















