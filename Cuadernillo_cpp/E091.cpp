#include <iostream>
#include <string>
#include <iomanip>

class Sensor {
private:
    std::string nombre;
    double valor;

public:
    Sensor(std::string n, double v) {
        nombre = n;
        valor = v;

        std::cout << nombre << " activado." << std::endl;
    }

    ~Sensor() {
        std::cout << nombre << " desactivado." << std::endl;
    }

    double leer() {
        return valor;
    }

    std::string getNombre() {
        return nombre;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Sensor s1("Temperatura", 36.6);
    Sensor s2("Presion", 101.3);

    std::cout << s1.getNombre() << ": " << s1.leer() << std::endl;
    std::cout << s2.getNombre() << ": " << s2.leer() << std::endl;

    return 0;
}