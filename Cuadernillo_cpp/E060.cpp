#include <iostream>

void intercambiar(int* a, int* b) {
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a, b;

    std::cin >> a;
    std::cin >> b;

    std::cout << "Antes:  a=" << a << ", b=" << b << std::endl;

    intercambiar(&a, &b);

    std::cout << "Despues: a=" << a << ", b=" << b << std::endl;

    return 0;
}