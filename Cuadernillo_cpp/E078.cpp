#include <iostream>
#include <string>

void ordenar(std::string* arr, int n) {
    std::string aux;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                aux = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = aux;
            }
        }
    }
}

void print(std::string* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i) << std::endl;
    }
}

int main() {
    int n;

    std::cin >> n;

    std::string* palabras = new std::string[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(palabras + i);
    }

    ordenar(palabras, n);

    std::cout << "Ordenado:" << std::endl;
    print(palabras, n);

    delete[] palabras;
    palabras = nullptr;

    return 0;
}