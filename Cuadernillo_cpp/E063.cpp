#include <iostream>

void triplicarRef(int &n) {
    n = n * 3;
}

void triplicarPtr(int* p) {
    *p = *p * 3;
}

int main() {
    int x;

    std::cin >> x;

    std::cout << "Valor inicial: " << x << std::endl;

    triplicarRef(x);

    std::cout << "Despues de triplicarRef: " << x << std::endl;

    triplicarPtr(&x);

    std::cout << "Despues de triplicarPtr: " << x << std::endl;

    return 0;
}