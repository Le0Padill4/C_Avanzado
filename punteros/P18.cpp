#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    if (n < 1 or n > 20) {
        std::cout << "Debe estar entre 1 y 20." << std::endl;
        return 0;
    }

    double* valores = new double[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Valor " << i + 1 << ": ";
        std::cin >> *(valores + i);
    }

    double suma = 0;

    for (int i = 0; i < n; i++) {
        suma += *(valores + i);
    }

    double promedio = suma / n;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Valores: ";
    for (int i = 0; i < n; i++) {
        std::cout << *(valores + i) << " ";
    }

    std::cout << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;

    delete[] valores;
    valores = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}