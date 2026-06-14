#include <iostream>
#include <iomanip>
#include <cmath>

class Triangulo {
private:
    double base;
    double altura;
    double hipotenusa;

public:
    Triangulo(double b, double h) : base(b), altura(h) {
        hipotenusa = std::sqrt(base * base + altura * altura);
    }

    double getBase() const {
        return base;
    }

    double getAltura() const {
        return altura;
    }

    double getHipotenusa() const {
        return hipotenusa;
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Base     : " << base << std::endl;
        std::cout << "Altura   : " << altura << std::endl;
        std::cout << "Hipotenusa: " << hipotenusa << std::endl;
    }
};

int main() {
    Triangulo t1(3.0, 4.0);

    t1.imprimir();

    return 0;
}