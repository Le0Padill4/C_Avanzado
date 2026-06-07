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

int main() {
    int opcion;
    int a, b;

    int (*op)(int, int);

    std::cin >> opcion;
    std::cin >> a >> b;

    if (opcion == 1) {
        op = sumar;
    } 
    else if (opcion == 2) {
        op = restar;
    } 
    else if (opcion == 3) {
        op = multiplicar;
    } 
    else {
        std::cout << "Opcion invalida." << std::endl;
        return 0;
    }

    std::cout << "Resultado: " << op(a, b) << std::endl;

    return 0;
}