#include <iostream>
#include <string>

class Volador {
public:
    virtual void volar() {
        std::cout << "Fiu fiu!" << std::endl;
    }

    virtual ~Volador() {
    }
};

class Nadador {
public:
    virtual void nadar() {
        std::cout << "Splash splash!" << std::endl;
    }

    virtual ~Nadador() {
    }
};

class Pato : public Volador, public Nadador {
private:
    std::string nombre;

public:
    Pato(std::string n) {
        nombre = n;
    }

    std::string getNombre() {
        return nombre;
    }

    void volar() override {
        std::cout << "Fiu fiu!" << std::endl;
    }

    void nadar() override {
        std::cout << "Splash splash!" << std::endl;
    }
};

int main() {
    Pato pato("Donald");

    std::cout << pato.getNombre() << " vuela: ";
    pato.volar();

    std::cout << pato.getNombre() << " nada: ";
    pato.nadar();

    return 0;
}