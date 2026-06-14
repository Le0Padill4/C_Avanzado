#include <iostream>
#include <iomanip>

class Temperatura {
public:
    double celsius;

    double getCelsius();
    double getFahrenheit();
    double getKelvin();
    void imprimir();
};

double Temperatura::getCelsius() {
    return celsius;
}

double Temperatura::getFahrenheit() {
    return celsius * 9.0 / 5.0 + 32.0;
}

double Temperatura::getKelvin() {
    return celsius + 273.15;
}

void Temperatura::imprimir() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Celsius   : " << getCelsius() << std::endl;
    std::cout << "Fahrenheit: " << getFahrenheit() << std::endl;
    std::cout << "Kelvin    : " << getKelvin() << std::endl;
}

int main() {
    Temperatura t1;

    t1.celsius = 100.0;

    t1.imprimir();

    return 0;
}