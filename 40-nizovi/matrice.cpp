#include <iostream>
#define max 10

int main ()
{
    int matrica[max][max], suma[max], proizvod[max];
    int n, s = 0, p = 1;
    std::cout << "Izaberi velicinu matrice (n): ";
    std::cin >> n;

    for (int i = 1; i <= max; i++) {
        suma[i] = 0;
        proizvod[i] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cout << "Unesi vrednost matrice[" << i << "," << j << "]: ";
            std::cin >> matrica[i][j];
            suma[j] += matrica[i][j];
            proizvod[i] *= matrica[i][j];
        }

    for (int i = 1; i <= n; i++)
        std::cout << "Zbir[" << i << "]=" << suma[i] << std::endl;

    for (int i = 1; i <= n; i++)
        std::cout << "Proizvod[" << i << "]=" << proizvod[i] << std::endl;

    return 0;
}
