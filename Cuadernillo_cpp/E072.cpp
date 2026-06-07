#include <iostream>

int* crear(int n, int inicio) {
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        *(arr + i) = inicio;
    }

    return arr;
}

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
    int inicio;

    std::cin >> n;
    std::cin >> inicio;

    int* arreglo = crear(n, inicio);

    std::cout << "Arreglo de " << n << " elementos inicializados en "
              << inicio << ":" << std::endl;

    print(arreglo, n);

    delete[] arreglo;
    arreglo = nullptr;

    return 0;
}