#include <iostream>
using namespace std;

class Mapa {
	public:
		int brojac = 1;
};

class Zmija {
	public:
	Mapa *pMapa; // pokazivac na mapu

	Zmija(Mapa *mapa) {
		pMapa = mapa;	
	}
};

Mapa mapa;
Zmija zmija(&mapa); // prosledjujem po referenci

int main() {
    cout << "Inicijalni brojac: " << mapa.brojac << endl;
	zmija.pMapa->brojac++;
    cout << "Brojac nakon promene po referenci: " << mapa.brojac << endl;
	return 0;
}