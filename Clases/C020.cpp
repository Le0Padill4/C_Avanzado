#include <iostream>
#include <iomanip>

class Rectangulo {
private:
    double base;
    double altura;

public:
    Rectangulo(double base, double altura) {
        if (base > 0) {
            this->base = base;
        } else {
            this->base = 1.0;
        }

        if (altura > 0) {
            this->altura = altura;
        } else {
            this->altura = 1.0;
        }
    }

    double getBase() const {
        return base;
    }

    double getAltura() const {
        return altura;
    }

    void setBase(double base) {
        if (base > 0) {
            this->base = base;
        } else {
            std::cout << "Base debe ser positiva." << std::endl;
        }
    }

    void setAltura(double altura) {
        if (altura > 0) {
            this->altura = altura;
        } else {
            std::cout << "Altura debe ser positiva." << std::endl;
        }
    }

    double calcularArea() const {
        return base * altura;
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Base: " << base
                  << ", Altura: " << altura
                  << ", Area: " << calcularArea() << std::endl;
    }
};

int main() {
    Rectangulo r1(5.0, 3.0);

    r1.imprimir();

    r1.setBase(-2.0);
    r1.imprimir();

    r1.setBase(8.0);
    r1.imprimir();

    return 0;
}