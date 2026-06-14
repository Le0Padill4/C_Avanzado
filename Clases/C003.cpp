#include <iostream>
#include <iomanip>
#include <cmath>

class Triangulo {
public:
    double lado1;
    double lado2;
    double lado3;

    double calcularPerimetro() {
        return lado1 + lado2 + lado3;
    }

    double calcularArea() {
        double s = calcularPerimetro() / 2.0;

        return std::sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    bool esEquilatero() {
        return lado1 == lado2 && lado2 == lado3;
    }

    bool esRectangulo() {
        double a = lado1;
        double b = lado2;
        double c = lado3;

        if (a > b) {
            double temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            double temp = b;
            b = c;
            c = temp;
        }

        if (a > b) {
            double temp = a;
            a = b;
            b = temp;
        }

        double tolerancia = 0.0001;

        return std::fabs((a * a + b * b) - (c * c)) < tolerancia;
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << std::endl;
        std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
        std::cout << "Area: " << calcularArea() << std::endl;
        std::cout << "Equilatero: " << (esEquilatero() ? "SI" : "NO") << std::endl;
        std::cout << "Rectangulo: " << (esRectangulo() ? "SI" : "NO") << std::endl;
    }
};

int main() {
    Triangulo t1;

    t1.lado1 = 3.0;
    t1.lado2 = 4.0;
    t1.lado3 = 5.0;

    t1.imprimir();

    return 0;
}