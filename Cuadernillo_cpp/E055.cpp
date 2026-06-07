#include <iostream>
#include <iomanip>
#include <string>

double calcularPromedio(double nota1, double nota2, double nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

void ordenar(std::string nombres[], double prom[], int n) {
    std::string auxNombre;
    double auxPromedio;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (prom[j] < prom[j + 1]) {
                auxPromedio = prom[j];
                prom[j] = prom[j + 1];
                prom[j + 1] = auxPromedio;

                auxNombre = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = auxNombre;
            }
        }
    }
}

int main() {
    int n;
    std::string nombres[100];
    double nota1, nota2, nota3;
    double prom[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> nombres[i] >> nota1 >> nota2 >> nota3;
        prom[i] = calcularPromedio(nota1, nota2, nota3);
    }

    ordenar(nombres, prom, n);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "=== Ranking de estudiantes ===" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". "
                  << std::left << std::setw(7) << nombres[i]
                  << "- Promedio: "
                  << prom[i]
                  << std::endl;
    }

    return 0;
}