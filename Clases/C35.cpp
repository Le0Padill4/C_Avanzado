#include <iostream>

class Volador {
public:
    virtual void volar() {
        std::cout << "Volando..." << std::endl;
    }
};

class Nadador {
public:
    virtual void nadar() {
        std::cout << "Nadando..." << std::endl;
    }
};

class Pato : public Volador, public Nadador {
private:
    std::string nombre;

public:
    Pato(std::string n) : nombre(n) {}

    void volar() override {
        std::cout << nombre << " vuela: Fiu fiu!" << std::endl;
    }

    void nadar() override {
        std::cout << nombre << " nada: Splash!" << std::endl;
    }
};

class Cisne : public Volador, public Nadador {
private:
    std::string nombre;

public:
    Cisne(std::string n) : nombre(n) {}

    void volar() override {
        std::cout << nombre << " vuela: Aleteo elegante." << std::endl;
    }

    void nadar() override {
        std::cout << nombre << " nada: Deslizamiento suave." << std::endl;
    }
};

int main() {
    Pato pato1("Donald");
    Cisne cisne1("Odette");

    pato1.volar();
    pato1.nadar();

    cisne1.volar();
    cisne1.nadar();

    return 0;
}