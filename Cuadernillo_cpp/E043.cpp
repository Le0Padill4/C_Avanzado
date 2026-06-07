#include <iostream>
#include <iomanip>

int calcularMaximo(int arr[], int n) {
    int maximo = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }

    return maximo;
}

int calcularMinimo(int arr[], int n) {
    int minimo = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }

    return minimo;
}

double calcularPromedio(int arr[], int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }

    return static_cast<double>(suma) / n;
}

int main() {
    int n;
    int numeros[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Maximo: " << calcularMaximo(numeros, n) << std::endl;
    std::cout << "Minimo: " << calcularMinimo(numeros, n) << std::endl;
    std::cout << "Promedio: " << calcularPromedio(numeros, n) << std::endl;

    return 0;
}