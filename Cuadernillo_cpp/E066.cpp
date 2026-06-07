#include <iostream>

int* buscarPtr(int* arr, int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == valor) {
            return arr + i;
        }
    }

    return nullptr;
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

    int* resultado = buscarPtr(numeros, n, valor);

    if (resultado != nullptr) {
        std::cout << "Valor " << valor << " encontrado." << std::endl;
    } else {
        std::cout << "Valor " << valor << " no encontrado." << std::endl;
    }

    return 0;
}