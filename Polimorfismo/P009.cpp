#include <iostream>
#include <iomanip>

class Vehiculo {
protected:
    std::string marca;

public:
    Vehiculo(std::string m) : marca(m) {}

    virtual void describir() const {
        std::cout << "Vehiculo marca " << marca << std::endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int puertas;

public:
    Auto(std::string m, int p) : Vehiculo(m), puertas(p) {}

    void describir() const override {
        std::cout << "Auto " << marca << " con " << puertas << " puertas" << std::endl;
    }

    void abrirMaletero() const {
        std::cout << "Maletero de " << marca << " abierto." << std::endl;
    }
};

class Camion : public Vehiculo {
private:
    double toneladas;

public:
    Camion(std::string m, double t) : Vehiculo(m), toneladas(t) {}

    void describir() const override {
        std::cout << "Camion " << marca << " de "
                  << std::fixed << std::setprecision(1)
                  << toneladas << " toneladas" << std::endl;
    }

    void cargarMercancia() const {
        std::cout << "Cargando mercancia en " << marca << "." << std::endl;
    }
};

int main() {
    Auto* autoPtr = new Auto("Toyota", 4);

    autoPtr->describir();
    autoPtr->abrirMaletero();

    Vehiculo* vehiculoPtr = autoPtr;
    vehiculoPtr->describir();

/*
Esto no compila:
        vehiculoPtr->abrirMaletero();

Mensaje de error:
error: 'class Vehiculo' has no member named 'abrirMaletero'

Al hacer upcasting se conserva lo virtual de Vehiculo, como
describir(). Lo especifico de Auto no se puede llamar desde
Vehiculo* si no esta en la interfaz de Vehiculo.
*/

    Vehiculo* vehiculos[2];

    vehiculos[0] = new Auto("Kia", 2);
    vehiculos[1] = new Camion("Volvo", 12.5);

    for (int i = 0; i < 2; i++) {
        vehiculos[i]->describir();
    }

    delete autoPtr;
    autoPtr = nullptr;
    vehiculoPtr = nullptr;

    for (int i = 0; i < 2; i++) {
        delete vehiculos[i];
        vehiculos[i] = nullptr;
    }

    return 0;
}