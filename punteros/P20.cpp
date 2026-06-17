#include <iostream>

int main() {
    int* original = new int[3];

    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    std::cout << "Original: ";
    for (int i = 0; i < 3; i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;

    int* ampliado = new int[6];

    for (int i = 0; i < 3; i++) {
        ampliado[i] = original[i];
    }

    ampliado[3] = 4;
    ampliado[4] = 5;
    ampliado[5] = 6;

    delete[] original;
    original = nullptr;

    std::cout << "Ampliado: ";
    for (int i = 0; i < 6; i++) {
        std::cout << ampliado[i] << " ";
    }
    std::cout << std::endl;

    delete[] ampliado;
    ampliado = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}