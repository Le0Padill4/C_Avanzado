#include <iostream>

void intercambiar(int &a, int &b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a;
    int b;

    std::cin >> a;
    std::cin >> b;

    std::cout << "Antes:  a=" << a << ", b=" << b << std::endl;

    intercambiar(a, b);

    std::cout << "Despues: a=" << a << ", b=" << b << std::endl;

    return 0;
}