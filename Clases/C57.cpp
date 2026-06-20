#include <iostream>

class Transporte {
protected:
    std::string origen;
    std::string destino;
    int capacidadPasajeros;

public:
    Transporte(std::string o, std::string d, int c)
        : origen(o), destino(d), capacidadPasajeros(c) {}

    virtual double calcularTarifa(double distanciaKm) const = 0;
    virtual double tiempoEstimado(double distanciaKm) const = 0;
    virtual std::string getTipo() const = 0;

    virtual void imprimir() const {
        std::cout << getTipo()
                  << " | " << origen << " a " << destino
                  << " | Capacidad: " << capacidadPasajeros
                  << std::endl;
    }

    virtual ~Transporte() {}
};

class TransporteTerrestre : public Transporte {
protected:
    double velocidadPromedio;
    double costoPorKm;

public:
    TransporteTerrestre(std::string o, std::string d, int c, double v, double costo)
        : Transporte(o, d, c), velocidadPromedio(v), costoPorKm(costo) {}
};

class TransporteAereo : public Transporte {
protected:
    double costoBase;
    double tasaAeropuerto;

public:
    TransporteAereo(std::string o, std::string d, int c, double base, double tasa)
        : Transporte(o, d, c), costoBase(base), tasaAeropuerto(tasa) {}
};

class Bus : public TransporteTerrestre {
public:
    Bus(std::string o, std::string d)
        : TransporteTerrestre(o, d, 40, 80, 0.20) {}

    std::string getTipo() const override {
        return "Bus";
    }

    double calcularTarifa(double distanciaKm) const override {
        return distanciaKm * costoPorKm;
    }

    double tiempoEstimado(double distanciaKm) const override {
        return distanciaKm / velocidadPromedio;
    }
};

class Taxi : public TransporteTerrestre {
public:
    Taxi(std::string o, std::string d)
        : TransporteTerrestre(o, d, 4, 60, 0.80) {}

    std::string getTipo() const override {
        return "Taxi";
    }

    double calcularTarifa(double distanciaKm) const override {
        return 3 + distanciaKm * costoPorKm;
    }

    double tiempoEstimado(double distanciaKm) const override {
        return distanciaKm / velocidadPromedio;
    }
};

class Avion : public TransporteAereo {
public:
    Avion(std::string o, std::string d)
        : TransporteAereo(o, d, 180, 100, 40) {}

    std::string getTipo() const override {
        return "Avion";
    }

    double calcularTarifa(double distanciaKm) const override {
        return costoBase + tasaAeropuerto + distanciaKm * 0.25;
    }

    double tiempoEstimado(double distanciaKm) const override {
        return distanciaKm / 700;
    }
};

class Helicoptero : public TransporteAereo {
public:
    Helicoptero(std::string o, std::string d)
        : TransporteAereo(o, d, 6, 300, 50) {}

    std::string getTipo() const override {
        return "Helicoptero";
    }

    double calcularTarifa(double distanciaKm) const override {
        return costoBase + tasaAeropuerto + distanciaKm * 5;
    }

    double tiempoEstimado(double distanciaKm) const override {
        return distanciaKm / 200;
    }
};

class Reserva {
private:
    Transporte* transporte;
    std::string pasajero;
    std::string fecha;
    double distancia;

public:
    Reserva(Transporte* t, std::string p, std::string f, double d)
        : transporte(t), pasajero(p), fecha(f), distancia(d) {}

    double calcularCosto() const {
        return transporte->calcularTarifa(distancia);
    }

    void imprimir() const {
        std::cout << "Pasajero: " << pasajero
                  << " | Fecha: " << fecha
                  << " | Distancia: " << distancia << " km"
                  << " | Costo: $" << calcularCosto()
                  << " | Tiempo: " << transporte->tiempoEstimado(distancia) << " horas"
                  << std::endl;

        transporte->imprimir();
    }

    ~Reserva() {
        delete transporte;
    }
};

class GestorReservas {
private:
    Reserva* reservas[50];
    int cantidad;

public:
    GestorReservas() : cantidad(0) {}

    void agregar(Reserva* r) {
        if (cantidad < 50) {
            reservas[cantidad] = r;
            cantidad++;
        }
    }

    void listar() const {
        for (int i = 0; i < cantidad; i++) {
            reservas[i]->imprimir();
        }
    }

    double totalVentas() const {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += reservas[i]->calcularCosto();
        }

        return total;
    }

    ~GestorReservas() {
        for (int i = 0; i < cantidad; i++) {
            delete reservas[i];
        }
    }
};

int main() {
    GestorReservas gestor;

    gestor.agregar(new Reserva(new Bus("Quito", "Ambato"), "Ana", "20/06/2026", 140));
    gestor.agregar(new Reserva(new Taxi("Quito", "Cumbaya"), "Luis", "20/06/2026", 18));
    gestor.agregar(new Reserva(new Avion("Quito", "Guayaquil"), "Carla", "21/06/2026", 420));
    gestor.agregar(new Reserva(new Helicoptero("Quito", "Mindo"), "Pedro", "22/06/2026", 90));

    gestor.listar();

    std::cout << "Total ventas: $" << gestor.totalVentas() << std::endl;

    return 0;
}