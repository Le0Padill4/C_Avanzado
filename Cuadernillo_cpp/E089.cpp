#include <iostream>
#include <iomanip>

class Rectangulo {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) {
        base = b;
        altura = h;
    }

    double area() {
        return base * altura;
    }

    double perimetro() {
        return 2 * (base + altura);
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Rectangulo: base=" << base
                  << ", altura=" << altura << std::endl;

        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimetro: " << perimetro() << std::endl;
    }
};

int main() {
    double base, altura;

    std::cin >> base >> altura;

    Rectangulo rectangulo(base, altura);

    rectangulo.imprimir();

    return 0;
}