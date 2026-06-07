#include <iostream>

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];

        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

void ordenarBurbuja(int arr[], int n) {
    int aux;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

int main() {
    int n;
    int numeros[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    std::cout << "Arreglo original: ";
    imprimirArreglo(numeros, n);

    ordenarBurbuja(numeros, n);

    std::cout << "Arreglo ordenado: ";
    imprimirArreglo(numeros, n);

    return 0;
}