#include <iostream>
#include <string>
#include <iomanip>

class Persona {
private:
    std::string nombre;
    std::string cedula;
    int edad;

public:
    Persona(std::string n, std::string c, int e)
        : nombre(n), cedula(c), edad(e) {}

    std::string getNombre() const {
        return nombre;
    }

    std::string getCedula() const {
        return cedula;
    }

    int getEdad() const {
        return edad;
    }

    virtual std::string getTipo() const = 0;
    virtual double calcularCostoMensual() const = 0;

    virtual void imprimir() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Cedula: " << cedula << std::endl;
        std::cout << "Edad: " << edad << std::endl;
    }

    virtual ~Persona() {}
};

class Paciente : public Persona {
protected:
    std::string codigoPaciente;
    std::string diagnostico;

public:
    Paciente(std::string n, std::string c, int e,
             std::string cod, std::string diag)
        : Persona(n, c, e), codigoPaciente(cod), diagnostico(diag) {}

    std::string getCodigoPaciente() const {
        return codigoPaciente;
    }

    std::string getDiagnostico() const {
        return diagnostico;
    }

    void imprimir() const override {
        Persona::imprimir();
        std::cout << "Codigo paciente: " << codigoPaciente << std::endl;
        std::cout << "Diagnostico: " << diagnostico << std::endl;
    }

    virtual ~Paciente() {}
};

class PacienteAmbulatorio : public Paciente {
private:
    int consultasMes;
    double costoConsulta;

public:
    PacienteAmbulatorio(std::string n, std::string c, int e,
                        std::string cod, std::string diag,
                        int consultas, double costo)
        : Paciente(n, c, e, cod, diag), consultasMes(consultas), costoConsulta(costo) {}

    std::string getTipo() const override {
        return "Paciente ambulatorio";
    }

    double calcularCostoMensual() const override {
        return consultasMes * costoConsulta;
    }

    void imprimir() const override {
        Paciente::imprimir();
        std::cout << "Tipo: " << getTipo() << std::endl;
        std::cout << "Consultas al mes: " << consultasMes << std::endl;
        std::cout << "Costo mensual: $" << calcularCostoMensual() << std::endl;
    }
};

class PacienteHospitalizado : public Paciente {
private:
    int diasInternado;
    double costoDia;

public:
    PacienteHospitalizado(std::string n, std::string c, int e,
                          std::string cod, std::string diag,
                          int dias, double costo)
        : Paciente(n, c, e, cod, diag), diasInternado(dias), costoDia(costo) {}

    std::string getTipo() const override {
        return "Paciente hospitalizado";
    }

    double calcularCostoMensual() const override {
        return diasInternado * costoDia;
    }

    void imprimir() const override {
        Paciente::imprimir();
        std::cout << "Tipo: " << getTipo() << std::endl;
        std::cout << "Dias internado: " << diasInternado << std::endl;
        std::cout << "Costo mensual: $" << calcularCostoMensual() << std::endl;
    }
};

class ProfesionalSalud : public Persona {
protected:
    std::string codigoEmpleado;
    std::string departamento;
    double salarioBase;

public:
    ProfesionalSalud(std::string n, std::string c, int e,
                     std::string cod, std::string dep, double salario)
        : Persona(n, c, e), codigoEmpleado(cod), departamento(dep), salarioBase(salario) {}

    std::string getCodigoEmpleado() const {
        return codigoEmpleado;
    }

    double getSalarioBase() const {
        return salarioBase;
    }

    virtual double calcularBono() const = 0;

    double calcularCostoMensual() const override {
        return salarioBase + calcularBono();
    }

    void imprimir() const override {
        Persona::imprimir();
        std::cout << "Codigo empleado: " << codigoEmpleado << std::endl;
        std::cout << "Departamento: " << departamento << std::endl;
        std::cout << "Salario base: $" << salarioBase << std::endl;
        std::cout << "Bono: $" << calcularBono() << std::endl;
        std::cout << "Pago mensual: $" << calcularCostoMensual() << std::endl;
    }

    virtual ~ProfesionalSalud() {}
};

class MedicoGeneral : public ProfesionalSalud {
private:
    int pacientesAtendidos;

public:
    MedicoGeneral(std::string n, std::string c, int e,
                  std::string cod, std::string dep, double salario,
                  int pacientes)
        : ProfesionalSalud(n, c, e, cod, dep, salario), pacientesAtendidos(pacientes) {}

    std::string getTipo() const override {
        return "Medico general";
    }

    double calcularBono() const override {
        return pacientesAtendidos * 5.0;
    }

    void imprimir() const override {
        ProfesionalSalud::imprimir();
        std::cout << "Tipo: " << getTipo() << std::endl;
        std::cout << "Pacientes atendidos: " << pacientesAtendidos << std::endl;
    }
};

class Especialista : public ProfesionalSalud {
protected:
    std::string especialidad;

public:
    Especialista(std::string n, std::string c, int e,
                 std::string cod, std::string dep, double salario,
                 std::string esp)
        : ProfesionalSalud(n, c, e, cod, dep, salario), especialidad(esp) {}

