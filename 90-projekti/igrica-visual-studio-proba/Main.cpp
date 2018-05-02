#include <iostream>
#include "IO.h"
#include <time.h>
#ifndef LINUX
#include <windows.h>
#endif

const int WAIT_TIME = 1000 / 60;
enum Smer { LEVO, DESNO, GORE, DOLE};
IO mIO;

class Kocka {
public:
	int x = 0;
	int y = 0;
	int sirina = 200;
	int visina = 200;
	Smer smer = DESNO;

	void primiUnos() {
		switch (mIO.Pollkey())
		{
			case (SDLK_RIGHT):
			{
				smer = DESNO;
				break;
			}
			case (SDLK_LEFT):
			{
				smer = LEVO;
				break;
			}
			case (SDLK_DOWN):
			{
				smer = DOLE;
				break;
			}
			case (SDLK_UP):
			{
				smer = GORE;
				break;
			}
		}
	}

	void azuriraj() {
		switch (smer)
		{
			case (LEVO):
			{
				x--;
				break;
			}
			case (DESNO):
			{
				x++;
				break;
			}
			case (GORE):
			{
				y--;
				break;
			}
			case (DOLE):
			{
				y++;
				break;
			}
		}
	}

	void crtaj() {
		mIO.DrawRectangle(x, y, x + sirina, y + visina, BLUE);
	}
};

#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)	// Linux users should quit this line
#else
int main()
#endif
{
	Kocka kocka;
	unsigned long mTime = SDL_GetTicks();

	while (!mIO.IsKeyDown (SDLK_ESCAPE))
	{
		mIO.ClearScreen();
		kocka.primiUnos();
		kocka.crtaj();
		mIO.UpdateScreen();

		if (SDL_GetTicks() - mTime > WAIT_TIME) {
			kocka.azuriraj();
			mTime = SDL_GetTicks();
		}
	}

	return 0;
}