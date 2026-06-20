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
        std::cout << "Circulo | Area: " << calcularArea() << std::endl;
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
        std::cout << "Rectangulo | Area: " << calcularArea() << std::endl;
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
        std::cout << "Triangulo | Area: " << calcularArea() << std::endl;
    }
};

class Cuadrado : public Figura {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}

    double calcularArea() const override {
        return lado * lado;
    }

    void imprimir() const override {
        std::cout << "Cuadrado | Area: " << calcularArea() << std::endl;
    }
};

class Rombo : public Figura {
private:
    double diagonal1;
    double diagonal2;

public:
    Rombo(double d1, double d2) : diagonal1(d1), diagonal2(d2) {}

    double calcularArea() const override {
        return diagonal1 * diagonal2 / 2;
    }

    void imprimir() const override {
        std::cout << "Rombo | Area: " << calcularArea() << std::endl;
    }
};

class Lienzo {
private:
    Figura* figuras[50];
    int cantidad;

public:
    Lienzo() : cantidad(0) {}

    void agregar(Figura* f) {
        if (cantidad < 50) {
            figuras[cantidad] = f;
            cantidad++;
        }
    }

    double areaTotalCanvas() const {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += figuras[i]->calcularArea();
        }

        return total;
    }

    double areaPromedio() const {
        if (cantidad == 0) {
            return 0;
        }

        return areaTotalCanvas() / cantidad;
    }

    Figura* figuraMayor() const {
        if (cantidad == 0) {
            return nullptr;
        }

        Figura* mayor = figuras[0];

        for (int i = 1; i < cantidad; i++) {
            if (figuras[i]->calcularArea() > mayor->calcularArea()) {
                mayor = figuras[i];
            }
        }

        return mayor;
    }

    Figura* figurasMenor() const {
        if (cantidad == 0) {
            return nullptr;
        }

        Figura* menor = figuras[0];

        for (int i = 1; i < cantidad; i++) {
            if (figuras[i]->calcularArea() < menor->calcularArea()) {
                menor = figuras[i];
            }
        }

        return menor;
    }

    void imprimirTodas() const {
        for (int i = 0; i < cantidad; i++) {
            figuras[i]->imprimir();
        }
    }

    ~Lienzo() {
        for (int i = 0; i < cantidad; i++) {
            delete figuras[i];
        }
    }
};

int main() {
    Lienzo lienzo;

    lienzo.agregar(new Circulo(5));
    lienzo.agregar(new Rectangulo(6, 4));
    lienzo.agregar(new Triangulo(3, 4));
    lienzo.agregar(new Cuadrado(8));
    lienzo.agregar(new Rombo(6, 8));
    lienzo.agregar(new Circulo(2));
    lienzo.agregar(new Rectangulo(10, 3));
    lienzo.agregar(new Triangulo(5, 7));

    lienzo.imprimirTodas();

    std::cout << "Area total: " << lienzo.areaTotalCanvas() << std::endl;
    std::cout << "Area promedio: " << lienzo.areaPromedio() << std::endl;

    std::cout << "Figura mayor: ";
    lienzo.figuraMayor()->imprimir();

    std::cout << "Figura menor: ";
    lienzo.figurasMenor()->imprimir();

    return 0;
}