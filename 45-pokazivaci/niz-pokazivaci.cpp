#include <iostream>
using namespace std;

const int DUZINA = 3;

int main () {
   int niz[DUZINA] = {10, 100, 200};
   int *pokazivac = niz; // adresa niza

   for (int i = 0; i < DUZINA; i++) {
      cout << "Vrednost niz[" << i << "] je " << *pokazivac << endl;
      cout << "Adresa niz[" << i << "] je " << pokazivac << endl;
      pokazivac++;  // povecava adresu (razmaci adresa za int su 4)
   }

   return 0;
}
