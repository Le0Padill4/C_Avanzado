#include <iostream>

class Instrumento {
public:
    virtual void tocar() const = 0;

    virtual ~Instrumento() {}
};

class Guitarra : public Instrumento {
public:
    void tocar() const override {
        std::cout << "Tañe las cuerdas" << std::endl;
    }
};

class Piano : public Instrumento {
public:
    void tocar() const override {
        std::cout << "Presiona las teclas" << std::endl;
    }
};

class Bateria : public Instrumento {
public:
    void tocar() const override {
        std::cout << "Golpea los parches" << std::endl;
    }
};

void concierto(Instrumento* i) {
    std::cout << "[puntero]    ";
    i->tocar();
}

void concierto(Instrumento& i) {
    std::cout << "[referencia] ";
    i.tocar();
}

int main() {
    Instrumento* instrumentos[3];

    instrumentos[0] = new Guitarra();
    instrumentos[1] = new Piano();
    instrumentos[2] = new Bateria();

    for (int i = 0; i < 3; i++) {
        concierto(instrumentos[i]);
    }

    for (int i = 0; i < 3; i++) {
        delete instrumentos[i];
        instrumentos[i] = nullptr;
    }

    Guitarra guitarra;
    Piano piano;
    Bateria bateria;

    concierto(guitarra);
    concierto(piano);
    concierto(bateria);

    return 0;
}