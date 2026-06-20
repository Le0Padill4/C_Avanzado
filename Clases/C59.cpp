#include <iostream>
#include <string>
#include <iomanip>

class Persona {
protected:
    std::string nombre;
    std::string cedula;
    std::string email;
    std::string telefono;

public:
    Persona(std::string n, std::string c, std::string e, std::string t)
        : nombre(n), cedula(c), email(e), telefono(t) {}

    std::string getNombre() const {
        return nombre;
    }

    std::string getCedula() const {
        return cedula;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getTelefono() const {
        return telefono;
    }

    virtual void imprimir() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Cedula: " << cedula << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Telefono: " << telefono << std::endl;
    }

    virtual ~Persona() {}
};

class Estudiante : public Persona {
private:
    std::string matricula;
    std::string carrera;
    int semestre;
    double notas[10];
    int numNotas;

public:
    Estudiante(std::string n, std::string c, std::string e, std::string t,
               std::string m, std::string car, int sem)
        : Persona(n, c, e, t), matricula(m), carrera(car), semestre(sem), numNotas(0) {}

    void agregarNota(double n) {
        if (n < 0 or n > 100) {
            std::cout << "Nota invalida." << std::endl;
            return;
        }

        if (numNotas < 10) {
            notas[numNotas] = n;
            numNotas++;
        } else {
            std::cout << "No se pueden agregar mas notas." << std::endl;
        }
    }

    double calcularPromedio() const {
        if (numNotas == 0) {
            return 0;
        }

        double suma = 0;

        for (int i = 0; i < numNotas; i++) {
            suma += notas[i];
        }

        return suma / numNotas;
    }

    bool estaEnRiesgo() const {
        return calcularPromedio() < 70;
    }

    void imprimir() const override {
        Persona::imprimir();
        std::cout << "Matricula: " << matricula << std::endl;
        std::cout << "Carrera: " << carrera << std::endl;
        std::cout << "Semestre: " << semestre << std::endl;
        std::cout << "Promedio: " << calcularPromedio() << std::endl;
        std::cout << "Estado: ";

        if (estaEnRiesgo()) {
            std::cout << "En riesgo" << std::endl;
        } else {
            std::cout << "Estable" << std::endl;
        }
    }
};

class Profesor : public Persona {
protected:
    std::string titulo;
    std::string departamento;
    double salario;
    std::string materias[5];
    int numMaterias;

public:
    Profesor(std::string n, std::string c, std::string e, std::string t,
             std::string tit, std::string dep, double sal)
        : Persona(n, c, e, t), titulo(tit), departamento(dep), salario(sal), numMaterias(0) {}

    void agregarMateria(std::string m) {
        if (numMaterias < 5) {
            materias[numMaterias] = m;
            numMaterias++;
        } else {
            std::cout << "No se pueden agregar mas materias." << std::endl;
        }
    }

    virtual double calcularBono() const {
        return 0;
    }

    double getSalario() const {
        return salario;
    }

    void imprimir() const override {
        Persona::imprimir();
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Departamento: " << departamento << std::endl;
        std::cout << "Salario: $" << salario << std::endl;
        std::cout << "Bono: $" << calcularBono() << std::endl;

        std::cout << "Materias: ";
        for (int i = 0; i < numMaterias; i++) {
            std::cout << materias[i];
            if (i < numMaterias - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

class ProfesorTitular : public Profesor {
public:
    ProfesorTitular(std::string n, std::string c, std::string e, std::string t,
                    std::string tit, std::string dep, double sal)
        : Profesor(n, c, e, t, tit, dep, sal) {}

    double calcularBono() const override {
        return salario * 0.15;
    }
};

class ProfesorContratado : public Profesor {
public:
    ProfesorContratado(std::string n, std::string c, std::string e, std::string t,
                       std::string tit, std::string dep, double sal)
        : Profesor(n, c, e, t, tit, dep, sal) {}

    double calcularBono() const override {
        return salario * 0.05;
    }
};

class Universidad {
private:
    Estudiante* estudiantes[500];
    Profesor* profesores[100];
    int numEstudiantes;
    int numProfesores;

public:
    Universidad() : numEstudiantes(0), numProfesores(0) {}

    void matricularEstudiante(Estudiante* e) {
        if (numEstudiantes < 500) {
            estudiantes[numEstudiantes] = e;
            numEstudiantes++;
        } else {
            std::cout << "No hay cupo para mas estudiantes." << std::endl;
        }
    }

    void contratarProfesor(Profesor* p) {
        if (numProfesores < 100) {
            profesores[numProfesores] = p;
            numProfesores++;
        } else {
            std::cout << "No hay cupo para mas profesores." << std::endl;
        }
    }

    void listarEstudiantesRiesgo() const {
        std::cout << "\n--- Estudiantes en riesgo ---" << std::endl;

        for (int i = 0; i < numEstudiantes; i++) {
            if (estudiantes[i]->estaEnRiesgo()) {
                estudiantes[i]->imprimir();
                std::cout << std::endl;
            }
        }
    }

    void listarProfesoresBono() const {
        std::cout << "\n--- Profesores y bonos ---" << std::endl;

        for (int i = 0; i < numProfesores; i++) {
            profesores[i]->imprimir();
            std::cout << std::endl;
        }
    }

    double presupuestoNomina() const {
        double total = 0;

        for (int i = 0; i < numProfesores; i++) {
            total += profesores[i]->getSalario() + profesores[i]->calcularBono();
        }

        return total;
    }

    ~Universidad() {
        for (int i = 0; i < numEstudiantes; i++) {
            delete estudiantes[i];
        }

        for (int i = 0; i < numProfesores; i++) {
            delete profesores[i];
        }
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Universidad universidad;

    Estudiante* e1 = new Estudiante("Juan Perez", "0102030405", "juan@email.com", "099111222", "MAT001", "Sistemas", 3);
    e1->agregarNota(85);
    e1->agregarNota(90);
    e1->agregarNota(78);

    Estudiante* e2 = new Estudiante("Maria Lopez", "0203040506", "maria@email.com", "098333444", "MAT002", "Medicina", 2);
    e2->agregarNota(60);
    e2->agregarNota(65);
    e2->agregarNota(68);

    Profesor* p1 = new ProfesorTitular("Carlos Ruiz", "0304050607", "carlos@email.com", "097555666", "PhD", "Ingenieria", 2000);
    p1->agregarMateria("Programacion");
    p1->agregarMateria("Estructuras de Datos");

    Profesor* p2 = new ProfesorContratado("Ana Torres", "0405060708", "ana@email.com", "096777888", "Magister", "Matematicas", 1200);
    p2->agregarMateria("Calculo I");
    p2->agregarMateria("Algebra Lineal");

    universidad.matricularEstudiante(e1);
    universidad.matricularEstudiante(e2);

    universidad.contratarProfesor(p1);
    universidad.contratarProfesor(p2);

    universidad.listarEstudiantesRiesgo();
    universidad.listarProfesoresBono();

    std::cout << "Presupuesto total de nomina: $"
              << universidad.presupuestoNomina() << std::endl;

    return 0;
}