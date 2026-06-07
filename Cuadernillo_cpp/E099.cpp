#include <iostream>
#include <iomanip>

class Lista {
private:
    int* datos;
    int capacidad;
    int cantidad;

public:
    Lista(int cap) {
        capacidad = cap;
        cantidad = 0;
        datos = new int[capacidad];
    }

    ~Lista() {
        delete[] datos;
        std::cout << "Destructor: memoria liberada." << std::endl;
    }

    void agregar(int val) {
        if (cantidad < capacidad) {
            datos[cantidad] = val;
            cantidad++;
        } else {
            std::cout << "Lista llena." << std::endl;
        }
    }

    void imprimir() {
        std::cout << "Lista:";

        for (int i = 0; i < cantidad; i++) {
            std::cout << " " << datos[i];
        }

        std::cout << std::endl;
    }

    double promedio() {
        if (cantidad == 0) {
            return 0;
        }

        double suma = 0;

        for (int i = 0; i < cantidad; i++) {
            suma += datos[i];
        }

        return suma / cantidad;
    }
};

int main() {
    int capacidad;
    std::cin >> capacidad;

    Lista lista(capacidad);

    int valor;

    for (int i = 0; i < capacidad; i++) {
        std::cin >> valor;
        lista.agregar(valor);
    }

    lista.imprimir();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Promedio: " << lista.promedio() << std::endl;

    return 0;
}