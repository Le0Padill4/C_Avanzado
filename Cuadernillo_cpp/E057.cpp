#include <iostream>

int main() {
    int x = 10;
    int* p = &x;

    std::cout << "Antes: " << x << std::endl;

    *p = 99;

    std::cout << "Despues: " << x << std::endl;

    return 0;
}