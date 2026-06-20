#include <iostream>
#include <string>

class Cuenta {
private:
    std::string numeroCuenta;
    std::string titular;
    double saldo;

protected:
    void setSaldo(double s) {
        saldo = s;
    }

public:
    Cuenta(std::string num, std::string tit, double sal) {
        if (num != "") {
            numeroCuenta = num;
        } else {
            numeroCuenta = "SIN_NUMERO";
        }

        if (tit != "") {
            titular = tit;
        } else {
            titular = "SIN_TITULAR";
        }

        if (sal >= 0) {
            saldo = sal;
        } else {
            saldo = 0;
        }
    }

    std::string getNumeroCuenta() const {
        return numeroCuenta;
    }

    std::string getTitular() const {
        return titular;
    }

    double getSaldo() const {
        return saldo;
    }

    virtual std::string getTipo() const = 0;
    virtual double calcularInteres() const = 0;

    virtual void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
        }
    }

    virtual void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
        } else {
            std::cout << "Retiro rechazado." << std::endl;
        }
    }

    void aplicarInteres() {
        saldo += calcularInteres();
    }

    void imprimir() const {
        std::cout << getTipo()
                  << " | Cuenta: " << numeroCuenta
                  << " | Titular: " << titular
                  << " | Saldo: $" << saldo
                  << " | Interes: $" << calcularInteres()
                  << std::endl;
    }

    virtual ~Cuenta() {}
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;
    double saldoMinimo;

public:
    CuentaAhorro(std::string num, std::string tit, double sal, double tasa, double minimo)
        : Cuenta(num, tit, sal), tasaInteres(tasa), saldoMinimo(minimo) {}

    std::string getTipo() const override {
        return "Cuenta Ahorro";
    }

    double calcularInteres() const override {
        return getSaldo() * tasaInteres;
    }

    void retirar(double monto) override {
        if (monto > 0 && getSaldo() - monto >= saldoMinimo) {
            setSaldo(getSaldo() - monto);
        } else {
            std::cout << "Retiro rechazado: saldo minimo." << std::endl;
        }
    }
};

class CuentaCorriente : public Cuenta {
private:
    double limiteCredito;
    double cargoMensual;

public:
    CuentaCorriente(std::string num, std::string tit, double sal, double limite, double cargo)
        : Cuenta(num, tit, sal), limiteCredito(limite), cargoMensual(cargo) {}

    std::string getTipo() const override {
        return "Cuenta Corriente";
    }

    double calcularInteres() const override {
        return 0;
    }

    void retirar(double monto) override {
        if (monto > 0 && monto <= getSaldo() + limiteCredito) {
            setSaldo(getSaldo() - monto);
        } else {
            std::cout << "Retiro rechazado: supera limite de credito." << std::endl;
        }
    }
};

class CuentaInversion : public Cuenta {
private:
    std::string activos[10];
    int cantidadActivos;
    std::string riesgo;

public:
    CuentaInversion(std::string num, std::string tit, double sal, std::string r)
        : Cuenta(num, tit, sal), cantidadActivos(0), riesgo(r) {}

    void agregarActivo(std::string activo) {
        if (cantidadActivos < 10) {
            activos[cantidadActivos] = activo;
            cantidadActivos++;
        }
    }

    std::string getTipo() const override {
        return "Cuenta Inversion";
    }

    double calcularInteres() const override {
        if (riesgo == "alto") {
            return getSaldo() * 0.12;
        } else if (riesgo == "medio") {
            return getSaldo() * 0.08;
        } else {
            return getSaldo() * 0.04;
        }
    }
};

class Banco {
private:
    Cuenta* cuentas[200];
    int numCuentas;

public:
    Banco() : numCuentas(0) {}

    void abrirCuenta(Cuenta* c) {
        if (numCuentas < 200) {
            cuentas[numCuentas] = c;
            numCuentas++;
        }
    }

    void cerrarCuenta(std::string numCuenta) {
        for (int i = 0; i < numCuentas; i++) {
            if (cuentas[i]->getNumeroCuenta() == numCuenta) {
                delete cuentas[i];

                for (int j = i; j < numCuentas - 1; j++) {
                    cuentas[j] = cuentas[j + 1];
                }

                numCuentas--;
                return;
            }
        }

        std::cout << "Cuenta no encontrada." << std::endl;
    }

    Cuenta* buscarCuenta(std::string numCuenta) const {
        for (int i = 0; i < numCuentas; i++) {
            if (cuentas[i]->getNumeroCuenta() == numCuenta) {
                return cuentas[i];
            }
        }

        return nullptr;
    }

    void aplicarIntereses() {
        for (int i = 0; i < numCuentas; i++) {
            cuentas[i]->aplicarInteres();
        }
    }

    void imprimirEstadoCuenta(std::string numCuenta) const {
        Cuenta* c = buscarCuenta(numCuenta);

        if (c != nullptr) {
            c->imprimir();
        } else {
            std::cout << "Cuenta no encontrada." << std::endl;
        }
    }

    double totalDepositado() const {
        double total = 0;

        for (int i = 0; i < numCuentas; i++) {
            total += cuentas[i]->getSaldo();
        }

        return total;
    }

    ~Banco() {
        for (int i = 0; i < numCuentas; i++) {
            delete cuentas[i];
        }
    }
};

int main() {
    Banco banco;

    banco.abrirCuenta(new CuentaAhorro("A001", "Ana", 1000, 0.05, 100));
    banco.abrirCuenta(new CuentaCorriente("C001", "Luis", 500, 300, 10));

    CuentaInversion* inv = new CuentaInversion("I001", "Carla", 2000, "alto");
    inv->agregarActivo("Acciones");
    inv->agregarActivo("Bonos");
    banco.abrirCuenta(inv);

    banco.imprimirEstadoCuenta("A001");
    banco.imprimirEstadoCuenta("C001");
    banco.imprimirEstadoCuenta("I001");

    std::cout << "Total depositado: $" << banco.totalDepositado() << std::endl;

    banco.aplicarIntereses();

    std::cout << "Despues de intereses:" << std::endl;
    banco.imprimirEstadoCuenta("A001");
    banco.imprimirEstadoCuenta("I001");

    banco.cerrarCuenta("C001");

    std::cout << "Total final: $" << banco.totalDepositado() << std::endl;

    return 0;
}