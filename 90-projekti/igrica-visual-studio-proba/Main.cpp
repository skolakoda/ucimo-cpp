#include <iostream>
#include "IO.h"
#include "Kocka.h"
#include <time.h>
#ifndef LINUX
#include <windows.h>
#endif

const int WAIT_TIME = 1000 / 60;

#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
	IO mIO;
	Kocka kocka;
	unsigned long time = SDL_GetTicks();

	while (!mIO.IsKeyDown (SDLK_ESCAPE))
	{
		mIO.ClearScreen();
		kocka.unos();
		kocka.crtaj();
		mIO.UpdateScreen();

		if (SDL_GetTicks() - time > WAIT_TIME) {
			kocka.azuriraj();
			time = SDL_GetTicks();
		}
	}
	return 0;
}