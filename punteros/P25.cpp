#include <iostream>

int* crearArreglo(int n) {
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    return arr;
}

void aplicar(int* arr, int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

void imprimir(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int duplicar(int x) {
    return x * 2;
}

int cuadrado(int x) {
    return x * x;
}

int sumarDiez(int x) {
    return x + 10;
}

int main() {
    int n = 5;

    int* numeros = crearArreglo(n);

    std::cout << "Original: ";
    imprimir(numeros, n);

    aplicar(numeros, n, duplicar);
    std::cout << "Duplicado: ";
    imprimir(numeros, n);

    aplicar(numeros, n, cuadrado);
    std::cout << "Cuadrado: ";
    imprimir(numeros, n);

    aplicar(numeros, n, sumarDiez);
    std::cout << "+10: ";
    imprimir(numeros, n);

    delete[] numeros;
    numeros = nullptr;

    std::cout << "Memoria liberada." << std::endl;

    return 0;
}