// https://codereview.stackexchange.com/questions/66481/snake-game-in-c
#include <iostream>
#include <conio.h>

enum Smer { LEVO, DESNO, GORE, DOLE };

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
                if (smer != Smer::DOLE) smer = Smer::GORE;
                break;
            case 'd':
                if (smer != Smer::LEVO) smer = Smer::DESNO;
                break;
            case 's':
                if (smer != Smer::GORE) smer = Smer::DOLE;
                break;
            case 'a':
                if (smer != Smer::DESNO) smer = Smer::LEVO;
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
int mapa_polja[VELICINA_MAPE];

Zmija zmija(VISINA_MAPE / 2, SIRINA_MAPE / 2, 3);
bool igra_ide = true;

int dajPolje(int x, int y) {
    return mapa_polja[x + y * VISINA_MAPE];
}

void setPolje(int x, int y, int vrednost) {
    mapa_polja[x + y * VISINA_MAPE] = vrednost;
}

char dajKarakter(int value) {
    switch (value) {
        case ZID: return 'X';
        case HRANA: return 'O';
        case PRAZNO: return ' ';
        default: return 'o'; // telo zmije mogu razni brojevi
    }
}

void praviHranu() {
    int x;
    int y;
    do {
        x = rand() % (VISINA_MAPE - 2) + 1;
        y = rand() % (SIRINA_MAPE - 2) + 1;
    } while (dajPolje(x, y) != PRAZNO);
    setPolje(x, y, HRANA);
}

void initMap() {
    setPolje(zmija.x, zmija.y, TELO_ZMIJE);
    for (int x = 0; x < VISINA_MAPE; ++x) {
        mapa_polja[x] = ZID;
        setPolje(x, SIRINA_MAPE - 1, ZID);
    }
    for (int y = 0; y < SIRINA_MAPE; y++) {
        setPolje(0, y, ZID);
        setPolje(VISINA_MAPE - 1, y, ZID);
    }
    praviHranu();
}

void crtaj() {
    for (int x = 0; x < VISINA_MAPE; ++x) {
        for (int y = 0; y < SIRINA_MAPE; ++y) {
            std::cout << dajKarakter(dajPolje(x, y));
        }
        std::cout << std::endl;
    }
}

void mrdajZmiju(int dx, int dy) {
    int x = zmija.x + dx;
    int y = zmija.y + dy;
    if (dajPolje(x, y) == HRANA) {
        zmija.duzina++;
        praviHranu();
    } else if (dajPolje(x, y) != PRAZNO) {
        igra_ide = false;
    }
    zmija.x = x;
    zmija.y = y;
    setPolje(x, y, zmija.duzina + 1); // povecava broj glavi zmije
}

void azurirajZmiju() {
    switch (zmija.smer) {
        case Smer::GORE: mrdajZmiju(-1, 0);
            break;
        case Smer::DESNO: mrdajZmiju(0, 1);
            break;
        case Smer::DOLE: mrdajZmiju(1, 0);
            break;
        case Smer::LEVO: mrdajZmiju(0, -1);
            break;
    }
    for (int i = 0; i < VELICINA_MAPE; i++) {
        if (mapa_polja[i] >= TELO_ZMIJE) mapa_polja[i]--;   // smanjuje broj zmiji
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
