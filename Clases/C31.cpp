#include <iostream>

class Persona{
protected:
    std::string nombre;
    int edad;

public:
    Persona(std::string n, int e) : nombre(n), edad(e) {}

    virtual void imprimir() const {
        std::cout << nombre << edad << "años" << std::endl;
    }
};

class Empleado : public Persona {
private:
    std::string empresa;
    double salario;
public:
    Empleado(std::string n, int e, std::string emp, double sal) : Persona(n, e), empresa(emp), salario(sal) {}
    void imprimir() const override{
        std::cout << nombre << edad << " años" << "Empresa: " << empresa << "Salario: " << salario << std::endl;
    }
};

class Estudiante : public Persona {
private:
    std::string carrera;
    int semestre;

public:
    Estudiante(std::string n, int e, std::string c, int s)
        : Persona(n, e), carrera(c), semestre(s) {}

    void imprimir() const override {
        std::cout << nombre << edad << " años" << "Carrera: " << carrera << "Semestre: " << semestre << std::endl;
    }
};

int main() {
    Empleado empleado1("Ana Torres", 28, "USFQ", 2500.00);
    Estudiante estudiante1("Luis Mora", 20, "Computacion", 4);

    empleado1.imprimir();
    estudiante1.imprimir();

    return 0;
}