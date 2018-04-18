#include <iostream>
using namespace std;

void conditions()
{
    int age;
    cout << "Koliko imas godina?" << endl;
    cin >> age;

    if (age <= 18) {
      cout <<"Ti si maloletnik";
    }
    if (age > 18 && age < 70) {
      cout << "Ti si odrastao";
    }
    if (age >= 70) {
      cout << "Ti si starac";
    }
}
