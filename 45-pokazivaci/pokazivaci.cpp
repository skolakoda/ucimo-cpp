#include <iostream>

int main(){
    int number = 3;
    std::cout << "number is initialized with a value of " << number << "\n";

    number = number * 2;
    std::cout << "After modifying number, its value is now " << number << "\n";

    std::cout << "The number variable's value lives at memory address " << &number << "\n";

    return 0;
}
