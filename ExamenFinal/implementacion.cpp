#include <fstream>
#include <iostream>

class Publicacion {
protected:
std::string titulo;
std::string autor;
int anio;

public:
    Publicacion(const std::string& titulo, const std::string& autor,int anio): titulo(titulo), autor(autor), anio(anio) {
    }
    virtual int diasPrestamo() const = 0;
    virtual void imprimir() const {
    std::cout << anio << titulo << " — " << autor << '\n';

    std::cout << "Prestamo: " << diasPrestamo() << " dias\n";
    }

    std::string getTitulo() const {
    return titulo;
    }
    virtual ~Publicacion() {
    }
};
std::ostream& operator<<(std::ostream& os, const Publicacion& publicacion) {
    publicacion.imprimir();
    return os;
}
class Libro : public Publicacion {
private:
    int paginas;

public:
    Libro(const std::string& titulo,
          const std::string& autor,
          int anio,
          int paginas)
        : Publicacion(titulo, autor, anio),
          paginas(paginas) {
    }

    int diasPrestamo() const override {
        if (paginas <= 300) {
            return 14;
        }

        return 21;
    }

    void imprimir() const override {
        Publicacion::imprimir();
        std::cout << "Paginas: " << paginas << '\n';
    }
};

class Revista : public Publicacion {
private:
int numero;
public:
    Revista(const std::string& titulo, const std::string& autor, int anio, int numero) : Publicacion(titulo, autor, anio),numero(numero) {
    }
    int diasPrestamo() const override {
        return 7;
    }
    void imprimir() const override {
        Publicacion::imprimir();
        std::cout << "Numero: " << numero << '\n';
    }
};

int main() {
Publicacion* publicaciones[4];

publicaciones[0] = new Libro(
    "dias de soledad",
        "jose luis araguren",
        32131,
        471
    );

    publicaciones[1] = new Libro(
        "El principito",
        "Antoine",
        1943,
        96
    );

    publicaciones[2] = new Revista(
        "daddadas Geographic",
        "Varios autdadores",
        2026,
        125
    );

    publicaciones[3] = new Revista(
        "sssss",
        "ssssasdaad",
        2025,
        89
    );
    for (int i = 0; i < 4; i++) {
        std::cout << *publicaciones[i];

    }
    std::ofstream archivo("catalogo.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo crear catalogo.txt\n";

        for (int i = 0; i < 4; i++) {
            delete publicaciones[i];
            publicaciones[i] = nullptr;
        }
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        archivo << publicaciones[i]->getTitulo() << " - "
                << publicaciones[i]->diasPrestamo() << " dias\n";
    }

    archivo.close();

    for (int i = 0; i < 4; i++) {
        delete publicaciones[i];
        publicaciones[i] = nullptr;
    }

    return 0;
}