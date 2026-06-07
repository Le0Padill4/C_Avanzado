#include <iostream>
#include <iomanip>
#include <string>

void ordenar(std::string* nombres, double* notas, int n) {
    std::string auxNombre;
    double auxNota;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(notas + j) < *(notas + j + 1)) {
                auxNota = *(notas + j);
                *(notas + j) = *(notas + j + 1);
                *(notas + j + 1) = auxNota;

                auxNombre = *(nombres + j);
                *(nombres + j) = *(nombres + j + 1);
                *(nombres + j + 1) = auxNombre;
            }
        }
    }
}

void print(std::string* nombres, double* notas, int n) {
    std::cout << "=== Ranking ===" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". "
                  << std::left << std::setw(7) << *(nombres + i)
                  << "- "
                  << std::fixed << std::setprecision(2)
                  << *(notas + i)
                  << std::endl;
    }
}

int main() {
    int n;

    std::cin >> n;

    std::string* nombres = new std::string[n];
    double* notas = new double[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(nombres + i) >> *(notas + i);
    }

    ordenar(nombres, notas, n);

    print(nombres, notas, n);

    delete[] nombres;
    delete[] notas;

    nombres = nullptr;
    notas = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}