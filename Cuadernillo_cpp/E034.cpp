#include <iostream>

void imprimirLinea(int n = 20, char c = '-') {
    for (int i = 1; i <= n; i++) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    imprimirLinea();
    imprimirLinea(10);
    imprimirLinea(5, '*');
    
    return 0;
}