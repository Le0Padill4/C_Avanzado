#include <iostream>
#include <string>

class Producto {
private:
    std::string codigo;
    std::string nombre;
    double precio;

public:
    Producto(std::string c, std::string n, double p)
        : codigo(c), nombre(n), precio(p) {}

    std::string getCodigo() const {
        return codigo;
    }

    std::string getNombre() const {
        return nombre;
    }

    double getPrecio() const {
        return precio;
    }

    void setPrecio(double p) {
        if (p >= 0) {
            precio = p;
        }
    }

    virtual std::string getCategoria() const = 0;
    virtual double calcularPrecioFinal() const = 0;

    virtual void imprimir() const {
        std::cout << codigo << " | " << nombre
                  << " | " << getCategoria()
                  << " | Precio final: $" << calcularPrecioFinal()
                  << std::endl;
    }

    virtual ~Producto() {}
};

class ProductoFisico : public Producto {
private:
    double peso;
    std::string dimensiones;

public:
    ProductoFisico(std::string c, std::string n, double p, double pe, std::string d)
        : Producto(c, n, p), peso(pe), dimensiones(d) {}

    std::string getCategoria() const override {
        return "Fisico";
    }

    double calcularPrecioFinal() const override {
        return getPrecio() + peso * 2;
    }
};

class ProductoDigital : public Producto {
private:
    double tamanoMB;
    std::string plataforma;

public:
    ProductoDigital(std::string c, std::string n, double p, double t, std::string pl)
        : Producto(c, n, p), tamanoMB(t), plataforma(pl) {}

    std::string getCategoria() const override {
        return "Digital";
    }

    double calcularPrecioFinal() const override {
        return getPrecio() * 0.85;
    }
};

class ProductoSuscripcion : public Producto {
private:
    int periodoMeses;
    bool renovacionAutomatica;

public:
    ProductoSuscripcion(std::string c, std::string n, double p, int meses, bool r)
        : Producto(c, n, p), periodoMeses(meses), renovacionAutomatica(r) {}

    std::string getCategoria() const override {
        return "Suscripcion";
    }

    double calcularPrecioFinal() const override {
        return getPrecio() * periodoMeses;
    }
};

class Inventario {
private:
    Producto* productos[100];
    int cantidad;

public:
    Inventario() : cantidad(0) {}

    void agregar(Producto* p) {
        if (cantidad < 100) {
            productos[cantidad] = p;
            cantidad++;
        }
    }

    void listar() const {
        for (int i = 0; i < cantidad; i++) {
            productos[i]->imprimir();
        }
    }

    Producto* buscar(std::string codigo) const {
        for (int i = 0; i < cantidad; i++) {
            if (productos[i]->getCodigo() == codigo) {
                return productos[i];
            }
        }

        return nullptr;
    }

    void actualizarPrecio(std::string codigo, double nuevoPrecio) {
        Producto* p = buscar(codigo);

        if (p != nullptr) {
            p->setPrecio(nuevoPrecio);
        } else {
            std::cout << "Producto no encontrado." << std::endl;
        }
    }

    void eliminar(std::string codigo) {
        for (int i = 0; i < cantidad; i++) {
            if (productos[i]->getCodigo() == codigo) {
                delete productos[i];

                for (int j = i; j < cantidad - 1; j++) {
                    productos[j] = productos[j + 1];
                }

                cantidad--;
                return;
            }
        }

        std::cout << "Producto no encontrado." << std::endl;
    }

    double valorTotal() const {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += productos[i]->calcularPrecioFinal();
        }

        return total;
    }

    ~Inventario() {
        for (int i = 0; i < cantidad; i++) {
            delete productos[i];
        }
    }
};

int main() {
    Inventario inv;

    inv.agregar(new ProductoFisico("F001", "Laptop", 800, 3, "30x20"));
    inv.agregar(new ProductoDigital("D001", "Curso C++", 100, 500, "Web"));
    inv.agregar(new ProductoSuscripcion("S001", "Netflix", 12, 6, true));

    std::cout << "Inventario:" << std::endl;
    inv.listar();

    std::cout << "Valor total: $" << inv.valorTotal() << std::endl;

    std::cout << std::endl << "Buscar producto D001:" << std::endl;
    Producto* encontrado = inv.buscar("D001");

    if (encontrado != nullptr) {
        encontrado->imprimir();
    }

    std::cout << std::endl << "Actualizar precio F001:" << std::endl;
    inv.actualizarPrecio("F001", 900);
    inv.listar();

    std::cout << std::endl << "Eliminar S001:" << std::endl;
    inv.eliminar("S001");
    inv.listar();

    std::cout << "Valor total final: $" << inv.valorTotal() << std::endl;

    return 0;
}