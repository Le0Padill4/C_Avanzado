#include <iostream>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    double precioBase;

public:
    Vehiculo(std::string ma, std::string mo, int a, double p)
        : marca(ma), modelo(mo), anio(a), precioBase(p) {}

    std::string getMarca() const {
        return marca;
    }

    std::string getModelo() const {
        return modelo;
    }

    int getAnio() const {
        return anio;
    }

    virtual double calcularCosto() const = 0;
    virtual std::string getTipo() const = 0;

    void imprimir() const {
        std::cout << marca << " " << modelo
                  << " | " << anio
                  << " | " << getTipo()
                  << " | Costo: $" << calcularCosto()
                  << std::endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
public:
    Auto(std::string ma, std::string mo, int a, double p)
        : Vehiculo(ma, mo, a, p) {}

    double calcularCosto() const override {
        if (anio > 2020) {
            return precioBase + precioBase * 0.10;
        }

        return precioBase;
    }

    std::string getTipo() const override {
        return "Auto";
    }
};

class Moto : public Vehiculo {
public:
    Moto(std::string ma, std::string mo, int a, double p)
        : Vehiculo(ma, mo, a, p) {}

    double calcularCosto() const override {
        return precioBase * 0.7;
    }

    std::string getTipo() const override {
        return "Moto";
    }
};

class Camion : public Vehiculo {
public:
    Camion(std::string ma, std::string mo, int a, double p)
        : Vehiculo(ma, mo, a, p) {}

    double calcularCosto() const override {
        return precioBase * 2.5;
    }

    std::string getTipo() const override {
        return "Camion";
    }
};

int main() {
    Vehiculo* vehiculos[6];

    vehiculos[0] = new Auto("Toyota", "Corolla", 2022, 20000);
    vehiculos[1] = new Moto("Yamaha", "FZ", 2021, 5000);
    vehiculos[2] = new Camion("Volvo", "FH", 2019, 40000);
    vehiculos[3] = new Auto("Kia", "Rio", 2018, 15000);
    vehiculos[4] = new Moto("Honda", "CBR", 2023, 8000);
    vehiculos[5] = new Camion("Mercedes", "Actros", 2022, 60000);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (vehiculos[j]->calcularCosto() < vehiculos[j + 1]->calcularCosto()) {
                Vehiculo* aux = vehiculos[j];
                vehiculos[j] = vehiculos[j + 1];
                vehiculos[j + 1] = aux;
            }
        }
    }

    double total = 0;

    for (int i = 0; i < 6; i++) {
        vehiculos[i]->imprimir();
        total += vehiculos[i]->calcularCosto();
    }

    std::cout << "Costo total de flota: $" << total << std::endl;

    for (int i = 0; i < 6; i++) {
        delete vehiculos[i];
    }

    return 0;
}