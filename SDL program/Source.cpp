#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace SDLproject;

int WinMain(int argc, char * argv[])
{
	srand(time(NULL));
	
	Screen screen;

	if (!screen.init())
	{
		cout << "Error initialising SDL" << endl;
	}

	Swarm swarm;

	while (true)
	{
		int elapsed = SDL_GetTicks();

		// screen.clear();
		swarm.update(elapsed);
		
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0007)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0008)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0009)) * 128);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i]; 

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x,y,red,green,blue);
		}

		screen.boxBlur();

		/*for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
		{ 
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
			{
				screen.setPixel(x,y,red,green,blue);
			}
		}*/

		// draw screen
		screen.update();	

		// check for messages / events
		if (!screen.processEvents())
		{
			break;
		}
	}

	screen.close();
	return 0;
}