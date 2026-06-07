#include <iostream>

int main() {
    char palabra[100];

    std::cin >> palabra;

    char* p = palabra;
    int len = 0;

    while (*p != '\0') {
        len++;
        p++;
    }

    std::cout << "Palabra: " << palabra << std::endl;
    std::cout << "Longitud (manual): " << len << std::endl;

    return 0;
}