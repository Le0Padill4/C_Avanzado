#include <iostream>

class Empleado {
protected:
    std::string nombre;
    double salario;

public:
    Empleado(std::string n, double s) : nombre(n), salario(s) {}

    std::string getNombre() const {
        return nombre;
    }

    double getSalario() const {
        return salario;
    }

    virtual double calcularBono() const {
        return 0;
    }

    virtual void imprimir() const {
        std::cout << nombre << ": $" << salario
                  << " Bono: $" << calcularBono() << std::endl;
    }
};

class Programador : public Empleado {
private:
    std::string lenguaje;

public:
    Programador(std::string n, double s, std::string l)
        : Empleado(n, s), lenguaje(l) {}

    double calcularBono() const override {
        return salario * 0.10;
    }

    void imprimir() const override {
        std::cout << nombre << " (Programador/" << lenguaje << "): $"
                  << salario << " | Bono: $" << calcularBono() << std::endl;
    }
};

class Gerente : public Empleado {
private:
    std::string departamento;

public:
    Gerente(std::string n, double s, std::string d)
        : Empleado(n, s), departamento(d) {}

    double calcularBono() const override {
        return salario * 0.20;
    }

    void imprimir() const override {
        std::cout << nombre << " Gerente" << departamento << ": $"
                  << salario << " Bono: $" << calcularBono() << std::endl;
    }
};

class Director : public Gerente {
private:
    double presupuesto;

public:
    Director(std::string n, double s, std::string d, double p)
        : Gerente(n, s, d), presupuesto(p) {}

    double calcularBono() const override {
        return salario * 0.30;
    }

    void imprimir() const override {
        std::cout << nombre << " (Directora): $"
                  << salario << " Bono: $" << calcularBono()
                  << " Ppto: $" << presupuesto << std::endl;
    }
};

int main() {
    Programador p("Ana", 3000, "Python");
    Gerente g("Luis", 5000, "Sistemas");
    Director d("Carla", 8000, "Direccion", 500000);

    p.imprimir();
    g.imprimir();
    d.imprimir();

    return 0;
}