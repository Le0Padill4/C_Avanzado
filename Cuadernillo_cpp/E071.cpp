#include <iostream>

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i);

        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int n;
    int nuevoElemento;

    std::cin >> n;

    int* arreglo = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(arreglo + i);
    }

    std::cin >> nuevoElemento;

    std::cout << "Original: ";
    print(arreglo, n);

    int* arregloExtendido = new int[n + 1];

    for (int i = 0; i < n; i++) {
        *(arregloExtendido + i) = *(arreglo + i);
    }

    *(arregloExtendido + n) = nuevoElemento;

    delete[] arreglo;
    arreglo = nullptr;

    std::cout << "Extendido: ";
    print(arregloExtendido, n + 1);

    delete[] arregloExtendido;
    arregloExtendido = nullptr;

    return 0;
}