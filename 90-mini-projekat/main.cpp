#include "proveriStarost.h"
#include "Junak.h"
#include "Ork.h"

int main()
{
    Junak igrac1;
    igrac1.unesiIme();
    igrac1.unesiGodine();
    igrac1.unesiKlasu();
    igrac1.predstaviSe();

    proveriStarost(igrac1.ime, igrac1.godine);

    Ork igrac2;
    igrac2.unesiIme();
    igrac2.unesiGodine();
    igrac2.unesiKlasu();
    igrac2.predstaviSe();

    proveriStarost(igrac2.ime, igrac2.godine);

    return 0;
}
