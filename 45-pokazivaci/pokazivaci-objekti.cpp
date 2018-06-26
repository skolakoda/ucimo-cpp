#include <iostream>
using namespace std;

class Mapa
{
  public:
	int brojac = 1;
};

class Igrac
{
  public:
	Mapa *pMapa; // pokazivac na mapu

	Igrac(Mapa *mapa)
	{
		pMapa = mapa;
	}
};

Mapa mapa;
Igrac igrac(&mapa); // prosledjujem po referenci

int main()
{
	cout << "Inicijalni brojac: " << mapa.brojac << endl;
	igrac.pMapa->brojac++;
	cout << "Brojac nakon promene po referenci: " << mapa.brojac << endl;
	return 0;
}