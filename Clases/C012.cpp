#include <iostream>
#include <iomanip>

class Punto3D {
public:
    double x;
    double y;
    double z;

    Punto3D() : x(0.0), y(0.0), z(0.0) {
    }

    Punto3D(double x, double y, double z) : x(x), y(y), z(z) {
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    Punto3D p1;
    Punto3D p2(3.0, 1.0, 4.0);
    Punto3D p3(1.0, 5.0, 9.0);

    p1.imprimir();
    p2.imprimir();
    p3.imprimir();

    return 0;
}