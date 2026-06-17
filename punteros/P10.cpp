#include <iostream>

void triplicar(int* n) {
    *n = *n * 3;
}

void elevarAlCuadrado(int* n) {
    *n = (*n) * (*n);
}

void resetear(int* n) {
    *n = 0;
}

int main() {
    int x = 4;

    std::cout << "x inicial: " << x << std::endl;

    triplicar(&x);
    std::cout << "tras triplicar: " << x << std::endl;

    elevarAlCuadrado(&x);
    std::cout << "tras cuadrado: " << x << std::endl;

    resetear(&x);
    std::cout << "tras resetear: " << x << std::endl;

    return 0;
}