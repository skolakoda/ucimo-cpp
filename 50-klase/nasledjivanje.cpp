#include <iostream>

class Junak {
  public:
    void zdravo() {
      std::cout << "Zdravo!" << std::endl;
    }
};

// ork nasledjuje junaka i gazi njegovu metodu

class Ork : public Junak {
  public:
    void zdravo() {
      std::cout << "Arghhh!" << std::endl;
    }
};

int main() {
  Junak igrac;
  Ork neprijatelj;

  igrac.zdravo();
  neprijatelj.zdravo();
}
