#include <iostream>
#include <iomanip>

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha() : dia(1), mes(1), anio(2000) {
    }

    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
    }

    Fecha(int d, int m) : dia(d), mes(m), anio(2024) {
    }

    void imprimir() {
        std::cout << std::setfill('0');
        std::cout << std::setw(2) << dia << "/"
                  << std::setw(2) << mes << "/"
                  << std::setw(4) << anio << std::endl;
        std::cout << std::setfill(' ');
    }
};

int main() {
    Fecha f1;
    Fecha f2(15, 6, 1999);
    Fecha f3(22, 3);

    f1.imprimir();
    f2.imprimir();
    f3.imprimir();

    return 0;
}