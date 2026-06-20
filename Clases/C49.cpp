#include <iostream>

class Figura {
public:
    virtual double calcularArea() const = 0;
    virtual void imprimir() const = 0;
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
        std::cout << "Circulo (r=" << radio << "): Area="
                  << calcularArea() << std::endl;
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
        std::cout << "Rect (" << base << "x" << altura << "): Area="
                  << calcularArea() << std::endl;
    }
};

Figura* crearFigura(std::string tipo, double a, double b) {
    if (tipo == "circulo") {
        return new Circulo(a);
    }

    if (tipo == "rectangulo") {
        return new Rectangulo(a, b);
    }

    return nullptr;
}

int main() {
    std::string tipo;
    double a;
    double b;

    while (std::cin >> tipo >> a >> b) {
        Figura* figura = crearFigura(tipo, a, b);

        if (figura != nullptr) {
            figura->imprimir();
            delete figura;
        } else {
            std::cout << "Tipo no valido" << std::endl;
        }
    }

    return 0;
}