#include <iostream>
#include <iomanip>
#include <string>

class Estudiante {
public:
    std::string nombre;
    double nota;

    void imprimir() {
        std::cout << nombre << ": "
                  << std::fixed << std::setprecision(2)
                  << nota << std::endl;
    }

    bool aprobo() {
        return nota >= 60.0;
    }
};

int main() {
    Estudiante estudiantes[4];

    estudiantes[0].nombre = "Ana";
    estudiantes[0].nota = 85.0;

    estudiantes[1].nombre = "Luis";
    estudiantes[1].nota = 45.0;

    estudiantes[2].nombre = "Carla";
    estudiantes[2].nota = 92.0;

    estudiantes[3].nombre = "Pedro";
    estudiantes[3].nota = 58.0;

    std::cout << "=== Aprobados ===" << std::endl;

    for (int i = 0; i < 4; i++) {
        if (estudiantes[i].aprobo()) {
            estudiantes[i].imprimir();
        }
    }

    std::cout << "=== Reprobados ===" << std::endl;

    for (int i = 0; i < 4; i++) {
        if (!estudiantes[i].aprobo()) {
            estudiantes[i].imprimir();
        }
    }

    return 0;
}