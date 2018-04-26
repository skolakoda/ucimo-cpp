#include <iostream>
#include <string>
using namespace std;

void proveriStarost(string ime, int age)
{
    if (age <= 18) {
      cout << ime << " je maloletnik." << endl;
    }
    if (age > 18 && age < 70) {
      cout << ime << " je odrastao." << endl;
    }
    if (age >= 70) {
      cout << ime << " je starac." << endl;
    }
}
