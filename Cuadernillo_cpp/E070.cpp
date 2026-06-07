#include <iostream>

int main() {
    int n;

    std::cin >> n;

    int* arreglo = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(arreglo + i);
    }

    std::cout << "Arreglo: ";

    for (int i = 0; i < n; i++) {
        std::cout << *(arreglo + i);

        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    delete[] arreglo;
    arreglo = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}