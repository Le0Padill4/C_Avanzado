#include <iostream>

class Figura {
public:
    virtual double calcularArea() const = 0;

    virtual void imprimir() const {
        std::cout << "Figura" << std::endl;
    }

    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double calcularArea() const override {
        return 3.1416 * radio * radio;
    }

    void imprimir() const override {
        std::cout << "Circulo de radio " << radio << std::endl;
    }
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura;
    }

    void imprimir() const override {
        std::cout << "Rectangulo de " << base << " x " << altura << std::endl;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura / 2;
    }

    void imprimir() const override {
        std::cout << "Triangulo de base " << base
                  << " y altura " << altura << std::endl;
    }
};

void describir(const Figura& f) {
    f.imprimir();
    std::cout << "Area: " << f.calcularArea() << std::endl;
}

int main() {
    Circulo c(5);
    Rectangulo r(6, 4);
    Triangulo t(3, 4);

    describir(c);
    describir(r);
    describir(t);

    return 0;
}