#include <iostream>
#include <iomanip>

double* crearNotas(int n) {
    double* notas = new double[n];

    for (int i = 0; i < n; i++) {
        notas[i] = 0.0;
    }

    return notas;
}

void llenar(double* notas, int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> notas[i];
    }
}

double promedio(const double* notas, int n) {
    double suma = 0;

    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }

    return suma / n;
}

int main() {
    int n;

    std::cin >> n;

    if (n <= 0) {
        std::cout << "Cantidad invalida." << std::endl;
        return 0;
    }

    double* notas = crearNotas(n);

    llenar(notas, n);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Notas: ";
    for (int i = 0; i < n; i++) {
        std::cout << notas[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Promedio: " << promedio(notas, n) << std::endl;

    delete[] notas;
    notas = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}