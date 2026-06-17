#include <iostream>

int main() {
    int* p = new int;

    *p = 73;

    std::cout << "Valor en heap: " << *p << std::endl;

    delete p;
    p = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    if (p == nullptr) {
        std::cout << "Puntero es null: SI" << std::endl;
    } else {
        std::cout << "Puntero es null: NO" << std::endl;
    }

    return 0;
}