#include <iostream>
#include <iomanip>

int* leer(int &n) {
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(arr + i);
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

double prom(int* arr, int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += *(arr + i);
    }

    return static_cast<double>(suma) / n;
}

void libera(int* &arr) {
    delete[] arr;
    arr = nullptr;
}

int main() {
    int n;
    int* arreglo = leer(n);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Arreglo: ";
    print(arreglo, n);

    std::cout << "Promedio: " << prom(arreglo, n) << std::endl;

    libera(arreglo);
    std::cout << "Memoria liberada." << std::endl;

    return 0;
}