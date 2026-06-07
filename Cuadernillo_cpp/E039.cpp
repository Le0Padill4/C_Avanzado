#include <iostream>
#include <iomanip>

double areaRectangulo(double base, double altura) {
    return base * altura;
}

double areaTriangulo(double base, double altura) {
    return (base * altura) / 2;
}

double areaCirculo(double radio) {
    const double PI = 3.1416;
    return PI * radio * radio;
}

void mostrarMenu() {
    std::cout << "=== Calculadora de areas ===" << std::endl;
    std::cout << "1. Rectangulo" << std::endl;
    std::cout << "2. Triangulo" << std::endl;
    std::cout << "3. Circulo" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "Opcion: ";
}

int main() {
    int opcion;
    double base, altura, radio;

    std::cout << std::fixed << std::setprecision(2);

    do {
        mostrarMenu();
        std::cin >> opcion;

        if (opcion == 1) {
            std::cin >> base >> altura;

            std::cout << "Base: " << base
                      << "  Altura: " << altura
                      << " -> Area: " << areaRectangulo(base, altura)
                      << std::endl;
        } 
        else if (opcion == 2) {
            std::cin >> base >> altura;

            std::cout << "Base: " << base
                      << "  Altura: " << altura
                      << " -> Area: " << areaTriangulo(base, altura)
                      << std::endl;
        } 
        else if (opcion == 3) {
            std::cin >> radio;

            std::cout << "Radio: " << radio
                      << " -> Area: " << areaCirculo(radio)
                      << std::endl;
        } 
        else if (opcion == 4) {
            std::cout << "Hasta pronto." << std::endl;
        } 
        else {
            std::cout << "Opcion invalida." << std::endl;
        }

    } while (opcion != 4);

    return 0;
}