#include <iostream>
#include <string>
#include <iomanip>

class Producto {
private:
    std::string nombre;
    double precio;

public:
    Producto() {
        nombre = "";
        precio = 0;
    }

    Producto(std::string n, double p) {
        nombre = n;
        precio = p;
    }

    std::string getNombre() {
        return nombre;
    }

    double getPrecio() {
        return precio;
    }

    void setDatos(std::string n, double p) {
        nombre = n;
        precio = p;
    }
};

int main() {
    int n;
    std::cin >> n;

    Producto productos[100];

    std::string nombre;
    double precio;

    for (int i = 0; i < n; i++) {
        std::cin >> nombre >> precio;
        productos[i].setDatos(nombre, precio);
    }

    int posCaro = 0;
    int posBarato = 0;

    for (int i = 1; i < n; i++) {
        if (productos[i].getPrecio() > productos[posCaro].getPrecio()) {
            posCaro = i;
        }

        if (productos[i].getPrecio() < productos[posBarato].getPrecio()) {
            posBarato = i;
        }
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Mas caro: "
              << productos[posCaro].getNombre()
              << " ($" << productos[posCaro].getPrecio() << ")"
              << std::endl;

    std::cout << "Mas barato: "
              << productos[posBarato].getNombre()
              << " ($" << productos[posBarato].getPrecio() << ")"
              << std::endl;

    return 0;
}