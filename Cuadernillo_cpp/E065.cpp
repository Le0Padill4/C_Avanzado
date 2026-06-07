#include <iostream>

void llenarCuadrados(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        *(arr + i) = i * i;
    }
}

int main() {
    int n;
    int numeros[100];

    std::cin >> n;

    llenarCuadrados(numeros, n);

    for (int i = 0; i < n; i++) {
        std::cout << *(numeros + i);

        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}