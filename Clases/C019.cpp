#include <iostream>
#include <iomanip>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;
    double altura;

public:
    Persona(std::string n, int e, double h) {
        nombre = n;

        if (e >= 0 && e <= 120) {
            edad = e;
        } else {
            edad = 0;
        }

        if (h >= 0.5 && h <= 2.5) {
            altura = h;
        } else {
            altura = 0.0;
        }
    }

    std::string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    double getAltura() const {
        return altura;
    }

    void setNombre(std::string n) {
        nombre = n;
    }

    void setEdad(int e) {
        if (e >= 0 && e <= 120) {
            edad = e;
        } else {
            std::cout << "Edad invalida." << std::endl;
        }
    }

    void setAltura(double h) {
        if (h >= 0.5 && h <= 2.5) {
            altura = h;
        } else {
            std::cout << "Altura invalida." << std::endl;
        }
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Nombre: " << nombre
                  << ", Edad: " << edad
                  << ", Altura: " << altura << "m" << std::endl;
    }
};

int main() {
    Persona p1("Ana", 22, 1.65);

    p1.imprimir();

    p1.setEdad(150);
    p1.setAltura(3.0);

    p1.imprimir();

    return 0;
}