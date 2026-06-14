#include <iostream>
#include <iomanip>
#include <string>

class ItemInventario {
private:
    std::string codigo;
    std::string nombre;
    int cantidad;
    double precio;

public:
    ItemInventario(std::string codigo, std::string nombre, int cantidad, double precio)
        : codigo(codigo), nombre(nombre) {

        if (cantidad >= 0) {
            this->cantidad = cantidad;
        } else {
            this->cantidad = 0;
        }

        if (precio >= 0) {
            this->precio = precio;
        } else {
            this->precio = 0.0;
        }
    }

    std::string getCodigo() const {
        return codigo;
    }

    std::string getNombre() const {
        return nombre;
    }

    int getCantidad() const {
        return cantidad;
    }

    double getPrecio() const {
        return precio;
    }

    void setCantidad(int cantidad) {
        if (cantidad >= 0) {
            this->cantidad = cantidad;
        } else {
            std::cout << "Cantidad invalida." << std::endl;
        }
    }

    void setPrecio(double precio) {
        if (precio >= 0) {
            this->precio = precio;
        } else {
            std::cout << "Precio invalido." << std::endl;
        }
    }

    double valorTotal() const {
        return cantidad * precio;
    }

    void vender(int n) {
        if (n <= 0) {
            std::cout << "Cantidad invalida." << std::endl;
        } else if (n <= cantidad) {
            cantidad -= n;
            std::cout << "Venta de " << n
                      << " unidades. Quedan: " << cantidad << std::endl;
        } else {
            std::cout << "Stock insuficiente. Solo hay "
                      << cantidad << " unidades." << std::endl;
        }
    }

    void reabastecer(int n) {
        if (n > 0) {
            cantidad += n;
            std::cout << "Reabastecido: +" << n
                      << " unidades. Total: " << cantidad << std::endl;
        } else {
            std::cout << "Cantidad invalida." << std::endl;
        }
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "[" << codigo << "] " << nombre
                  << " | Cant: " << cantidad
                  << " | Precio: $" << precio
                  << " | Total: $" << valorTotal() << std::endl;
    }
};

int main() {
    ItemInventario item1("A001", "Laptop", 10, 1200.0);

    item1.imprimir();

    item1.vender(3);
    item1.vender(10);
    item1.reabastecer(20);

    item1.imprimir();

    return 0;
}