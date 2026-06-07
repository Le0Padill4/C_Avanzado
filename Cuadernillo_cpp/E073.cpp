#include <iostream>

int main() {
    int* a = new int(5);
    int* b = new int[10];

    // Antes de asignar una nueva memoria a "a",
    // debemos liberar la memoria anterior.
    // Si no hacemos esto, se pierde la direccion del valor 5.
    delete a;

    // Ahora "a" puede apuntar a una nueva memoria sin causar leak.
    a = new int(20);

    std::cout << "Valor final de a: " << *a << std::endl;

    // Liberamos la memoria dinamica usada.
    delete a;
    delete[] b;

    // Buena practica: dejar los punteros en nullptr.
    a = nullptr;
    b = nullptr;

    std::cout << "Memoria liberada correctamente." << std::endl;

    return 0;
}