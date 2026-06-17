#include <iostream>
#include <iomanip>

int main() {
    int filas, columnas;

    std::cout << "Ingrese filas y columnas: ";
    std::cin >> filas >> columnas;

    int** matriz = new int*[filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j + 1;
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << std::setw(3) << matriz[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }

    delete[] matriz;
    matriz = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}