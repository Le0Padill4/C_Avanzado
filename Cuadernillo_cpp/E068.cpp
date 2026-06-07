#include <iostream>
#include <iomanip>

int sum(int* arr, int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += *(arr + i);
    }

    return suma;
}

double prom(int* arr, int n) {
    int suma = sum(arr, n);
    return static_cast<double>(suma) / n;
}

void invertir(int* arr, int n) {
    int inicio = 0;
    int fin = n - 1;
    int aux;

    while (inicio < fin) {
        aux = *(arr + inicio);
        *(arr + inicio) = *(arr + fin);
        *(arr + fin) = aux;

        inicio++;
        fin--;
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i);

        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int n;
    int numeros[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> *(numeros + i);
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Suma: " << sum(numeros, n) << std::endl;
    std::cout << "Promedio: " << prom(numeros, n) << std::endl;

    invertir(numeros, n);

    std::cout << "Invertido: ";
    print(numeros, n);

    return 0;
}