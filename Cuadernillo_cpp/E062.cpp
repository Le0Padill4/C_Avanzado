#include <iostream>

int* encontrarMax(int arr[], int n) {
    int* max = arr;

    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }

    return max;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];

        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int n;
    int num[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> num[i];
    }

    int* punteromax = encontrarMax(num, n);

    std::cout << "Maximo encontrado: " << *punteromax << std::endl;

    *punteromax = *punteromax * 2;
    std::cout << "Arreglo tras duplicar el maximo: ";
    print(num, n);

    return 0;
}