#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream archivoSalida("poema.txt");

    if (archivoSalida.is_open()) {
        archivoSalida << "Las rosas son rojas" << std::endl;
        archivoSalida << "El mar es profundo" << std::endl;
        archivoSalida << "El codigo es logica" << std::endl;
        archivoSalida << "C++ es poderoso" << std::endl;

        archivoSalida.close();
    } else {
        std::cout << "No se pudo crear el archivo." << std::endl;
        return 0;
    }

    std::ifstream archivoEntrada("poema.txt");

    if (archivoEntrada.is_open()) {
        std::string linea;
        int contador = 1;

        while (std::getline(archivoEntrada, linea)) {
            std::cout << contador << ": " << linea << std::endl;
            contador++;
        }

        archivoEntrada.close();
    } else {
        std::cout << "No se pudo leer el archivo." << std::endl;
    }

    return 0;
}