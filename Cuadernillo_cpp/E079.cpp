#include <iostream>

int main() {
    int* p = new int(10);

    std::cout << "Valor antes de delete: " << *p << std::endl;

    delete p;
    p = nullptr;

    if (p != nullptr) {
        std::cout << *p << std::endl;
    } else {
        std::cout << "Puntero puesto en nullptr. Acceso bloqueado." << std::endl;
    }

    return 0;
}