#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream archivoSalida("texto.txt");

    if (archivoSalida.is_open()) {
        archivoSalida << "La programacion es el arte de resolver problemas" << std::endl;
        archivoSalida << "C++ es un lenguaje potente y rapido" << std::endl;
        archivoSalida << "Aprender a programar abre muchas puertas" << std::endl;

        archivoSalida.close();
    } else {
        std::cout << "No se pudo crear el archivo." << std::endl;
        return 0;
    }

    std::ifstream archivoLineas("texto.txt");

    int lineas = 0;
    std::string linea;

    if (archivoLineas.is_open()) {
        while (std::getline(archivoLineas, linea)) {
            lineas++;
        }

        archivoLineas.close();
    } else {
        std::cout << "No se pudo abrir el archivo para contar lineas." << std::endl;
        return 0;
    }

    std::ifstream archivoPalabras("texto.txt");

    int palabras = 0;
    std::string palabra;

    if (archivoPalabras.is_open()) {
        while (archivoPalabras >> palabra) {
            palabras++;
        }

        archivoPalabras.close();
    } else {
        std::cout << "No se pudo abrir el archivo para contar palabras." << std::endl;
        return 0;
    }

    std::cout << "Lineas: " << lineas << std::endl;
    std::cout << "Palabras: " << palabras << std::endl;

    return 0;
}