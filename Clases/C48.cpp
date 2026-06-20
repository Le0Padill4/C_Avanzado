#include <iostream>

class Forma {
public:
    virtual double area() const = 0;

    void imprimir() const {
        std::cout << "Area: " << area() << std::endl;
    }

    virtual ~Forma() {}
};

class Cuadrado : public Forma {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}

    double area() const override {
        return lado * lado;
    }
};

class Rombo : public Forma {
private:
    double d1;
    double d2;

public:
    Rombo(double diagonal1, double diagonal2)
        : d1(diagonal1), d2(diagonal2) {}

    double area() const override {
        return (d1 * d2) / 2;
    }
};

class Pentagono : public Forma {
private:
    double perimetro;
    double apotema;

public:
    Pentagono(double p, double a)
        : perimetro(p), apotema(a) {}

    double area() const override {
        return (perimetro * apotema) / 2;
    }
};

int main() {
    Cuadrado c(5);
    Rombo r(6, 8);
    Pentagono p(15, 4.588);

    Forma* formas[3] = {&c, &r, &p};

    for (int i = 0; i < 3; i++) {
        formas[i]->imprimir();
    }

    return 0;
}