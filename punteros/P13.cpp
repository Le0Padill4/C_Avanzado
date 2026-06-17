#include <iostream>

void doblarElementos(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        *(arr + i) = *(arr + i) * 2;
    }
}

void imprimirArreglo(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int n = 5;

    std::cout << "Original : ";
    imprimirArreglo(numeros, n);

    doblarElementos(numeros, n);

    std::cout << "Doblado  : ";
    imprimirArreglo(numeros, n);

    return 0;
}