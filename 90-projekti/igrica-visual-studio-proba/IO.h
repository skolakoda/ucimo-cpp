#pragma once

#ifndef LINUX
#include "SDL/include/SDL.h"							
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include <SDL/SDL.h>									
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"	
#endif

#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

const int sirinaEkrana = 800;
const int visinaEkrana = 600;
enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

class IO
{
	SDL_Surface *screen;
	Uint32 colors[COLOR_MAX] = {0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff, 0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff};
	public:
		IO						();
		void DrawRectangle		(int pX1, int pY1, int pX2, int pY2, enum color pC);
		void ClearScreen		();
		int Pollkey				();
		int IsKeyDown			(int pKey);
		void UpdateScreen		();
};
