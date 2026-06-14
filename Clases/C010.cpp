#include <iostream>
#include <iomanip>
#include <string>

class Cuenta {
public:
    std::string titular;
    double saldo;

    void depositar(double monto) {
        saldo += monto;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Deposito: $" << monto
                  << " Nuevo saldo: $" << saldo << std::endl;
    }

    void retirar(double monto) {
        if (tieneSaldo(monto)) {
            saldo -= monto;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Retiro: $" << monto
                      << " Nuevo saldo: $" << saldo << std::endl;
        } else {
            std::cout << "Saldo insuficiente." << std::endl;
        }
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Titular: " << titular
                  << " Saldo: $" << saldo << std::endl;
    }

    bool tieneSaldo(double monto) {
        return saldo >= monto;
    }
};

int main() {
    Cuenta cuenta1;

    cuenta1.titular = "Ana Torres";
    cuenta1.saldo = 500.0;

    cuenta1.imprimir();

    cuenta1.depositar(200.0);
    cuenta1.retirar(100.0);
    cuenta1.retirar(1000.0);

    cuenta1.imprimir();

    return 0;
}