#pragma once
#include "IO.h"

enum Smer { LEVO, DESNO, GORE, DOLE };

class Kocka
{
public:
	int x = 0;
	int y = 0;
	int sirina = 200;
	int visina = 200;
	Smer smer = DESNO;
	IO mIO;

	void unos();
	void azuriraj();
	void crtaj();
};