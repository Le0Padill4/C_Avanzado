#include <iostream>
#include <string>

class Animal {
protected:
    std::string nombre;

public:
    Animal(std::string n) : nombre(n) {
    }

    std::string getNombre() const {
        return nombre;
    }

    virtual void hacerSonido() const {
        std::cout << nombre << " dice: ..." << std::endl;
    }

    virtual void imprimir() const {
        std::cout << "Animal: " << nombre << std::endl;
    }
};

class Perro : public Animal {
private:
    std::string raza;

public:
    Perro(std::string n, std::string r) : Animal(n), raza(r) {
    }

    void hacerSonido() const override {
        std::cout << nombre << " (" << raza << ") dice: Guau!" << std::endl;
    }

    void imprimir() const override {
        std::cout << nombre << " - Raza: " << raza << std::endl;
    }
};

class Gato : public Animal {
private:
    bool esCallejero;

public:
    Gato(std::string n, bool c) : Animal(n), esCallejero(c) {
    }

    void hacerSonido() const override {
        std::cout << nombre << " (Callejero: "
                  << (esCallejero ? "Si" : "No")
                  << ") dice: Miau!" << std::endl;
    }

    void imprimir() const override {
        std::cout << nombre << " - Callejero: "
                  << (esCallejero ? "Si" : "No")
                  << std::endl;
    }
};

int main() {
    Perro perro1("Rex", "Labrador");
    Gato gato1("Luna", false);

    perro1.hacerSonido();
    perro1.imprimir();

    gato1.hacerSonido();
    gato1.imprimir();

    return 0;
}