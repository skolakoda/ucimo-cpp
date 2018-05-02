// za windows
#include <iostream>
#include <conio.h>

enum Smer { LEVO, DESNO, GORE, DOLE };

const int ZID = -1;
const int HRANA = -2;
const int PRAZNO = 0;
const int ZMIJA = 1; // ne moze enum jer se povecava broj

bool igra_ide = true;

char dajKarakter(int value) {
    switch (value) {
        case ZID: return 'X';
        case HRANA: return 'O';
        case PRAZNO: return ' ';
        default: return 'o'; // telo zmije mogu razni brojevi
    }
}

struct Mapa {
    int sirina = 30;
    int visina = 20;
    int velicina = visina * sirina;
    int polja[30 * 20]; // ne moze velicina?

    int dajPolje(int x, int y) {
        return polja[x + y * visina];
    }

    void postaviPolje(int x, int y, int vrednost) {
        polja[x + y * visina] = vrednost;
    }

    void postaviZidove() {
        for (int i = 0; i < visina; ++i) {
            polja[i] = ZID;
            postaviPolje(i, sirina - 1, ZID);
        }
        for (int j = 0; j < sirina; j++) {
            postaviPolje(0, j, ZID);
            postaviPolje(visina - 1, j, ZID);
        }
    }

    void postaviHranu() {
        int x, y;
        do {
            x = rand() % (visina - 2) + 1;
            y = rand() % (sirina - 2) + 1;
        } while (dajPolje(x, y) != PRAZNO);
        postaviPolje(x, y, HRANA);
    }

    void azuriraj() {
        for (int i = 0; i < velicina; i++) {
            if (polja[i] >= ZMIJA) polja[i]--;   // smanjuje broj citavoj zmiji
        }
    }

    void crtaj() {
        for (int x = 0; x < visina; ++x) {
            for (int y = 0; y < sirina; ++y) {
                std::cout << dajKarakter(dajPolje(x, y));
            }
            std::cout << std::endl;
        }
    }
};

class Zmija {
  public:
    int x;
    int y;
    int duzina;
    Smer smer;
    Mapa *pMapa;

    Zmija(Mapa *mapa, int c) {
        pMapa = mapa;
        x = pMapa->visina/2;
        y = pMapa->sirina/2;
        duzina = c;
    }
    
    void unos(char key) {
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

    void azuriraj() {
        switch (smer) {
            case Smer::GORE: mrdaj(-1, 0);
                break;
            case Smer::DESNO: mrdaj(0, 1);
                break;
            case Smer::DOLE: mrdaj(1, 0);
                break;
            case Smer::LEVO: mrdaj(0, -1);
                break;
        }
    }

    void mrdaj(int dx, int dy) {
        int novi_x = x + dx;
        int novi_y = y + dy;
        if (pMapa->dajPolje(novi_x, novi_y) == HRANA) {
            duzina++;
            pMapa->postaviHranu();
        } else if (pMapa->dajPolje(novi_x, novi_y) != PRAZNO) {
            igra_ide = false;
        }
        x = novi_x;
        y = novi_y;
        pMapa->postaviPolje(x, y, duzina + 1); // povecava broj glavi zmije
    }
};

Mapa mapa;
Zmija zmija(&mapa, 3);

/* INIT */

void initMap() {
    mapa.postaviZidove();
    mapa.postaviPolje(zmija.x, zmija.y, ZMIJA);
    mapa.postaviHranu();
}

int main() {
    initMap();
    while (igra_ide) {
        system("cls");
        if (kbhit()) zmija.unos(getch());
        zmija.azuriraj();
        mapa.azuriraj();
        mapa.crtaj();
        _sleep(200);
    }
    std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << zmija.duzina;
    return 0;
}
