// https://codereview.stackexchange.com/questions/66481/snake-game-in-c
#include <iostream>
#include <conio.h>

void game();
void initMap();
void crtajMapu();
void mrdajZmiju(int dx, int dy);
void azurirajZmiju();
void promeniSmer(char key);
void praviHranu();
char dajKarakter(int value);

const int VISINA_MAPE = 20;
const int SIRINA_MAPE = 30;
const int VELICINA = VISINA_MAPE * SIRINA_MAPE;

int mapa[VELICINA];
int glava_x;
int glava_y;
int smer;
int duzina_zmije = 3;
bool igra_ide;

int main()
{
    game();
    return 0;
}

void game()
{
    initMap();
    igra_ide = true;
    while (igra_ide) {
        if (kbhit()) // key pressed
            promeniSmer(getch());

        azurirajZmiju();
        system("cls");
        crtajMapu();

        _sleep(200);
    }
    std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << duzina_zmije;
    std::cin.ignore(); // stop console from closing instantly
}

void promeniSmer(char key) {
    switch (key) {
    case 'w':
        if (smer != 2) smer = 0;
        break;
    case 'd':
        if (smer != 3) smer = 1;
        break;
    case 's':
        if (smer != 4) smer = 2;
        break;
    case 'a':
        if (smer != 5) smer = 3;
        break;
    }
}

void mrdajZmiju(int dx, int dy) {
    int novi_x = glava_x + dx;
    int novi_y = glava_y + dy;

    if (mapa[novi_x + novi_y * VISINA_MAPE] == -2) {
        duzina_zmije++;
        praviHranu();
    } else if (mapa[novi_x + novi_y * VISINA_MAPE] != 0) {
        igra_ide = false;
    }

    glava_x = novi_x;
    glava_y = novi_y;
    mapa[glava_x + glava_y * VISINA_MAPE] = duzina_zmije + 1;
}

void praviHranu() {
    int x = 0;
    int y = 0;
    do {
        x = rand() % (VISINA_MAPE - 2) + 1;
        y = rand() % (SIRINA_MAPE - 2) + 1;
    // If location is not free try again
    } while (mapa[x + y * VISINA_MAPE] != 0);
    mapa[x + y * VISINA_MAPE] = -2; // food
}

void azurirajZmiju() {
    switch (smer) {
        case 0: mrdajZmiju(-1, 0);
            break;
        case 1: mrdajZmiju(0, 1);
            break;
        case 2: mrdajZmiju(1, 0);
            break;
        case 3: mrdajZmiju(0, -1);
            break;
    }

    for (int i = 0; i < VELICINA; i++) {
        if (mapa[i] > 0) mapa[i]--;
    }
}

void initMap()
{
    glava_x = VISINA_MAPE / 2;
    glava_y = SIRINA_MAPE / 2;
    mapa[glava_x + glava_y * VISINA_MAPE] = 1;
    // top and bottom walls
    for (int x = 0; x < VISINA_MAPE; ++x) {
        mapa[x] = -1;
        mapa[x + (SIRINA_MAPE - 1) * VISINA_MAPE] = -1;
    }
    // left and right walls
    for (int y = 0; y < SIRINA_MAPE; y++) {
        mapa[0 + y * VISINA_MAPE] = -1;
        mapa[(VISINA_MAPE - 1) + y * VISINA_MAPE] = -1;
    }
    praviHranu();
}

void crtajMapu()
{
    for (int x = 0; x < VISINA_MAPE; ++x) {
        for (int y = 0; y < SIRINA_MAPE; ++y) {
            std::cout << dajKarakter(mapa[x + y * VISINA_MAPE]);
        }
        std::cout << std::endl;
    }
}

char dajKarakter(int value)
{
    if (value > 0) return 'o';  // telo zmije
    switch (value) {
        case -1: return 'X'; // zid
        case -2: return 'O'; // hrana
    }
}
