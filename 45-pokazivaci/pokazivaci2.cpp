#include <iostream>

int main(){
    int broj = 3;
    int *pokazivac;

    std::cout << "Prazan pokazivac pokazuje na memorijsku adresu " << pokazivac << ".\n";

    pokazivac = &broj;
    std::cout << "Pokazivac sada pokazuje na " << pokazivac << ", memorijsku adresu varijable broj.\n";

    return 0;
}
