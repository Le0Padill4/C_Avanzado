#include <iostream>
#include <string>

class Empleado {
private:
    std::string nombre;
    double salario;
    int edad;
    std::string contrasena;

public:
    Empleado(std::string nombre, double salario, int edad, std::string contrasena) {
        this->nombre = nombre;

        if (salario >= 0) {
            this->salario = salario;
        } else {
            this->salario = 0;
        }

        if (edad >= 18 && edad <= 100) {
            this->edad = edad;
        } else {
            this->edad = 18;
        }

        if (contrasena.length() >= 6) {
            this->contrasena = contrasena;
        } else {
            this->contrasena = "123456";
        }
    }

    std::string getNombre() const {
        return nombre;
    }

    double getSalario() const {
        return salario;
    }

    int getEdad() const {
        return edad;
    }

    void setNombre(std::string nombre) {
        this->nombre = nombre;
    }

    void setSalario(double salario) {
        if (salario >= 0) {
            this->salario = salario;
        } else {
            std::cout << "Salario invalido." << std::endl;
        }
    }

    void setEdad(int edad) {
        if (edad >= 18 && edad <= 100) {
            this->edad = edad;
        } else {
            std::cout << "Edad invalida." << std::endl;
        }
    }

    void setContrasena(std::string contrasena) {
        if (contrasena.length() >= 6) {
            this->contrasena = contrasena;
        } else {
            std::cout << "Contrasena invalida." << std::endl;
        }
    }

    bool verificarContrasena(std::string intento) const {
        return intento == contrasena;
    }

    void imprimir() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Salario: $" << salario << std::endl;
    }
};

int main() {
    Empleado empleado1("Ana", 1200.0, 25, "clave123");

    empleado1.imprimir();

    empleado1.setSalario(-5000);
    empleado1.setEdad(150);
    empleado1.setContrasena("abc");

    empleado1.imprimir();

    return 0;
}