#include <iostream>
#include <iomanip>

class Mascota {
protected:
    std::string nombre;
    double precio;

public:
    Mascota(std::string n, double p) : nombre(n), precio(p) {}

    virtual std::string tipo() const = 0;
    virtual std::string sonido() const = 0;
    virtual std::string detalle() const {
        return "";
    }

    virtual void describir() const {
        std::cout << "[" << tipo() << "] "
                  << nombre << detalle()
                  << " - $" << std::fixed << std::setprecision(2) << precio
                  << " - " << sonido()
                  << std::endl;
    }

    virtual ~Mascota() {}
};

class Perro : public Mascota {
private:
    std::string raza;

public:
    Perro(std::string n, double p, std::string r)
        : Mascota(n, p), raza(r) {}

    std::string tipo() const override {
        return "Perro";
    }

    std::string sonido() const override {
        return "Guau!";
    }

    std::string detalle() const override {
        return " (" + raza + ")";
    }
};

class Gato : public Mascota {
private:
    std::string colorOjos;

public:
    Gato(std::string n, double p, std::string c)
        : Mascota(n, p), colorOjos(c) {}

    std::string tipo() const override {
        return "Gato";
    }

    std::string sonido() const override {
        return "Miau!";
    }

    std::string detalle() const override {
        return " (ojos " + colorOjos + ")";
    }
};

class Conejo : public Mascota {
private:
    double pesoKg;

public:
    Conejo(std::string n, double p, double peso)
        : Mascota(n, p), pesoKg(peso) {}

    std::string tipo() const override {
        return "Conejo";
    }

    std::string sonido() const override {
        return "Sniff!";
    }

    std::string detalle() const override {
        return " (" + std::to_string(pesoKg) + " kg)";
    }
};

void agregarMascota(Mascota** mascotas, int& cantidad, int capacidad) {
    if (cantidad == capacidad) {
        std::cout << "No hay espacio para mas mascotas." << std::endl;
        return;
    }

    std::string tipo;
    std::string nombre;
    double precio;

    std::cout << "Tipo (perro/gato/conejo): ";
    std::cin >> tipo;

    std::cout << "Nombre: ";
    std::cin >> nombre;

    if (tipo == "perro") {
        std::string raza;

        std::cout << "Raza: ";
        std::cin >> raza;

        std::cout << "Precio: ";
        std::cin >> precio;

        mascotas[cantidad] = new Perro(nombre, precio, raza);
        cantidad++;

    } else if (tipo == "gato") {
        std::string color;

        std::cout << "Color de ojos: ";
        std::cin >> color;

        std::cout << "Precio: ";
        std::cin >> precio;

        mascotas[cantidad] = new Gato(nombre, precio, color);
        cantidad++;

    } else if (tipo == "conejo") {
        double peso;

        std::cout << "Peso kg: ";
        std::cin >> peso;

        std::cout << "Precio: ";
        std::cin >> precio;

        mascotas[cantidad] = new Conejo(nombre, precio, peso);
        cantidad++;

    } else {
        std::cout << "Tipo no reconocido." << std::endl;
    }
}

void listarMascotas(Mascota** mascotas, int cantidad) {
    if (cantidad == 0) {
        std::cout << "No hay mascotas registradas." << std::endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        mascotas[i]->describir();
    }
}

void buscarPorTipo(Mascota** mascotas, int cantidad) {
    std::string tipo;
    bool encontrado = false;

    std::cout << "Buscar tipo: ";
    std::cin >> tipo;

    for (int i = 0; i < cantidad; i++) {
        bool coincide = false;

        if (tipo == "perro" && dynamic_cast<Perro*>(mascotas[i]) != nullptr) {
            coincide = true;
        } else if (tipo == "gato" && dynamic_cast<Gato*>(mascotas[i]) != nullptr) {
            coincide = true;
        } else if (tipo == "conejo" && dynamic_cast<Conejo*>(mascotas[i]) != nullptr) {
            coincide = true;
        }

        if (coincide) {
            mascotas[i]->describir();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No hay mascotas de ese tipo." << std::endl;
    }
}

int main() {
    const int capacidad = 10;
    int cantidad = 0;
    int opcion = 0;

    Mascota** mascotas = new Mascota*[capacidad];

    while (opcion != 4) {
        std::cout << "=== TIENDA DE MASCOTAS ===" << std::endl;
        std::cout << "1. Agregar  2. Listar  3. Buscar  4. Salir" << std::endl;
        std::cout << "> ";
        std::cin >> opcion;

        if (opcion == 1) {
            agregarMascota(mascotas, cantidad, capacidad);
        } else if (opcion == 2) {
            listarMascotas(mascotas, cantidad);
        } else if (opcion == 3) {
            buscarPorTipo(mascotas, cantidad);
        } else if (opcion != 4) {
            std::cout << "Opcion invalida." << std::endl;
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < cantidad; i++) {
        delete mascotas[i];
        mascotas[i] = nullptr;
    }

    delete[] mascotas;
    mascotas = nullptr;

    std::cout << "Hasta luego. Memoria liberada." << std::endl;

    return 0;
}