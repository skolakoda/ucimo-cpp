#include <iostream>
using namespace std;

int main()
{
    cout << "char: " << sizeof(char) << " bajt" << endl;
    cout << "int: " << sizeof(int) << " bajta" << endl;
    cout << "float: " << sizeof(float) << " bajta" << endl;
    cout << "double: " << sizeof(double) << " bajta" << endl;

    int broj = 50;
    cout << "Velicina celobrojne varijable je: " << sizeof(broj) << endl;

    return 0;
}
