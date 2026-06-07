#include <iostream>

int main() {
    int x = 42;
    int* p = &x;

    std::cout << "Valor de x: " << x << std::endl;
    std::cout << "Direccion de x: " << &x << std::endl;
    std::cout << "Valor de p: " << p << std::endl;
    std::cout << "Valor de *p: " << *p << std::endl;

    return 0;
}