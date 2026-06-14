#include <iostream>
#include <iomanip>
#include <string>

class Producto {
public:
    std::string nombre;
    double precio;
    int stock;

    Producto(std::string n, double p, int s) : nombre(n) {
        precio = (p >= 0) ? p : 0;
        stock = (s >= 0) ? s : 0;
    }

    Producto(std::string n, double p) : nombre(n) {
        precio = (p >= 0) ? p : 0;
        stock = 0;
    }

    ~Producto() {
        std::cout << "Producto " << nombre << " eliminado del sistema." << std::endl;
    }

    void vender(int cantidad) {
        if (cantidad <= 0) {
            std::cout << "Cantidad invalida." << std::endl;
        } else if (stock >= cantidad) {
            stock -= cantidad;
            std::cout << "Venta exitosa. Stock restante: " << stock << std::endl;
        } else {
            std::cout << "Stock insuficiente." << std::endl;
        }
    }

    void reabastecer(int cantidad) {
        if (cantidad > 0) {
            stock += cantidad;
            std::cout << "Reabastecer: " << cantidad
                      << " unidades. Stock: " << stock << std::endl;
        } else {
            std::cout << "Cantidad invalida." << std::endl;
        }
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << nombre << " | $" << precio
                  << " | Stock: " << stock << std::endl;
    }
};

int main() {
    Producto producto1("Laptop", 1200.0, 5);

    producto1.imprimir();

    producto1.vender(2);
    producto1.vender(10);
    producto1.reabastecer(10);

    producto1.imprimir();

    return 0;
}