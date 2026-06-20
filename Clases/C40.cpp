#include <iostream>

class Figura {
protected:
    std::string color;

public:
    Figura(std::string c) : color(c) {}

    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;

    virtual void imprimir() const {
        std::cout << "Figura color: " << color << std::endl;
    }
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r, std::string c) : Figura(c), radio(r) {}

    double calcularArea() const override {
        return 3.1416 * radio * radio;
    }

    double calcularPerimetro() const override {
        return 2 * 3.1416 * radio;
    }

    void imprimir() const override {
        std::cout << "Circulo " << color << " Radio: " << radio << " Area: " << calcularArea() << " Perim: " << calcularPerimetro()<< std::endl;
    }
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h, std::string c)
        : Figura(c), base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura;
    }

    double calcularPerimetro() const override {
        return 2 * (base + altura);
    }

    void imprimir() const override {
        std::cout << "Rectangulo " << color << base << "x" << altura << " Area: " << calcularArea() << " Perim: " << calcularPerimetro() << std::endl;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double h, std::string c)
        : Figura(c), base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura / 2;
    }

    double calcularPerimetro() const override {
        return 0;
    }

    void imprimir() const override {
        std::cout << "Triangulo " << color << " Base: " << base << " Altura: " << altura << " Area: " << calcularArea() << std::endl;
    }
};

int main() {
    Circulo c(5, "rojo");
    Rectangulo r(6, 4, "azul");
    Triangulo t(3, 4, "verde");

    c.imprimir();
    r.imprimir();
    t.imprimir();

    return 0;
}