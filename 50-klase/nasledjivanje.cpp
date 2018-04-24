#include <iostream>

class Junak {
  public:
    void zdravo() {
      std::cout << "Zdravo!";
    }
};

class Ork : public Junak {
  public:
    void zdravo() {
      std::cout << "Arghhh!";
    }
};

int main(int argc, char const *argv[]) {
  Junak igrac;
  igrac.zdravo();
  Ork neprijatelj;
  neprijatelj.zdravo();
}
