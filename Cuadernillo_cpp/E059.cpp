#include <iostream>

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        std::cin >> *(arr + i);
    }

    for (int i = 0; i < 5; i++) {
        std::cout << "Elemento " << i << ": " << *(arr + i) << std::endl;
    }

    return 0;
}