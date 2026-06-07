#include <iostream>

int* buscar(int* arr, int n, int val) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == val) {
            return arr + i;
        }
    }

    return nullptr;
}

int main() {
    int n;
    int val;

    std::cin >> n;

    int* arreglo = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(arreglo + i);
    }

    std::cin >> val;

    int* resultado = buscar(arreglo, n, val);

    if (resultado != nullptr) {
        std::cout << "Elemento encontrado: " << *resultado << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }

    delete[] arreglo;
    arreglo = nullptr;

    return 0;
}