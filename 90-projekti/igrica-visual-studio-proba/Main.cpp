#include <iostream>
#include "IO.h"
#include "Kocka.h"
#include <time.h>
#ifndef LINUX
#include <windows.h>
#endif

const int WAIT_TIME = 1000 / 60;

#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)	// Linux users should quit this line
#else
int main()
#endif
{
	IO mIO;
	Kocka kocka;
	unsigned long mTime = SDL_GetTicks();

	while (!mIO.IsKeyDown (SDLK_ESCAPE))
	{
		mIO.ClearScreen();
		kocka.unos();
		kocka.crtaj();
		mIO.UpdateScreen();

		if (SDL_GetTicks() - mTime > WAIT_TIME) {
			kocka.azuriraj();
			mTime = SDL_GetTicks();
		}
	}

	return 0;
}