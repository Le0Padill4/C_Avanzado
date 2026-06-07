#include <iostream>
#include <cctype>

int main() {
    std::string oracion;

    std::getline(std::cin, oracion);

    std::cout << "Longitud: " << oracion.length() << std::endl;

    for (int i = 0; i < oracion.length(); i++) {
        oracion[i] = std::toupper(oracion[i]);
    }

    std::cout << "En mayusculas: " << oracion << std::endl;

    return 0;
}