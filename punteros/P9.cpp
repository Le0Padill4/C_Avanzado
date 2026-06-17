#include <iostream>

void imprimirValor(int* p) {
    if (p == nullptr) {
        std::cout << "Puntero nulo — sin valor" << std::endl;
    } else {
        std::cout << "Valor: " << *p << std::endl;
    }
}

int main() {
    int x = 55;

    int* valido = &x;
    int* nulo = nullptr;

    imprimirValor(valido);
    imprimirValor(nulo);

    return 0;
}