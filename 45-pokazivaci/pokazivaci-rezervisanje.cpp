#include <iostream>
using namespace std;

int main()
{
  // varijable nemaju vrednost ali imaju adrese
  int var1;
  char var2[10];

  cout << "Adresa var1: " << &var1 << endl;
  cout << "Adresa var2: " << &var2 << endl;

  return 0;
}
