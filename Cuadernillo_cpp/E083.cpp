#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string oracion;

    std::getline(std::cin, oracion);

    std::ofstream archivo("registro.txt", std::ios::app);

    if (archivo.is_open()) {
        archivo << oracion << std::endl;

        archivo.close();

        std::cout << "Linea agregada a \"registro.txt\"." << std::endl;
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    return 0;
}