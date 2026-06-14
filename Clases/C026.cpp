#include <iostream>
#include <string>

class Semaforo {
private:
    std::string estado;

public:
    Semaforo() : estado("rojo") {
    }

    std::string getEstado() const {
        return estado;
    }

    void avanzar() {
        if (estado == "rojo") {
            estado = "verde";
        } else if (estado == "verde") {
            estado = "amarillo";
        } else {
            estado = "rojo";
        }
    }

    void imprimir() const {
        std::cout << "Estado: " << estado << std::endl;
    }
};

int main() {
    Semaforo semaforo;

    semaforo.imprimir();

    for (int i = 0; i < 7; i++) {
        semaforo.avanzar();
        semaforo.imprimir();
    }

    return 0;
}