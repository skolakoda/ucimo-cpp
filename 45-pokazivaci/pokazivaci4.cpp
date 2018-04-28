#include <iostream>

using namespace std;

int main () {
   int broj = 20;
   int *pokazivac;
   pokazivac = &broj;

   cout << "Value of broj: " << broj << endl;
   cout << "Value of pokazivac: " << pokazivac << endl;
   cout << "Value of *pokazivac: " << *pokazivac << endl;

   return 0;
}
