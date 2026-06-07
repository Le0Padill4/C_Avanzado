#include <iostream>

int main() {
    int opcion;

    do {
        std::cout << "=== Menu ===" << std::endl;
        std::cout << "1. Saludar" << std::endl;
        std::cout << "2. Despedirse" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Opcion: ";

        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "Hola!" << std::endl;
        } 
        else if (opcion == 2) {
            std::cout << "Hasta luego!" << std::endl;
        } 
        else if (opcion == 3) {
            std::cout << "Programa terminado." << std::endl;
        } 
        else {
            std::cout << "Opcion invalida." << std::endl;
        }

    } while (opcion != 3);

    return 0;
}