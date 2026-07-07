#include <iostream>
#include <iomanip>

class Empleado {
protected:
    std::string nombre;
    double salario;

public:
    Empleado(std::string n, double s) : nombre(n), salario(s) {}

    std::string getNombre() const {
        return nombre;
    }

    virtual std::string tipo() const = 0;
    virtual double calcularPago() const = 0;

    virtual ~Empleado() {}
};

class EmpleadoTC : public Empleado {
public:
    EmpleadoTC(std::string n, double s) : Empleado(n, s) {}

    std::string tipo() const override {
        return "TC";
    }

    double calcularPago() const override {
        return salario;
    }
};

class EmpleadoFL : public Empleado {
private:
    double horas;
    double tarifa;

public:
    EmpleadoFL(std::string n, double h, double t)
        : Empleado(n, 0), horas(h), tarifa(t) {}

    std::string tipo() const override {
        return "FL";
    }

    double calcularPago() const override {
        return horas * tarifa;
    }
};

void mostrarPago(Empleado* e) {
    std::cout << e -> getNombre() << " [" << e -> tipo() << "]: $" << std::fixed << std::setprecision(2)
    << e->calcularPago() << std::endl;
}

int main() {
    Empleado* e1 = new EmpleadoTC("Ana", 3500.0);
    Empleado* e2 = new EmpleadoFL("Luis", 80.0, 15.0);

    mostrarPago(e1);
    mostrarPago(e2);

    delete e1;
    delete e2;

    return 0;
}