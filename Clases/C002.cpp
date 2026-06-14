#include <iostream>
#include <iomanip>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;
    double altura;

    void print() {
        std::cout << "Nombre: " << nombre
                  << ", Edad: " << edad
                  << ", Altura: " << std::fixed << std::setprecision(2)
                  << altura << "m" << std::endl;
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }

    std::string saludar() {
        return "Hola, soy " + nombre + " y tengo " + std::to_string(edad) + " años.";
    }
};

int main() {
    Persona p1;
    p1.nombre = "Ana";
    p1.edad = 22;
    p1.altura = 1.65;

    Persona p2;
    p2.nombre = "Luis";
    p2.edad = 16;
    p2.altura = 1.72;

    Persona p3;
    p3.nombre = "Carla";
    p3.edad = 19;
    p3.altura = 1.58;

    p1.print();
    std::cout << "Mayor de edad: " << (p1.esMayorDeEdad() ? "SI" : "NO") << std::endl;
    std::cout << p1.saludar() << std::endl;

    p2.print();
    std::cout << "Mayor de edad: " << (p2.esMayorDeEdad() ? "SI" : "NO") << std::endl;
    std::cout << p2.saludar() << std::endl;

    p3.print();
    std::cout << "Mayor de edad: " << (p3.esMayorDeEdad() ? "SI" : "NO") << std::endl;
    std::cout << p3.saludar() << std::endl;

    return 0;
}