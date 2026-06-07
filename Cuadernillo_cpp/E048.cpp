#include <iostream>

int main() {
    int matriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        int sumaFila = 0;

        for (int j = 0; j < 3; j++) {
            sumaFila += matriz[i][j];
        }

        std::cout << "Suma fila " << i + 1 << ": " << sumaFila << std::endl;
    }

    for (int j = 0; j < 3; j++) {
        int sumaColumna = 0;

        for (int i = 0; i < 3; i++) {
            sumaColumna += matriz[i][j];
        }

        std::cout << "Suma columna " << j + 1 << ": " << sumaColumna << std::endl;
    }

    return 0;
}