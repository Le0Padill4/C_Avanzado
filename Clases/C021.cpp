#include <iostream>
#include <iomanip>
#include <string>

class CuentaBancaria {
private:
    std::string titular;
    double saldo;

public:
    CuentaBancaria(std::string titular, double saldo) {
        this->titular = titular;

        if (saldo >= 0) {
            this->saldo = saldo;
        } else {
            this->saldo = 0.0;
        }
    }

    std::string getTitular() const {
        return titular;
    }

    double getSaldo() const {
        return saldo;
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Deposito: $" << monto
                      << ". Saldo: $" << saldo << std::endl;
        } else {
            std::cout << "Error: monto debe ser positivo." << std::endl;
        }
    }

    void retirar(double monto) {
        if (monto <= 0) {
            std::cout << "Error: monto debe ser positivo." << std::endl;
        } else if (monto <= saldo) {
            saldo -= monto;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Retiro: $" << monto
                      << ". Saldo: $" << saldo << std::endl;
        } else {
            std::cout << "Error: saldo insuficiente." << std::endl;
        }
    }

    void imprimir() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << titular << ": $" << saldo << std::endl;
    }
};

int main() {
    CuentaBancaria cuenta("Ana Torres", -100.0);

    cuenta.imprimir();

    cuenta.depositar(500.0);
    cuenta.retirar(200.0);
    cuenta.retirar(500.0);
    cuenta.depositar(-50.0);

    cuenta.imprimir();

    return 0;
}