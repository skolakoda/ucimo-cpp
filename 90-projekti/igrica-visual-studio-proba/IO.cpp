#include "IO.h"

Uint32 colors [COLOR_MAX] = {
	0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff, 0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff
};

IO::IO() 
{
	Uint32 videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;
	screen = SDL_SetVideoMode(sirinaEkrana, visinaEkrana, 0, videoflags);
	atexit(SDL_Quit);
}

void IO::ClearScreen() 
{
	boxColor(screen, 0, 0, screen->w - 1, screen->h - 1, colors[BLACK]);
}

void IO::DrawRectangle (int pX1, int pY1, int pX2, int pY2, enum color pC)
{
	boxColor(screen, pX1, pY1, pX2, pY2-1, colors[pC]);
}

void IO::UpdateScreen()
{
	SDL_Flip(screen);
}

int IO::Pollkey()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type) {
			case SDL_KEYDOWN:
				return event.key.keysym.sym;
			case SDL_QUIT:
				exit(3);
		}
	}
	return -1;
}

int IO::IsKeyDown (int pKey)
{
	Uint8* keytable;
	int numkeys;
	SDL_PumpEvents();
	keytable = SDL_GetKeyState(&numkeys);
	return keytable[pKey];
}
