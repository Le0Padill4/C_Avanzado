#include <iostream>
#include <string>

class Empleado {
protected:
    std::string nombre;

public:
    Empleado(std::string n) : nombre(n) {}

    virtual double calcularSalarioMensual() const = 0;
    virtual double calcularImpuesto() const = 0;

    virtual void imprimir() const {
        std::cout << nombre << " Bruto: $" << calcularSalarioMensual() << " Impuesto: $" << calcularImpuesto() << " Neto: $" << calcularSalarioMensual() - calcularImpuesto()<< std::endl;
    }

    virtual ~Empleado() {}
};

class EmpleadoFijo : public Empleado {
private:
    double salario;

public:
    EmpleadoFijo(std::string n, double s) : Empleado(n), salario(s) {}

    double calcularSalarioMensual() const override {
        return salario;
    }

    double calcularImpuesto() const override {
        if (salario > 2000) {
            return salario * 0.15;
        }

        return salario * 0.10;
    }
};

class EmpleadoHora : public Empleado {
private:
    int horasSemanales;
    double tarifaHora;

public:
    EmpleadoHora(std::string n, int h, double t)
        : Empleado(n), horasSemanales(h), tarifaHora(t) {}

    double calcularSalarioMensual() const override {
        return horasSemanales * tarifaHora * 4;
    }

    double calcularImpuesto() const override {
        return calcularSalarioMensual() * 0.08;
    }
};

class EmpleadoComision : public Empleado {
private:
    double salarioBase;
    double ventas;
    double pctComision;

public:
    EmpleadoComision(std::string n, double sb, double v, double pct)
        : Empleado(n), salarioBase(sb), ventas(v), pctComision(pct) {}

    double calcularSalarioMensual() const override {
        return salarioBase + ventas * pctComision;
    }

    double calcularImpuesto() const override {
        return calcularSalarioMensual() * 0.12;
    }
};

class Nomina {
private:
    Empleado* lista[50];
    int cantidad;

public:
    Nomina() : cantidad(0) {}

    void agregar(Empleado* e) {
        if (cantidad < 50) {
            lista[cantidad] = e;
            cantidad++;
        }
    }

    double totalBruto() const {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += lista[i]->calcularSalarioMensual();
        }

        return total;
    }

    double totalImpuesto() const {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += lista[i]->calcularImpuesto();
        }

        return total;
    }

    double totalNeto() const {
        return totalBruto() - totalImpuesto();
    }

    void imprimirNomina() const {
        for (int i = 0; i < cantidad; i++) {
            lista[i]->imprimir();
        }

        std::cout << "Total bruto: $" << totalBruto() << std::endl;
        std::cout << "Total impuesto: $" << totalImpuesto() << std::endl;
        std::cout << "Total neto: $" << totalNeto() << std::endl;
    }

    ~Nomina() {
        for (int i = 0; i < cantidad; i++) {
            delete lista[i];
        }
    }
};

int main() {
    Nomina nomina;

    nomina.agregar(new EmpleadoFijo("Ana", 2500));
    nomina.agregar(new EmpleadoFijo("Luis", 1800));
    nomina.agregar(new EmpleadoHora("Pedro", 40, 12));
    nomina.agregar(new EmpleadoComision("Carla", 1000, 5000, 0.10));

    nomina.imprimirNomina();

    return 0;
}