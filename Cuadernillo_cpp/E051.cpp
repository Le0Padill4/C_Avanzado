#include <iostream>

int main() {
    std::string oracion;
    int palabras = 0;

    std::getline(std::cin, oracion);

    if (oracion.length() > 0) {
        palabras = 1;

        for (int i = 0; i < oracion.length(); i++) {
            if (oracion[i] == ' ') {
                palabras++;
            }
        }
    }

    std::cout << "Palabras: " << palabras << std::endl;

    return 0;
}