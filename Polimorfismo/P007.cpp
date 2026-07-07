#include <iostream>
#include <iomanip>
#include <cmath>

class Figura {
public:
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void imprimir() const = 0;

    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double area() const override {
        return 3.14116 * radio * radio;
    }

    double perimetro() const override {
        return 2 * 3.14116 * radio;
    }

    void imprimir() const override {
        std::cout << std::left << std::setw(10) << "Circulo"
                  << " : area=" << std::fixed << std::setprecision(2) << area()
                  << "  perim=" << perimetro()
                  << std::endl;
    }
};

class Cuadrado : public Figura {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}

    double area() const override {
        return lado * lado;
    }

    double perimetro() const override {
        return 4 * lado;
    }

    void imprimir() const override {
        std::cout << std::left << std::setw(10) << "Cuadrado"
                  << " : area=" << std::fixed << std::setprecision(2) << area()
                  << "  perim=" << perimetro()
                  << std::endl;
    }
};

class TrianguloR : public Figura {
private:
    double cateto1;
    double cateto2;
    double hipotenusa;

public:
    TrianguloR(double c1, double c2)
        : cateto1(c1), cateto2(c2), hipotenusa(std::sqrt(c1 * c1 + c2 * c2)) {}

    double area() const override {
        return cateto1 * cateto2 / 2.0;
    }

    double perimetro() const override {
        return cateto1 + cateto2 + hipotenusa;
    }

    void imprimir() const override {
        std::cout << std::left << std::setw(10) << "TrianguloR"
                  << " : area=" << std::fixed << std::setprecision(2) << area()
                  << "  perim=" << perimetro()
                  << std::endl;
    }
};

int main() {
    Figura* figuras[5];

    figuras[0] = new Circulo(5.0);
    figuras[1] = new Cuadrado(5.0);
    figuras[2] = new TrianguloR(3.0, 4.0);
    figuras[3] = new Circulo(2.0);
    figuras[4] = new Cuadrado(3.0);

    for (int i = 0; i < 5; i++) {
        figuras[i]->imprimir();
    }

    for (int i = 0; i < 5; i++) {
        delete figuras[i];
        figuras[i] = nullptr;
    }

    return 0;
}