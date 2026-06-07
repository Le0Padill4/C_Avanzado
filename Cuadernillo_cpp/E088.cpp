#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::ofstream archivoSalida("notas.txt");

    if (!archivoSalida.is_open()) {
        std::cout << "No se pudo crear el archivo notas.txt." << std::endl;
        return 0;
    }

    std::string nombre;
    double nota;

    for (int i = 0; i < n; i++) {
        std::cin >> nombre >> nota;
        archivoSalida << nombre << " " << nota << std::endl;
    }

    archivoSalida.close();

    std::cout << "Datos guardados en \"notas.txt\"." << std::endl;

    std::ifstream archivoEntrada("notas.txt");

    if (!archivoEntrada.is_open()) {
        std::cout << "No se pudo abrir el archivo notas.txt." << std::endl;
        return 0;
    }

    double suma = 0;
    int contador = 0;

    while (archivoEntrada >> nombre >> nota) {
        suma += nota;
        contador++;
    }

    archivoEntrada.close();

    double promedio = suma / contador;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Promedio del grupo: " << promedio << std::endl;

    std::ofstream archivoAppend("notas.txt", std::ios::app);

    if (!archivoAppend.is_open()) {
        std::cout << "No se pudo abrir el archivo para guardar el promedio." << std::endl;
        return 0;
    }

    archivoAppend << "Promedio " << std::fixed << std::setprecision(2)
                  << promedio << std::endl;

    archivoAppend.close();

    std::cout << "Promedio guardado en el archivo." << std::endl;

    return 0;
}