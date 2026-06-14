#include <iostream>
#include <iomanip>
#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    int anio;
    double precio;

public:
    Libro(std::string titulo, std::string autor, int anio, double precio)
        : titulo(titulo), autor(autor), anio(anio) {
        if (precio >= 0) {
            this->precio = precio;
        } else {
            this->precio = 0.0;
        }
    }

    const std::string& getTitulo() const {
        return titulo;
    }

    const std::string& getAutor() const {
        return autor;
    }

    int getAnio() const {
        return anio;
    }

    double getPrecio() const {
        return precio;
    }

    void setPrecio(double precio) {
        if (precio >= 0) {
            this->precio = precio;
        } else {
            std::cout << "Precio invalido." << std::endl;
        }
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor : " << autor << std::endl;
        std::cout << "Anio  : " << anio << std::endl;
        std::cout << "Precio: $" << precio << std::endl;
    }
};

int main() {
    Libro libro1("El Principito", "Antoine de Saint-Exupery", 1943, 12.50);

    libro1.imprimir();

    return 0;
}