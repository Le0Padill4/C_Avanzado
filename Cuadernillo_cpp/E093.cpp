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
    Perro perro("Rex");
    Gato gato("Luna");

    std::cout << "Perro (" << perro.getNombre() << "): ";
    perro.hacerSonido();

    std::cout << "Gato (" << gato.getNombre() << "): ";
    gato.hacerSonido();

    return 0;
}