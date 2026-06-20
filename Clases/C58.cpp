#include <iostream>
#include <string>

class Personaje {
private:
    std::string nombre;
    int vida;
    int ataque;
    int defensa;
    int nivel;

protected:
    void curar(int cantidad) {
        vida += cantidad;
    }

public:
    Personaje(std::string n, int v, int a, int d, int niv)
        : nombre(n), vida(v), ataque(a), defensa(d), nivel(niv) {}

    std::string getNombre() const {
        return nombre;
    }

    int getVida() const {
        return vida;
    }

    int getAtaque() const {
        return ataque;
    }

    int getDefensa() const {
        return defensa;
    }

    int getNivel() const {
        return nivel;
    }

    virtual std::string getClase() const = 0;
    virtual int habilidadEspecial() = 0;

    void recibirDano(int dano) {
        int danoReal = dano - defensa;

        if (danoReal < 0) {
            danoReal = 0;
        }

        vida -= danoReal;

        if (vida < 0) {
            vida = 0;
        }
    }

    bool estaVivo() const {
        return vida > 0;
    }

    virtual void imprimir() const {
        std::cout << nombre << getClase() << " Vida: " << vida << " Ataque: " << ataque << " Defensa: " << defensa << " Nivel: " << nivel << std::endl;
    }

    virtual ~Personaje() {}
};

class Guerrero : public Personaje {
public:
    Guerrero(std::string n, int v, int a, int d, int niv)
        : Personaje(n, v, a, d, niv) {}

    std::string getClase() const override {
        return "Guerrero";
    }

    int habilidadEspecial() override {
        return getAtaque() * 2;
    }
};

class Mago : public Personaje {
public:
    Mago(std::string n, int v, int a, int d, int niv)
        : Personaje(n, v, a, d, niv) {}

    std::string getClase() const override {
        return "Mago";
    }

    int habilidadEspecial() override {
        return getAtaque() * 3;
    }
};

class Arquero : public Personaje {
public:
    Arquero(std::string n, int v, int a, int d, int niv)
        : Personaje(n, v, a, d, niv) {}

    std::string getClase() const override {
        return "Arquero";
    }

    int habilidadEspecial() override {
        return getAtaque() * 1.5;
    }
};

class Paladin : public Guerrero {
public:
    Paladin(std::string n, int v, int a, int d, int niv)
        : Guerrero(n, v, a, d, niv) {}

    std::string getClase() const override {
        return "Paladin";
    }

    int habilidadEspecial() override {
        curar(20);
        return getAtaque() * 2;
    }
};

void combate(Personaje& p1, Personaje& p2) {
    std::cout << "Combate: " << p1.getNombre()
              << " vs " << p2.getNombre() << std::endl;

    while (p1.estaVivo() && p2.estaVivo()) {
        p2.recibirDano(p1.habilidadEspecial());

        if (p2.estaVivo()) {
            p1.recibirDano(p2.habilidadEspecial());
        }
    }

    if (p1.estaVivo()) {
        std::cout << "Gana: " << p1.getNombre() << std::endl;
    } else {
        std::cout << "Gana: " << p2.getNombre() << std::endl;
    }
}

void torneo(Personaje* participantes[], int n) {
    for (int i = 0; i < n; i++) {
        participantes[i]->imprimir();
    }

    std::cout << std::endl;

    for (int i = 0; i < n - 1; i += 2) {
        combate(*participantes[i], *participantes[i + 1]);
        std::cout << std::endl;
    }
}

int main() {
    Guerrero g("Arthur", 100, 20, 8, 5);
    Mago m("Merlin", 80, 25, 5, 6);
    Arquero a("Robin", 90, 18, 6, 4);
    Paladin p("Uther", 120, 22, 10, 7);

    Personaje* participantes[4] = {&g, &m, &a, &p};

    torneo(participantes, 4);

    return 0;
}