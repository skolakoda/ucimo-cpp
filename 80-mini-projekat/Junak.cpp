#include "Junak.h"
#include <iostream>

using namespace std;

void Junak::unesiGodine() {
    cout << "Unesi svoje godine" << endl;
    cin >> godine;
}

void Junak::unesiIme() {
    cout << "Unesi svoje ime" << endl;
    cin >> ime;
    ime[0] = toupper(ime[0]);
}

void Junak::unesiKlasu() {
    cout << "Unesi klasu" << endl;
    cin >> klasa;
}

void Junak::predstaviSe() {
    cout << "Zdravo ja sam " << ime << ". Moja starost je " << godine << " godine. Po zanimanju sam " << klasa << "." << endl;
}
