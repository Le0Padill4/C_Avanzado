#include <iostream>

int main() {
    int n;
    int numero;
    int contadores[11] = {0};

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> numero;
        contadores[numero]++;
    }

    for (int i = 1; i <= 10; i++) {
        if (contadores[i] > 0) {
            std::cout << "Valor " << i << ": " << contadores[i] << " veces" << std::endl;
        }
    }

    return 0;
}