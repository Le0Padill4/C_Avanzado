#include <iostream>

void saludar(std::string nom) {
    std::cout << "Hola, " << nom << "! Bienvenido al sistema." << std::endl;
}

int main() {
    std::string nom;

    std::cin >> nom;

    saludar(nom);

    return 0;
}