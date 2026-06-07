#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream archivoEntrada("estudiantes.txt");

    if (!archivoEntrada.is_open()) {
        std::cout << "No se pudo abrir el archivo estudiantes.txt." << std::endl;
        return 0;
    }

    std::ofstream archivoSalida("respaldo.txt");

    if (!archivoSalida.is_open()) {
        std::cout << "No se pudo crear el archivo respaldo.txt." << std::endl;
        archivoEntrada.close();
        return 0;
    }

    std::string linea;
    int contadorLineas = 0;

    while (std::getline(archivoEntrada, linea)) {
        archivoSalida << linea << std::endl;
        contadorLineas++;
    }

    archivoEntrada.close();
    archivoSalida.close();

    std::cout << "Copiadas " << contadorLineas
              << " lineas a \"respaldo.txt\"." << std::endl;

    return 0;
}