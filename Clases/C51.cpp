#include <iostream>

class Material {
private:
    std::string codigo;
    std::string titulo;
    int anio;

public:
    Material(std::string c, std::string t, int a)
        : codigo(c), titulo(t), anio(a) {}

    std::string getCodigo() const {
        return codigo;
    }

    std::string getTitulo() const {
        return titulo;
    }

    int getAnio() const {
        return anio;
    }

    virtual std::string getTipo() const = 0;
    virtual bool esPrestable() const = 0;

    virtual void imprimir() const {
        std::cout << getTipo() << " | "
                  << codigo << " | "
                  << titulo << " | "
                  << anio;

        if (esPrestable()) {
            std::cout << " Prestable";
        } else {
            std::cout << " No prestable";
        }

        std::cout << std::endl;
    }

    virtual ~Material() {}
};

class Libro : public Material {
private:
    std::string autor;
    int paginas;

public:
    Libro(std::string c, std::string t, int a, std::string au, int p)
        : Material(c, t, a), autor(au), paginas(p) {}

    std::string getTipo() const override {
        return "Libro";
    }

    bool esPrestable() const override {
        return true;
    }

    void imprimir() const override {
        Material::imprimir();
        std::cout << "Autor: " << autor << " Paginas: " << paginas << std::endl;
    }
};

class Revista : public Material {
private:
    int numero;
    std::string editorial;

public:
    Revista(std::string c, std::string t, int a, int n, std::string e)
        : Material(c, t, a), numero(n), editorial(e) {}

    std::string getTipo() const override {
        return "Revista";
    }

    bool esPrestable() const override {
        return numero < 50;
    }

    void imprimir() const override {
        Material::imprimir();
        std::cout << "Numero: " << numero << " Editorial: " << editorial << std::endl;
    }
};

class DVD : public Material {
private:
    int duracionMin;
    std::string clasificacion;

public:
    DVD(std::string c, std::string t, int a, int d, std::string cl)
        : Material(c, t, a), duracionMin(d), clasificacion(cl) {}

    std::string getTipo() const override {
        return "DVD";
    }

    bool esPrestable() const override {
        return clasificacion != "18+";
    }

    void imprimir() const override {
        Material::imprimir();
        std::cout << "Duracion: " << duracionMin << " min Clasificacion: " << clasificacion << std::endl;
    }
};

class Biblioteca {
private:
    Material* catalogo[100];
    int cantidad;

public:
    Biblioteca() : cantidad(0) {}

    void agregar(Material* m) {
        if (cantidad < 100) {
            catalogo[cantidad] = m;
            cantidad++;
        }
    }

    void listarTodo() const {
        for (int i = 0; i < cantidad; i++) {
            catalogo[i]->imprimir();
        }
    }

    void listarPrestables() const {
        for (int i = 0; i < cantidad; i++) {
            if (catalogo[i]->esPrestable()) {
                catalogo[i]->imprimir();
            }
        }
    }

    void buscarPorTitulo(std::string titulo) const {
        for (int i = 0; i < cantidad; i++) {
            if (catalogo[i]->getTitulo() == titulo) {
                catalogo[i]->imprimir();
                return;
            }
        }

        std::cout << "No se encontro el material." << std::endl;
    }

    ~Biblioteca() {
        for (int i = 0; i < cantidad; i++) {
            delete catalogo[i];
        }
    }
};

int main() {
    Biblioteca b;

    b.agregar(new Libro("L001", "Cien anios de soledad", 1967, "Gabriel Garcia Marquez", 417));
    b.agregar(new Revista("R001", "National Geographic", 2020, 25, "NatGeo"));
    b.agregar(new Revista("R002", "Revista Moderna", 2024, 80, "Editorial Norte"));
    b.agregar(new DVD("D001", "Toy Story", 1995, 81, "Todo publico"));
    b.agregar(new DVD("D002", "Pelicula adulta", 2021, 120, "18+"));

    std::cout << "TODO EL CATALOGO:" << std::endl;
    b.listarTodo();

    std::cout << std::endl << "MATERIALES PRESTABLES:" << std::endl;
    b.listarPrestables();

    std::cout << std::endl << "BUSQUEDA:" << std::endl;
    b.buscarPorTitulo("Toy Story");

    return 0;
}