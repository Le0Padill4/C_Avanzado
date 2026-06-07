#include <iostream>

int main() {
    int n;

    std::cin >> n;

    int numeros[100];

    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        std::cout << numeros[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}