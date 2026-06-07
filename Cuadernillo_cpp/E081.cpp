#include <iostream>
#include <fstream>

int main() {
    std::ofstream archivo("saludo.txt");

    if (archivo.is_open()) {
        archivo << "Linea 1: Hola desde C++" << std::endl;
        archivo << "Linea 2: Aprendiendo archivos" << std::endl;
        archivo << "Linea 3: fstream es poderoso" << std::endl;

        archivo.close();

        std::cout << "Archivo \"saludo.txt\" creado." << std::endl;
        std::cout << "3 lineas escritas." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo." << std::endl;
    }

    return 0;
}