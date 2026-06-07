#include <iostream>
#include <iomanip>

class CuentaBancaria {
private:
    double saldo;

public:
    CuentaBancaria(double saldoInicial) {
        saldo = saldoInicial;
    }

    bool depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            return true;
        }

        return false;
    }

    bool retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            return true;
        }

        return false;
    }

    double getSaldo() {
        return saldo;
    }
};

int main() {
    double saldoInicial;
    std::cin >> saldoInicial;

    CuentaBancaria cuenta(saldoInicial);

    int opcion;
    double monto;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Saldo inicial: $" << cuenta.getSaldo() << std::endl;

    do {
        std::cout << "=== Menu ===" << std::endl;
        std::cout << "1. Depositar  2. Retirar  3. Ver saldo  4. Salir" << std::endl;
        std::cout << "Opcion: ";

        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "Monto: ";
            std::cin >> monto;

            if (cuenta.depositar(monto)) {
                std::cout << "Deposito OK. Saldo: $" 
                          << cuenta.getSaldo() << std::endl;
            } else {
                std::cout << "Error: monto invalido. Saldo: $" 
                          << cuenta.getSaldo() << std::endl;
            }

        } else if (opcion == 2) {
            std::cout << "Monto: ";
            std::cin >> monto;

            if (cuenta.retirar(monto)) {
                std::cout << "Retiro OK. Saldo: $" 
                          << cuenta.getSaldo() << std::endl;
            } else {
                std::cout << "Error: saldo insuficiente. Saldo: $" 
                          << cuenta.getSaldo() << std::endl;
            }

        } else if (opcion == 3) {
            std::cout << "Saldo: $" << cuenta.getSaldo() << std::endl;

        } else if (opcion == 4) {
            std::cout << "Hasta pronto." << std::endl;

        } else {
            std::cout << "Opcion invalida." << std::endl;
        }

    } while (opcion != 4);

    return 0;
}