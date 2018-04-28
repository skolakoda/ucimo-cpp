#include <iostream>

using namespace std;
const int MAX = 3;

int main () {
   int niz[MAX] = {10, 100, 200};
   int *ptr;
   ptr = niz; // array address in pointer

   for (int i = 0; i < MAX; i++) {
      cout << "Value of niz[" << i << "] = ";
      cout << *ptr << endl;

      cout << "Address of niz[" << i << "] = ";
      cout << ptr << endl;

      // prelazi na sledecu adresu (razmaci adresa za int su 4)
      ptr++;
   }

   return 0;
}
