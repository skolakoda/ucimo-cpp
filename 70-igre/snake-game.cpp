// https://codereview.stackexchange.com/questions/66481/snake-game-in-c
#include <iostream>
#include <conio.h>

void game();
void initMap();
void crtaj();
void mrdajZmiju(int dx, int dy);
void azurirajZmiju();
void promeniSmer(char key);
void praviHranu();
char dajKarakter(int value);

enum class Smer { levo, desno, gore, dole };
const int ZID = -1;
const int HRANA = -2;
const int PRAZNO = 0;
const int ZMIJA = 1; // ne moze enum jer se povecava broj

const int VISINA_MAPE = 20;
const int SIRINA_MAPE = 30;
const int VELICINA = VISINA_MAPE * SIRINA_MAPE;

Smer smer;
int mapa[VELICINA];
int glava_x;
int glava_y;
int duzina_zmije = 3;
bool igra_ide = true;

int main()
{
    game();
    return 0;
}

void game()
{
    initMap();
    while (igra_ide) {
        if (kbhit()) promeniSmer(getch());
        azurirajZmiju();
        system("cls");
        crtaj();
        _sleep(200);
    }
    std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << duzina_zmije;
    std::cin.ignore(); // stop console from closing instantly
}

void promeniSmer(char key) {
    switch (key) {
    case 'w':
        if (smer != Smer::dole) smer = Smer::gore;
        break;
    case 'd':
        if (smer != Smer::levo) smer = Smer::desno;
        break;
    case 's':
        if (smer != Smer::gore) smer = Smer::dole;
        break;
    case 'a':
        if (smer != Smer::desno) smer = Smer::levo;
        break;
    }
}

void mrdajZmiju(int dx, int dy) {
    int novi_x = glava_x + dx;
    int novi_y = glava_y + dy;

    if (mapa[novi_x + novi_y * VISINA_MAPE] == HRANA) {
        duzina_zmije++;
        praviHranu();
    } else if (mapa[novi_x + novi_y * VISINA_MAPE] != PRAZNO) {
        igra_ide = false;
    }

    glava_x = novi_x;
    glava_y = novi_y;
    mapa[glava_x + glava_y * VISINA_MAPE] = duzina_zmije + 1;   // povecavanje broja zmiji
}

void praviHranu() {
    int x;
    int y;
    do {
        x = rand() % (VISINA_MAPE - 2) + 1;
        y = rand() % (SIRINA_MAPE - 2) + 1;
    } while (mapa[x + y * VISINA_MAPE] != PRAZNO);
    mapa[x + y * VISINA_MAPE] = HRANA;
}

void azurirajZmiju() {
    switch (smer) {
        case Smer::gore: mrdajZmiju(-1, 0);
            break;
        case Smer::desno: mrdajZmiju(0, 1);
            break;
        case Smer::dole: mrdajZmiju(1, 0);
            break;
        case Smer::levo: mrdajZmiju(0, -1);
            break;
    }
    for (int i = 0; i < VELICINA; i++) {
        if (mapa[i] >= ZMIJA) mapa[i]--;   // oduzimanje broja zmiji
    }
}

void initMap()
{
    glava_x = VISINA_MAPE / 2;
    glava_y = SIRINA_MAPE / 2;
    mapa[glava_x + glava_y * VISINA_MAPE] = ZMIJA;
    for (int x = 0; x < VISINA_MAPE; ++x) {
        mapa[x] = ZID;
        mapa[x + (SIRINA_MAPE - 1) * VISINA_MAPE] = ZID;
    }
    for (int y = 0; y < SIRINA_MAPE; y++) {
        mapa[0 + y * VISINA_MAPE] = ZID;
        mapa[(VISINA_MAPE - 1) + y * VISINA_MAPE] = ZID;
    }
    praviHranu();
}

void crtaj()
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
    switch (value) {
        case ZID: return 'X';
        case HRANA: return 'O';
        case PRAZNO: return ' ';
        default: return 'o'; // zmija
    }
}
