#include <iostream>
using namespace std;

int main()
{
    cout << "char: " << sizeof(char) << " byte" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;

    int var = 50;
    cout << "Velicina varijable je: " << sizeof(var) << endl;

    return 0;
}
