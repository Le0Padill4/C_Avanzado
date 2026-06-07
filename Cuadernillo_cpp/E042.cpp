#include <iostream>

int buscar(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n;
    int numeros[100];
    int valor;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    std::cin >> valor;

    int indice = buscar(numeros, n, valor);

    if (indice != -1) {
        std::cout << "Valor " << valor << " encontrado en indice " << indice << "." << std::endl;
    } else {
        std::cout << "Valor " << valor << " no encontrado." << std::endl;
    }

    return 0;
}