#include <iostream>
#include <iomanip>

double calcularPromedio3(double a, double b, double c) {
    return (a + b + c) / 3;
}

double calcularAreaRectangulo(double base, double altura) {
    return base * altura;
}

bool esMayorDeEdad(int edad) {
    return edad >= 18;
}

std::string clasificarEdad(int edad) {
    if (edad < 12) {
        return "Niño";
    } 
    else if (edad >= 12 && edad <= 17) {
        return "Adolescente";
    } 
    else {
        return "Adulto";
    }
}

int main() {
    double nota1, nota2, nota3;
    double base, altura;
    int edad;

    std::cin >> nota1 >> nota2 >> nota3;
    std::cin >> base >> altura;
    std::cin >> edad;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Promedio de notas: " 
              << calcularPromedio3(nota1, nota2, nota3) 
              << std::endl;

    std::cout << "Area del rectangulo: " 
              << calcularAreaRectangulo(base, altura) 
              << std::endl;

    std::cout << "Edad " << edad << ": " 
              << clasificarEdad(edad);

    if (esMayorDeEdad(edad)) {
        std::cout << " (mayor de edad)";
    } else {
        std::cout << " (menor de edad)";
    }

    std::cout << std::endl;

    return 0;
}