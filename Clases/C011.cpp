#include <iostream>
#include <iomanip>

class Rectangulo {
public:
    double base;
    double altura;

    Rectangulo(double b, double h) : base(b), altura(h) {
    }

    double calcularArea() {
        return base * altura;
    }

    double calcularPerimetro() {
        return 2 * (base + altura);
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Base: " << base << ", Altura: " << altura << std::endl;
        std::cout << "Area: " << calcularArea() << std::endl;
        std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
    }
};

int main() {
    Rectangulo r1(6.0, 4.0);
    Rectangulo r2(10.0, 2.5);

    r1.imprimir();
    r2.imprimir();

    return 0;
}