#include <iostream>

class Animal {
public:
    virtual void hacerSonido() const = 0;

    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Miau!" << std::endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Muuu!" << std::endl;
    }
};

class Pato : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Cuac!" << std::endl;
    }
};

int main() {
    Animal* animales[4];

    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();
    animales[3] = new Pato();

    for (int i = 0; i < 4; i++) {
        animales[i]->hacerSonido();
    }

    for (int i = 0; i < 4; i++) {
        delete animales[i];
        animales[i] = nullptr;
    }

/*
Sin polimorfismo, para agregar Pato tocaría modificar una función con varios if

Con polimorfismo solo se crea la clase Pato.
El arreglo usa Animal* y llama hacerSonido() de forma uniforme.

Aunque el puntero sea de tipo Animal*, el método ejecutado depende del objeto real: Perro, Gato, Vaca o Pato.
*/

    return 0;
}