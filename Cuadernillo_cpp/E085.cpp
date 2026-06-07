#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::ofstream archivoSalida("estudiantes.txt");

    if (archivoSalida.is_open()) {
        std::string nombre;
        double nota;

        for (int i = 0; i < n; i++) {
            std::cin >> nombre >> nota;
            archivoSalida << nombre << " " << nota << std::endl;
        }

        archivoSalida.close();

        std::cout << "Guardados " << n << " registros en \"estudiantes.txt\"." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo." << std::endl;
        return 0;
    }

    std::ifstream archivoEntrada("estudiantes.txt");

    if (archivoEntrada.is_open()) {
        std::string nombre;
        double nota;

        std::cout << "Leyendo archivo:" << std::endl;

        while (archivoEntrada >> nombre >> nota) {
            std::cout << nombre << " - "
                      << std::fixed << std::setprecision(2)
                      << nota << std::endl;
        }

        archivoEntrada.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 0;
    }

    return 0;
}