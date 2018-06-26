#include <iostream>

void setValueToFive(int x) {
    x = 5;
}

void setPointerValueToFive(int *x) {
    *x = 5;
}

// only in C++
void setValueToFiveWithReference(int& x) {
    x = 5;
}

int main(){
    int x = 3;
    setValueToFive(x);
    std::cout << "The value of x is " << x << ", setValueToFive() did not modify x.\n";

    x = 3;
    setPointerValueToFive(&x);
    std::cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";

    x = 3;
    setValueToFiveWithReference(x);
    std::cout << "The value of x is " << x << ", setValueToFiveWithReference() modified x.\n";

    return 0;
}
