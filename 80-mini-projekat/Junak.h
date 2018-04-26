#ifndef JUNAK_H
#define JUNAK_H
#include <string>

class Junak
{
    public:
        int godine;
        std::string ime;
        std::string klasa;
        void unesiIme();
        void unesiGodine();
        void unesiKlasu();
        void predstaviSe();

    protected:

    private:
};

#endif // JUNAK_H
