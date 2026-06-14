#include <iostream>
#include <string>

class Recurso {
public:
    std::string nombre;

    Recurso(std::string n) : nombre(n) {
        std::cout << nombre << " creado." << std::endl;
    }

    ~Recurso() {
        std::cout << nombre << " destruido." << std::endl;
    }
};

int main() {
    Recurso r1("A");

    {
        Recurso r2("B");

        {
            Recurso r3("C");
        } 

    } 

    return 0;
} 