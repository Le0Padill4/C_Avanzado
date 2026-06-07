#include <iostream>
#include <iomanip>
#include <cmath>

class Figura {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;

    void describir() {
        std::cout << "Area=" << calcularArea()
                  << ", Perimetro=" << calcularPerimetro()
                  << std::endl;
    }

    virtual ~Figura() {
    }
};

class Circulo : public Figura {
private:
    double radio;
    const double PI = 3.14159;

public:
    Circulo(double r) {
        radio = r;
    }

    double calcularArea() override {
        return PI * radio * radio;
    }

    double calcularPerimetro() override {
        return 2 * PI * radio;
    }

    double getRadio() {
        return radio;
    }
};

class Triangulo : public Figura {
private:
    double a;
    double b;
    double c;

public:
    Triangulo(double ladoA, double ladoB, double ladoC) {
        a = ladoA;
        b = ladoB;
        c = ladoC;
    }

    double calcularPerimetro() override {
        return a + b + c;
    }

    double calcularArea() override {
        double s = calcularPerimetro() / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    double getC() {
        return c;
    }
};

int main() {
    double radio;
    double a, b, c;

    std::cin >> radio;
    std::cin >> a >> b >> c;

    Circulo circulo(radio);
    Triangulo triangulo(a, b, c);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Circulo (r=" << circulo.getRadio() << "): ";
    circulo.describir();

    std::cout << "Triangulo ("
              << triangulo.getA() << ","
              << triangulo.getB() << ","
              << triangulo.getC() << "): ";
    triangulo.describir();

    return 0;
}