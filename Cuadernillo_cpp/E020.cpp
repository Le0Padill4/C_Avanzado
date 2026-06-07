#include <iostream>

int main() {
    int n;
    int num;
    int mayor;
    int menor;
    int contador = 1;

    std::cin >> n;

    std::cin >> num;
    mayor = num;
    menor = num;

    while (contador < n) {
        std::cin >> num;

        if (num > mayor) {
            mayor = num;
        }

        if (num < menor) {
            menor = num;
        }

        contador++;
    }

    std::cout << "Mayor: " << mayor << std::endl;
    std::cout << "Menor: " << menor << std::endl;

    return 0;
}