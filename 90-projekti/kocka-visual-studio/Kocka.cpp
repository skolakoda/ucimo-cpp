#include "Kocka.h"

void Kocka::unos() {
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

void Kocka::azuriraj() {
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

void Kocka::crtaj() {
	 mIO.DrawRectangle(x, y, x + sirina, y + visina, BLUE);
}