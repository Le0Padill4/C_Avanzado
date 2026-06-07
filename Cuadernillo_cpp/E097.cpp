#include <iostream>

class Contador {
private:
    static int total;
    char nombre;

public:
    Contador() {
        nombre = 'A' + total;
        total++;

        std::cout << "(crear " << nombre << ") Total objetos: "
                  << total << std::endl;
    }

    ~Contador() {
        total--;

        std::cout << "(destruir " << nombre << ") Total objetos: "
                  << total << std::endl;
    }

    static int getTotal() {
        return total;
    }
};

int Contador::total = 0;

int main() {
    std::cout << "Total objetos: " << Contador::getTotal() << std::endl;

    {
        Contador a;
        Contador b;
        Contador c;
    }

    return 0;
}