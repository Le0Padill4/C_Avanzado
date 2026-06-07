#include <iostream>

int main() {
    int* p = new int(99);

    std::cout << "Valor: " << *p << std::endl;
    std::cout << "Direccion: " << p << std::endl;

    delete p;
    p = nullptr;

    std::cout << "Memoria liberada correctamente." << std::endl;

    return 0;
}