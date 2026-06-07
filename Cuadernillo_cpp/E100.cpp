#include <iostream>
#include <string>
#include <iomanip>

class Empleado {
protected:
    std::string nombre;
    double salario;

public:
    Empleado(std::string n, double s) {
        nombre = n;
        salario = s;
    }

    virtual double calcularBono() = 0;

    virtual void imprimir() = 0;

    virtual ~Empleado() {
    }
};

class Programador : public Empleado {
private:
    std::string lenguaje;

public:
    Programador(std::string n, double s, std::string l)
        : Empleado(n, s) {
        lenguaje = l;
    }

    double calcularBono() override {
        return salario * 0.10;
    }

    void imprimir() override {
        std::cout << nombre << " (Programador/" << lenguaje << "): "
                  << "Salario=$" << salario
                  << ", Bono=$" << calcularBono()
                  << std::endl;
    }
};

class Gerente : public Empleado {
private:
    std::string departamento;

public:
    Gerente(std::string n, double s, std::string d)
        : Empleado(n, s) {
        departamento = d;
    }

    double calcularBono() override {
        return salario * 0.20;
    }

    void imprimir() override {
        std::cout << nombre << " (Gerente/" << departamento << "): "
                  << "Salario=$" << salario
                  << ", Bono=$" << calcularBono()
                  << std::endl;
    }
};

int main() {
    Empleado* equipo[3];

    equipo[0] = new Programador("Ana", 3000, "Python");
    equipo[1] = new Gerente("Luis", 5000, "Sistemas");
    equipo[2] = new Programador("Carla", 2800, "C++");

    double totalBonos = 0;

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < 3; i++) {
        equipo[i]->imprimir();
        totalBonos += equipo[i]->calcularBono();
    }

    std::cout << "─────────────────────────────" << std::endl;
    std::cout << "Total bonos a pagar: $" << totalBonos << std::endl;

    for (int i = 0; i < 3; i++) {
        delete equipo[i];
    }

    return 0;
}