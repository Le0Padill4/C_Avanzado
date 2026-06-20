#include <iostream>

class Instrumento {
public:
    virtual void tocar() const = 0;
    virtual std::string getFamilia() const = 0;
    virtual double getPrecio() const = 0;

    void imprimir() const {
        std::cout << getFamilia() << " | Precio: $" << getPrecio() << std::endl;
    }

    virtual ~Instrumento() {}
};

class Cuerdas : public Instrumento {
public:
    std::string getFamilia() const override {
        return "Cuerdas";
    }

    virtual int getCuerdas() const = 0;
};

class Viento : public Instrumento {
public:
    std::string getFamilia() const override {
        return "Viento";
    }

    virtual std::string getMaterial() const = 0;
};

class Percusion : public Instrumento {
public:
    std::string getFamilia() const override {
        return "Percusion";
    }
};

class Guitarra : public Cuerdas {
private:
    double precio;

public:
    Guitarra(double p) : precio(p) {}

    void tocar() const override {
        std::cout << "Tocando guitarra." << std::endl;
    }

    int getCuerdas() const override {
        return 6;
    }

    double getPrecio() const override {
        return precio;
    }
};

class Violin : public Cuerdas {
private:
    double precio;

public:
    Violin(double p) : precio(p) {}

    void tocar() const override {
        std::cout << "Tocando violin." << std::endl;
    }

    int getCuerdas() const override {
        return 4;
    }

    double getPrecio() const override {
        return precio;
    }
};

class Trompeta : public Viento {
private:
    double precio;

public:
    Trompeta(double p) : precio(p) {}

    void tocar() const override {
        std::cout << "Tocando trompeta." << std::endl;
    }

    std::string getMaterial() const override {
        return "Metal";
    }

    double getPrecio() const override {
        return precio;
    }
};

class Flauta : public Viento {
private:
    double precio;

public:
    Flauta(double p) : precio(p) {}

    void tocar() const override {
        std::cout << "Tocando flauta." << std::endl;
    }

    std::string getMaterial() const override {
        return "Madera";
    }

    double getPrecio() const override {
        return precio;
    }
};

class Bateria : public Percusion {
private:
    double precio;

public:
    Bateria(double p) : precio(p) {}

    void tocar() const override {
        std::cout << "Tocando bateria." << std::endl;
    }

    double getPrecio() const override {
        return precio;
    }
};

class Tambor : public Percusion {
private:
    double precio;

public:
    Tambor(double p) : precio(p) {}

    void tocar() const override {
        std::cout << "Tocando tambor." << std::endl;
    }

    double getPrecio() const override {
        return precio;
    }
};

int main() {
    Instrumento* orquesta[8];

    orquesta[0] = new Guitarra(300);
    orquesta[1] = new Violin(500);
    orquesta[2] = new Trompeta(450);
    orquesta[3] = new Flauta(200);
    orquesta[4] = new Bateria(1000);
    orquesta[5] = new Tambor(150);
    orquesta[6] = new Guitarra(350);
    orquesta[7] = new Flauta(180);

    int cuerdas = 0;
    int viento = 0;
    int percusion = 0;
    double total = 0;

    for (int i = 0; i < 8; i++) {
        orquesta[i]->tocar();
        orquesta[i]->imprimir();

        total += orquesta[i]->getPrecio();

        if (orquesta[i]->getFamilia() == "Cuerdas") {
            cuerdas++;
        } else if (orquesta[i]->getFamilia() == "Viento") {
            viento++;
        } else if (orquesta[i]->getFamilia() == "Percusion") {
            percusion++;
        }
    }

    std::cout << "Cuerdas: " << cuerdas << std::endl;
    std::cout << "Viento: " << viento << std::endl;
    std::cout << "Percusion: " << percusion << std::endl;

    std::cout << "Valor total: $" << total << std::endl;

    for (int i = 0; i < 8; i++) {
        delete orquesta[i];
    }

    return 0;
}