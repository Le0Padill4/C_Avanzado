#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base creada" << std::endl;
    }

    ~Base() {
        std::cout << "Base destruida" << std::endl;
    }
};

class Derivada : public Base {
public:
    Derivada() {
        std::cout << "Derivada creada" << std::endl;
    }

    ~Derivada() {
        std::cout << "Derivada destruida" << std::endl;
    }
};

int main() {
    Derivada d;

    return 0;
}