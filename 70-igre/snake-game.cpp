// https://codereview.stackexchange.com/questions/66481/snake-game-in-c
#include <iostream>
#include <conio.h>

enum Smer { levo, desno, gore, dole };

class Zmija {
  public:
    int x;
    int y;
    int duzina;
    Smer smer;

    Zmija(int a, int b, int c) {
        x = a;
        y = b;
        duzina = c;
    }
    
    void okreni(char key) {
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
};

const int ZID = -1;
const int HRANA = -2;
const int PRAZNO = 0;
const int TELO_ZMIJE = 1; // ne moze enum jer se povecava broj

const int VISINA_MAPE = 20;
const int SIRINA_MAPE = 30;
const int VELICINA_MAPE = VISINA_MAPE * SIRINA_MAPE;

int mapa[VELICINA_MAPE];
bool igra_ide = true;
Zmija zmija(VISINA_MAPE / 2, SIRINA_MAPE / 2, 3);

void praviHranu() {
    int x;
    int y;
    do {
        x = rand() % (VISINA_MAPE - 2) + 1;
        y = rand() % (SIRINA_MAPE - 2) + 1;
    } while (mapa[x + y * VISINA_MAPE] != PRAZNO);
    mapa[x + y * VISINA_MAPE] = HRANA;
}

void initMap() {
    mapa[zmija.x + zmija.y * VISINA_MAPE] = TELO_ZMIJE;
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

char dajKarakter(int value) {
    switch (value) {
        case ZID: return 'X';
        case HRANA: return 'O';
        case PRAZNO: return ' ';
        default: return 'o'; // telo zmije mogu razni brojevi
    }
}

void crtaj() {
    for (int x = 0; x < VISINA_MAPE; ++x) {
        for (int y = 0; y < SIRINA_MAPE; ++y) {
            std::cout << dajKarakter(mapa[x + y * VISINA_MAPE]);
        }
        std::cout << std::endl;
    }
}

void mrdajZmiju(int dx, int dy) {
    int x = zmija.x + dx;
    int y = zmija.y + dy;

    if (mapa[x + y * VISINA_MAPE] == HRANA) {
        zmija.duzina++;
        praviHranu();
    } else if (mapa[x + y * VISINA_MAPE] != PRAZNO) {
        igra_ide = false;
    }

    zmija.x = x;
    zmija.y = y;
    mapa[zmija.x + zmija.y * VISINA_MAPE] = zmija.duzina + 1;   // povecavanje broja zmiji
}

void azurirajZmiju() {
    switch (zmija.smer) {
        case Smer::gore: mrdajZmiju(-1, 0);
            break;
        case Smer::desno: mrdajZmiju(0, 1);
            break;
        case Smer::dole: mrdajZmiju(1, 0);
            break;
        case Smer::levo: mrdajZmiju(0, -1);
            break;
    }
    for (int i = 0; i < VELICINA_MAPE; i++) {
        if (mapa[i] >= TELO_ZMIJE) mapa[i]--;   // oduzimanje broja zmiji
    }
}

int main() {
    initMap();
    while (igra_ide) {
        if (kbhit()) zmija.okreni(getch());
        azurirajZmiju();
        system("cls");
        crtaj();
        _sleep(200);
    }
    std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << zmija.duzina;
    return 0;
}
