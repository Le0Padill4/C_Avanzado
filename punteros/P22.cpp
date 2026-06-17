#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int n;

    std::cin >> n;

    if (n <= 0) {
        std::cout << "Cantidad invalida." << std::endl;
        return 0;
    }

    std::string* nombres = new std::string[n];
    double* notas = new double[n];

    for (int i = 0; i < n; i++) {
        std::cin >> nombres[i] >> notas[i];
    }

    double suma = 0;
    double maxima = notas[0];
    double minima = notas[0];
    int posMaxima = 0;
    int posMinima = 0;

    for (int i = 0; i < n; i++) {
        suma += notas[i];

        if (notas[i] > maxima) {
            maxima = notas[i];
            posMaxima = i;
        }

        if (notas[i] < minima) {
            minima = notas[i];
            posMinima = i;
        }
    }

    double promedio = suma / n;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "=== Reporte ===" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << std::left << std::setw(6) << nombres[i]
                  << ": " << notas[i] << std::endl;
    }

    std::cout << "Promedio: " << promedio << std::endl;
    std::cout << "Maxima: " << maxima << nombres[posMaxima] << std::endl;
    std::cout << "Minima: " << minima << nombres[posMinima] << std::endl;

    delete[] nombres;
    delete[] notas;

    nombres = nullptr;
    notas = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}