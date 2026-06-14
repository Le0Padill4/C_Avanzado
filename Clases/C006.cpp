#include <iostream>
#include <iomanip>
#include <cmath>

class Punto {
public:
    double x;
    double y;

    void imprimir() {
        std::cout << "(" << std::fixed << std::setprecision(2)
                  << x << ", " << y << ")";
    }

    double distanciaA(Punto otro) {
        double diferenciaX = x - otro.x;
        double diferenciaY = y - otro.y;

        return std::sqrt(diferenciaX * diferenciaX + diferenciaY * diferenciaY);
    }

    Punto puntoMedio(Punto otro) {
        Punto medio;

        medio.x = (x + otro.x) / 2.0;
        medio.y = (y + otro.y) / 2.0;

        return medio;
    }
};

int main() {
    Punto p1;
    p1.x = 3.0;
    p1.y = 4.0;

    Punto p2;
    p2.x = 7.0;
    p2.y = 1.0;

    Punto medio = p1.puntoMedio(p2);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "P1: ";
    p1.imprimir();
    std::cout << std::endl;

    std::cout << "P2: ";
    p2.imprimir();
    std::cout << std::endl;

    std::cout << "Distancia: " << p1.distanciaA(p2) << std::endl;

    std::cout << "Punto medio: ";
    medio.imprimir();
    std::cout << std::endl;

    return 0;
}