    std::string getEspecialidad() const {
        return especialidad;
    }

    void imprimir() const override {
        ProfesionalSalud::imprimir();
        std::cout << "Especialidad: " << especialidad << std::endl;
    }

    virtual ~Especialista() {}
};

class Cardiologo : public Especialista {
private:
    int examenesCardiacos;

public:
    Cardiologo(std::string n, std::string c, int e,
               std::string cod, std::string dep, double salario,
               int examenes)
        : Especialista(n, c, e, cod, dep, salario, "Cardiologia"),
          examenesCardiacos(examenes) {}

    std::string getTipo() const override {
        return "Cardiologo";
    }

    double calcularBono() const override {
        return salarioBase * 0.15 + examenesCardiacos * 10.0;
    }

    void imprimir() const override {
        Especialista::imprimir();
        std::cout << "Tipo: " << getTipo() << std::endl;
        std::cout << "Examenes cardiacos: " << examenesCardiacos << std::endl;
    }
};

class Pediatra : public Especialista {
private:
    int controlesNinos;

public:
    Pediatra(std::string n, std::string c, int e,
             std::string cod, std::string dep, double salario,
             int controles)
        : Especialista(n, c, e, cod, dep, salario, "Pediatria"),
          controlesNinos(controles) {}

    std::string getTipo() const override {
        return "Pediatra";
    }

    double calcularBono() const override {
        return salarioBase * 0.12 + controlesNinos * 4.0;
    }

    void imprimir() const override {
        Especialista::imprimir();
        std::cout << "Tipo: " << getTipo() << std::endl;
        std::cout << "Controles de ninos: " << controlesNinos << std::endl;
    }
};

class Cirujano : public Especialista {
private:
    int cirugiasRealizadas;

public:
    Cirujano(std::string n, std::string c, int e,
             std::string cod, std::string dep, double salario,
             int cirugias)
        : Especialista(n, c, e, cod, dep, salario, "Cirugia"),
          cirugiasRealizadas(cirugias) {}

    std::string getTipo() const override {
        return "Cirujano";
    }

    double calcularBono() const override {
        return salarioBase * 0.20 + cirugiasRealizadas * 50.0;
    }

    void imprimir() const override {
        Especialista::imprimir();
        std::cout << "Tipo: " << getTipo() << std::endl;
        std::cout << "Cirugias realizadas: " << cirugiasRealizadas << std::endl;
    }
};

class Hospital {
private:
    std::string nombre;
    Persona* personas[600];
    int numPersonas;

public:
    Hospital(std::string n)
        : nombre(n), numPersonas(0) {}

    std::string getNombre() const {
        return nombre;
    }

    void agregarPersona(Persona* p) {
        if (numPersonas < 600) {
            personas[numPersonas] = p;
            numPersonas++;
        } else {
            std::cout << "No hay espacio para mas personas." << std::endl;
        }
    }

    void listarPersonas() const {
        std::cout << "\n=== LISTA GENERAL DEL HOSPITAL ===" << std::endl;

        for (int i = 0; i < numPersonas; i++) {
            personas[i]->imprimir();
            std::cout << "-----------------------------" << std::endl;
        }
    }

    void listarCostosMensuales() const {
        std::cout << "\n=== COSTOS MENSUALES ===" << std::endl;

        for (int i = 0; i < numPersonas; i++) {
            std::cout << personas[i]->getNombre()
                      << " | " << personas[i]->getTipo()
                      << " | $" << personas[i]->calcularCostoMensual()
                      << std::endl;
        }
    }

    double calcularTotalMensual() const {
        double total = 0;

        for (int i = 0; i < numPersonas; i++) {
            total += personas[i]->calcularCostoMensual();
        }

        return total;
    }

    ~Hospital() {
        for (int i = 0; i < numPersonas; i++) {
            delete personas[i];
        }
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Hospital hospital("Hospital Central");

    hospital.agregarPersona(new PacienteAmbulatorio(
        "Luis Perez", "0102030405", 25,
        "P001", "Gripe fuerte", 3, 25.0
    ));

    hospital.agregarPersona(new PacienteHospitalizado(
        "Maria Lopez", "0203040506", 40,
        "P002", "Fractura", 7, 90.0
    ));

    hospital.agregarPersona(new MedicoGeneral(
        "Carlos Ruiz", "0304050607", 45,
        "M001", "Consulta externa", 1200.0, 80
    ));

    hospital.agregarPersona(new Cardiologo(
        "Ana Torres", "0405060708", 50,
        "M002", "Cardiologia", 2200.0, 12
    ));

    hospital.agregarPersona(new Pediatra(
        "Sofia Mena", "0506070809", 38,
        "M003", "Pediatria", 1800.0, 50
    ));

    hospital.agregarPersona(new Cirujano(
        "Pedro Salazar", "0607080910", 55,
        "M004", "Quirofano", 3000.0, 8
    ));

    hospital.listarPersonas();

    hospital.listarCostosMensuales();

    std::cout << "\nTotal mensual del hospital: $"
              << hospital.calcularTotalMensual() << std::endl;

    return 0;
}