#include <iostream>

int busquedaBinaria(int arr[], int n, int valor) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;

        if (arr[medio] == valor) {
            return medio;
        } 
        else if (arr[medio] < valor) {
            izquierda = medio + 1;
        } 
        else {
            derecha = medio - 1;
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

    int indice = busquedaBinaria(numeros, n, valor);

    if (indice != -1) {
        std::cout << "Valor " << valor << " encontrado en indice " 
                  << indice << " (busqueda binaria)." << std::endl;
    } else {
        std::cout << "Valor " << valor << " no encontrado." << std::endl;
    }

    return 0;
}