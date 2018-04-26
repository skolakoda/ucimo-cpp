#include <iostream>
using namespace std;

void proveriStarost(int age)
{
    if (age <= 18) {
      cout <<"Junak je maloletnik." << endl;
    }
    if (age > 18 && age < 70) {
      cout << "Junak je odrastao." << endl;
    }
    if (age >= 70) {
      cout << "Junak je starac." << endl;
    }
}
