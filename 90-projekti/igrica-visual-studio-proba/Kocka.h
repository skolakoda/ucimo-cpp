#pragma once
#include "IO.h"

enum Smer { LEVO, DESNO, GORE, DOLE };

class Kocka
{
	IO mIO;
	Smer smer = DESNO;
	int x = 0;
	int y = 0;
	int sirina = 200;
	int visina = 200;
	public:
		void unos();
		void azuriraj();
		void crtaj();
};