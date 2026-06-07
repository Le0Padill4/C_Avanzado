#include <iostream>

int main() {
    int filas, columnas;

    std::cin >> filas >> columnas;

    int** mat = new int*[filas];

    for (int i = 0; i < filas; i++) {
        mat[i] = new int[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            mat[i][j] = i * j;
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << mat[i][j];

            if (j < columnas - 1) {
                std::cout << "  ";
            }
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < filas; i++) {
        delete[] mat[i];
    }

    delete[] mat;
    mat = nullptr;

    return 0;
}