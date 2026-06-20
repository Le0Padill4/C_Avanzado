#include <iostream>

class Cuenta {
protected:
    std::string titular;
    double saldo;

public:
    Cuenta(std::string t, double s) : titular(t) {
        if (s >= 0) {
            saldo = s;
        } else {
            saldo = 0;
        }
    }

    std::string getTitular() const {
        return titular;
    }

    double getSaldo() const {
        return saldo;
    }

    virtual void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            std::cout << "Deposito: " << monto << " Saldo: " << saldo << std::endl;
        }
    }

    virtual void retirar(double monto) {
        if (monto <= saldo) {
            saldo -= monto;
            std::cout << "Retiro: " << monto << " Saldo: " << saldo << std::endl;
        } else {
            std::cout << "Retiro rechazado." << std::endl;
        }
    }

    virtual void imprimir() const {
        std::cout << titular << ": $" << saldo << std::endl;
    }
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;

public:
    CuentaAhorro(std::string t, double s, double tasa)
        : Cuenta(t, s), tasaInteres(tasa) {}

    void aplicarInteres() {
        saldo += saldo * tasaInteres;
        std::cout << "Interes aplicado Saldo: " << saldo << std::endl;
    }

    void imprimir() const override {
        std::cout << "[Ahorro] " << titular << ": $" << saldo
                  << " Interes: " << tasaInteres * 100 << "%" << std::endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double sobregiroMax;

public:
    CuentaCorriente(std::string t, double s, double sobregiro)
        : Cuenta(t, s), sobregiroMax(sobregiro) {}

    void retirar(double monto) override {
        if (monto <= saldo + sobregiroMax) {
            saldo -= monto;
            std::cout << "Retiro: " << monto << " Saldo: " << saldo << std::endl;
        } else {
            std::cout << "Retiro: " << monto
                      << " RECHAZADO: supera limite de sobregiro." << std::endl;
        }
    }

    void imprimir() const override {
        std::cout << "[Corriente] " << titular << ": $" << saldo
                  << " | Sobregiro max: $" << sobregiroMax << std::endl;
    }
};

int main() {
    CuentaAhorro ahorro("Ana", 1000, 0.05);
    ahorro.imprimir();
    ahorro.depositar(200);
    ahorro.aplicarInteres();

    CuentaCorriente corriente("Luis", 500, 200);
    corriente.imprimir();
    corriente.retirar(600);
    corriente.retirar(200);

    return 0;
}