#include <iostream>

bool esPrimo(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << "Primos entre 1 y 50:" << std::endl;

    for (int i = 1; i <= 50; i++) {
        if (esPrimo(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}