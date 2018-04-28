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
const int ZMIJA = 1; // ne moze enum jer se povecava broj

struct Mapa {
    int sirina = 30;
    int visina = 20;
    int velicina = visina * sirina;
    int polja[30 * 20]; // ne moze velicina?

    int dajPolje(int x, int y) {
        return polja[x + y * visina];
    }

    void staviPolje(int x, int y, int vrednost) {
        polja[x + y * visina] = vrednost;
    }

    void praviZidove() {
        for (int i = 0; i < visina; ++i) {
            polja[i] = ZID;
            staviPolje(i, sirina - 1, ZID);
        }
        for (int j = 0; j < sirina; j++) {
            staviPolje(0, j, ZID);
            staviPolje(visina - 1, j, ZID);
        }
    }

    void staviHranu() {
        int x, y;
        do {
            x = rand() % (visina - 2) + 1;
            y = rand() % (sirina - 2) + 1;
        } while (dajPolje(x, y) != PRAZNO);
        staviPolje(x, y, HRANA);
    }
};

Mapa mapa;
Zmija zmija(mapa.visina/2, mapa.sirina/2, 3);
bool igra_ide = true;

/* FUNKCIJE */

char dajKarakter(int value) {
    switch (value) {
        case ZID: return 'X';
        case HRANA: return 'O';
        case PRAZNO: return ' ';
        default: return 'o'; // telo zmije mogu razni brojevi
    }
}

void initMap() {
    mapa.praviZidove();
    mapa.staviPolje(zmija.x, zmija.y, ZMIJA);
    mapa.staviHranu();
}

void crtaj() {
    for (int x = 0; x < mapa.visina; ++x) {
        for (int y = 0; y < mapa.sirina; ++y) {
            std::cout << dajKarakter(mapa.dajPolje(x, y));
        }
        std::cout << std::endl;
    }
}

void mrdajZmiju(int dx, int dy) {
    int x = zmija.x + dx;
    int y = zmija.y + dy;
    if (mapa.dajPolje(x, y) == HRANA) {
        zmija.duzina++;
        mapa.staviHranu();
    } else if (mapa.dajPolje(x, y) != PRAZNO) {
        igra_ide = false;
    }
    zmija.x = x;
    zmija.y = y;
    mapa.staviPolje(x, y, zmija.duzina + 1); // povecava broj glavi zmije
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
    for (int i = 0; i < mapa.velicina; i++) {
        if (mapa.polja[i] >= ZMIJA) mapa.polja[i]--;   // smanjuje broj zmiji
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
