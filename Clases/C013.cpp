#include <iostream>
#include <iomanip>

class Circulo {
public:
    const double PI;
    double radio;

    Circulo(double r) : PI(3.14159), radio(r) {
    }

    double area() {
        return PI * radio * radio;
    }

    double perimetro() {
        return 2 * PI * radio;
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Radio: " << radio << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimetro: " << perimetro() << std::endl;
    }
};

int main() {
    Circulo c1(7.0);

    c1.imprimir();

    return 0;
}