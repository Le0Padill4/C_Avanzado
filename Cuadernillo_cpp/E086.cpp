#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream archivoEntrada("estudiantes.txt");

    if (!archivoEntrada.is_open()) {
        std::cout << "No se pudo abrir el archivo estudiantes.txt." << std::endl;
        return 0;
    }

    std::string nombreBuscado;
    std::string nombre;
    double nota;
    int encontrado = 0;

    std::cin >> nombreBuscado;

    while (archivoEntrada >> nombre >> nota) {
        if (nombre == nombreBuscado) {
            std::cout << "Estudiante encontrado: "
                      << nombre << " - "
                      << std::fixed << std::setprecision(2)
                      << nota << std::endl;

            encontrado = 1;
        }
    }

    archivoEntrada.close();

    if (encontrado == 0) {
        std::cout << "Estudiante no encontrado." << std::endl;
    }

    return 0;
}