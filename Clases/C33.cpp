#include <iostream>

class Figura {
protected:
    double area;

public:
    Figura(double a) : area(a) {}

    virtual void imprimir() const {
        std::cout << "Figura: " << area << std::endl;
    }
};

class Rectangulo : public Figura {
protected:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) : Figura(b * h), base(b), altura(h) {}

    void imprimir() const override {
        Figura::imprimir();
        std::cout << "Base: " << base << " Altura: " << altura << std::endl;
    }
};

class Cuadrado : public Rectangulo {
private:
    double lado;

public:
    Cuadrado(double l) : Rectangulo(l, l), lado(l) {}

    void imprimir() const override {
        Rectangulo::imprimir();
        std::cout << "Lado: " << lado << std::endl;
    }
};

int main() {
    Cuadrado c(5.0);
    c.imprimir();

    return 0;
}