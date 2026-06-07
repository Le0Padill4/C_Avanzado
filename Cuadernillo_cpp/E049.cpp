#include <iostream>

int main() {
    int n;
    int matriz[100][100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz[i][j];
        }
    }

    int suma = 0;

    std::cout << "Diagonal principal: ";

    for (int i = 0; i < n; i++) {
        std::cout << matriz[i][i] << " ";
        suma += matriz[i][i];
    }

    std::cout << std::endl;
    std::cout << "Suma: " << suma << std::endl;

    return 0;
}