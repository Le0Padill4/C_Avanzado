#include <iostream>
#include <string>
#include <iomanip>

struct Estudiante {
    std::string nombre;
    double nota;
    int edad;
};

void imprimir(const Estudiante* e) {
    std::cout << "Nombre: " << e->nombre << " Nota: " << std::fixed << std::setprecision(2) << e->nota << " Edad: " << e->edad << std::endl;
}

void actualizarNota(Estudiante* e, double nuevaNota) {
    if (nuevaNota >= 0 && nuevaNota <= 100) {
        e->nota = nuevaNota;
    }
}

bool aprobo(const Estudiante* e) {
    return e->nota >= 60;
}

int main() {
    Estudiante estudiante = {"Ana", 75.00, 20};

    imprimir(&estudiante);

    actualizarNota(&estudiante, 85.00);

    std::cout << "Nota actualizada: " << std::fixed << std::setprecision(2) << estudiante.nota << std::endl;

    if (aprobo(&estudiante)) {
        std::cout << "Estado: APROBADO" << std::endl;
    } else {
        std::cout << "Estado: REPROBADO" << std::endl;
    }

    return 0;
}