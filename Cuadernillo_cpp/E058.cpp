#include <iostream>

void duplicar(int* p) {
    *p = *p * 2;
}

int main() {
    int numero;

    std::cin >> numero;

    std::cout << "Antes: " << numero << std::endl;

    duplicar(&numero);

    std::cout << "Despues: " << numero << std::endl;

    return 0;
}