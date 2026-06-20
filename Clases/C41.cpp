#include <iostream>

class Figura {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;

    virtual void imprimir() const {
        std::cout << "Area: " << calcularArea()
                  << " | Perimetro: " << calcularPerimetro()
                  << std::endl;
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

    double calcularPerimetro() const override {
        return 2 * 3.1416 * radio;
    }

    void imprimir() const override {
        std::cout << "Circulo | Area: " << calcularArea()
                  << " | Perimetro: " << calcularPerimetro()
                  << std::endl;
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

    double calcularPerimetro() const override {
        return 2 * (base + altura);
    }

    void imprimir() const override {
        std::cout << "Rectangulo | Area: " << calcularArea()
                  << " | Perimetro: " << calcularPerimetro()
                  << std::endl;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;
    double lado2;
    double lado3;

public:
    Triangulo(double b, double h, double l2, double l3)
        : base(b), altura(h), lado2(l2), lado3(l3) {}

    double calcularArea() const override {
        return base * altura / 2;
    }

    double calcularPerimetro() const override {
        return base + lado2 + lado3;
    }

    void imprimir() const override {
        std::cout << "Triangulo | Area: " << calcularArea()
                  << " | Perimetro: " << calcularPerimetro()
                  << std::endl;
    }
};

int main() {
    Figura* figuras[5];

    figuras[0] = new Circulo(5);
    figuras[1] = new Rectangulo(6, 4);
    figuras[2] = new Triangulo(3, 4, 5, 5);
    figuras[3] = new Circulo(2);
    figuras[4] = new Rectangulo(10, 3);

    double total = 0;

    for (int i = 0; i < 5; i++) {
        figuras[i]->imprimir();
        total += figuras[i]->calcularArea();
    }

    std::cout << "Area total: " << total << std::endl;

    for (int i = 0; i < 5; i++) {
        delete figuras[i];
    }

    return 0;
}