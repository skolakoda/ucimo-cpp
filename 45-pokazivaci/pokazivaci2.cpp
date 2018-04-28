#include <iostream>

int main(){
    int number = 3;

    int *numberPointer;
    std::cout << "Empty numberPointer points to the memory address " << numberPointer << ".\n";

    numberPointer = &number;
    std::cout << "The numberPointer now points to the memory address `" << numberPointer << "`, which is the memory address of number\n";

    return 0;
}
