#include <iostream>

class Animal {
protected:
    std::string nombre;

public:
    Animal(std::string n) : nombre(n) {}

    virtual void imprimir() const {
        std::cout << nombre << ": sonido" << std::endl;
    }
};

class Perro : public Animal {
public:
    Perro(std::string n) : Animal(n) {}

    void imprimir() const override {
        std::cout << nombre << ": Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    Gato(std::string n) : Animal(n) {}

    void imprimir() const override {
        std::cout << nombre << ": Miau!" << std::endl;
    }
};

class Pajaro : public Animal {
public:
    Pajaro(std::string n) : Animal(n) {}

    void imprimir() const override {
        if (nombre == "Loro") {
            std::cout << nombre << ": Loro quiere galleta!" << std::endl;
        } else {
            std::cout << nombre << ": Pio pio!" << std::endl;
        }
    }
};

int main() {
    Perro a1("Rex");
    Gato a2("Luna");
    Pajaro a3("Pio");
    Perro a4("Max");
    Gato a5("Pelusa");
    Pajaro a6("Loro");

    Animal* animales[6] = {&a1, &a2, &a3, &a4, &a5, &a6};

    for (int i = 0; i < 6; i++) {
        animales[i]->imprimir();
    }

    return 0;
}