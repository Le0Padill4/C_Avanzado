#include <iostream>
#include <string>

class Animal {
protected:
    std::string nombre;

public:
    Animal(std::string n) {
        nombre = n;
    }

    virtual void hacerSonido() {
        std::cout << "..." << std::endl;
    }

    std::string getNombre() {
        return nombre;
    }

    virtual ~Animal() {
    }
};

class Perro : public Animal {
public:
    Perro(std::string n) : Animal(n) {
    }

    void hacerSonido() override {
        std::cout << "Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    Gato(std::string n) : Animal(n) {
    }

    void hacerSonido() override {
        std::cout << "Miau!" << std::endl;
    }
};

int main() {
    Animal* animales[4];

    animales[0] = new Perro("Rex");
    animales[1] = new Gato("Luna");
    animales[2] = new Perro("Max");
    animales[3] = new Gato("Michi");

    for (int i = 0; i < 4; i++) {
        std::cout << animales[i]->getNombre() << ": ";
        animales[i]->hacerSonido();
    }

    for (int i = 0; i < 4; i++) {
        delete animales[i];
    }

    return 0;
}