#include <iostream>
#include <iomanip>

class Circulo {
public:
    double radio;

    double calcularArea() {
        const double PI = 3.14159;
        return PI * radio * radio;
    }

    double calcularPerimetro() {
        const double PI = 3.14159;
        return 2 * PI * radio;
    }

    void print() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Radio: " << radio << std::endl;
        std::cout << "Area: " << calcularArea() << std::endl;
        std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
    }
};

int main() {
    Circulo c1;
    c1.radio = 5.0;

    Circulo c2;
    c2.radio = 3.0;

    c1.print();
    c2.print();

    return 0;
}