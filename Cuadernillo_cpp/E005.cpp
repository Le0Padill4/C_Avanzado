#include <iostream>

int main() {
    int a, b;
    std :: cout << "Entrada: ";
    std :: cin >> a;

    std :: cin >> a;

    b = a % 2;

    std :: cout << a << " % 2 = " << b << std :: endl;
    if (b == 0) {
        std :: cout << "El numero es par." << std :: endl;
    } else {
        std :: cout << "El numero es impar." << std :: endl;
    }

    return 0;
}