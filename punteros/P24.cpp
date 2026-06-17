#include <iostream>

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a, int b) {
    if (b != 0) { return a / b;} 
    else {
        std::cout << "Error: division por cero" << std::endl;
        return 0;
    }
}

int main() {
    int a, b;

    std::cin >> a >> b;

    int (*operaciones[4])(int, int) = {
        sumar,
        restar,
        multiplicar,
        dividir
    };

    std::cout << "Suma: " << operaciones[0](a, b) << std::endl;
    std::cout << "Resta: " << operaciones[1](a, b) << std::endl;
    std::cout << "Multiplicacion: " << operaciones[2](a, b) << std::endl;
    std::cout << "Division: " << operaciones[3](a, b) << std::endl;

    return 0;
}