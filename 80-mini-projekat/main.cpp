#include "proveriStarost.h"
#include "Junak.h"

int main()
{
    Junak igrac;
    igrac.unesiIme();
    igrac.unesiGodine();
    igrac.unesiKlasu();
    igrac.predstaviSe();

    proveriStarost(igrac.godine);

    return 0;
}
