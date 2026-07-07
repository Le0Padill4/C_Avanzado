#include <iostream>

class Empleado {
protected:
    std::string nombre;

public:
    Empleado(std::string n) : nombre(n) {}

    virtual void trabajar() const {
        std::cout << nombre << " trabaja." << std::endl;
    }

    virtual ~Empleado() {}
};

class Programador : public Empleado {
private:
    std::string lenguaje;

public:
    Programador(std::string n, std::string l) : Empleado(n), lenguaje(l) {}

    void trabajar() const override {
        std::cout << nombre << " programa." << std::endl;
    }

    void escribirCodigo() const {
        std::cout << nombre << " escribe codigo en " << lenguaje << std::endl;
    }
};

class Disenador : public Empleado {
private:
    std::string herramienta;

public:
    Disenador(std::string n, std::string h) : Empleado(n), herramienta(h) {}

    void trabajar() const override {
        std::cout << nombre << " disena." << std::endl;
    }

    void crearMockup() const {
        std::cout << nombre << " crea mockup en " << herramienta << std::endl;
    }
};

class Gerente : public Empleado {
private:
    std::string departamento;

public:
    Gerente(std::string n, std::string d) : Empleado(n), departamento(d) {}
};

void asignarTarea(Empleado* e) {
    Programador* p = dynamic_cast<Programador*>(e);

    if (p != nullptr) {
        p->escribirCodigo();
        return;
    }

    Disenador* d = dynamic_cast<Disenador*>(e);

    if (d != nullptr) {
        d->crearMockup();
        return;
    }

    std::cout << "Tarea generica." << std::endl;
}

int main() {
    Empleado* equipo[3];

    equipo[0] = new Programador("Ana", "C++");
    equipo[1] = new Disenador("Luis", "Figma");
    equipo[2] = new Gerente("Marta", "Ventas");

    for (int i = 0; i < 3; i++) {
        asignarTarea(equipo[i]);
    }

    for (int i = 0; i < 3; i++) {
        delete equipo[i];
        equipo[i] = nullptr;
    }

    return 0;
}