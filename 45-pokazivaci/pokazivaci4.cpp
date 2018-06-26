#include <iostream>

using namespace std;

int main () {
   int broj = 20;
   int *pokazivac;
   pokazivac = &broj;

   cout << "Vrednost pokazivac je " << pokazivac << endl;
   cout << "Vrednost *pokazivac je " << *pokazivac << endl;

   return 0;
}
