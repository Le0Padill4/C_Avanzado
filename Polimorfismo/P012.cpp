#include <iostream>
#include <iomanip>

class MedioPago {
public:
    virtual void procesar(double monto) = 0;
    virtual bool exitoso() const = 0;
    virtual void imprimirComprobante() const = 0;

    virtual ~MedioPago() {}
};

class TarjetaCredito : public MedioPago {
private:
    std::string ultimosDigitos;
    double monto;
    bool aprobado;

public:
    TarjetaCredito(std::string digitos)
        : ultimosDigitos(digitos), monto(0), aprobado(false) {}

    void procesar(double m) override {
        monto = m;
        aprobado = true;

        std::cout << "[Tarjeta] Procesando $"
                  << std::fixed << std::setprecision(2)
                  << monto
                  << "... Aprobado."
                  << std::endl;
    }

    bool exitoso() const override {
        return aprobado;
    }

    void imprimirComprobante() const override {
        std::cout << "Comprobante: TC-****"
                  << ultimosDigitos
                  << " $"
                  << std::fixed << std::setprecision(2)
                  << monto
                  << std::endl;
    }
};

class TransferenciaBancaria : public MedioPago {
private:
    std::string codigo;
    double monto;
    bool aprobado;

public:
    TransferenciaBancaria(std::string c)
        : codigo(c), monto(0), aprobado(false) {}

    void procesar(double m) override {
        monto = m;
        aprobado = true;

        std::cout << "[Transferencia] Procesando $"
                  << std::fixed << std::setprecision(2)
                  << monto
                  << "... Aprobado."
                  << std::endl;
    }

    bool exitoso() const override {
        return aprobado;
    }

    void imprimirComprobante() const override {
        std::cout << "Comprobante: TR-"
                  << codigo
                  << " $"
                  << std::fixed << std::setprecision(2)
                  << monto
                  << std::endl;
    }
};

class Efectivo : public MedioPago {
private:
    std::string codigo;
    double monto;
    bool aprobado;

public:
    Efectivo(std::string c)
        : codigo(c), monto(0), aprobado(false) {}

    void procesar(double m) override {
        monto = m;
        aprobado = true;

        std::cout << "[Efectivo] Procesando $"
                  << std::fixed << std::setprecision(2)
                  << monto
                  << "... Aprobado."
                  << std::endl;
    }

    bool exitoso() const override {
        return aprobado;
    }

    void imprimirComprobante() const override {
        std::cout << "Comprobante: EF-"
                  << codigo
                  << " $"
                  << std::fixed << std::setprecision(2)
                  << monto
                  << std::endl;
    }
};

int main() {
    MedioPago* pagos[3];
    double montos[3] = {150.0, 500.0, 20.0};

    pagos[0] = new TarjetaCredito("1234");
    pagos[1] = new TransferenciaBancaria("001");
    pagos[2] = new Efectivo("001");

    for (int i = 0; i < 3; i++) {
        pagos[i]->procesar(montos[i]);

        if (pagos[i]->exitoso()) {
            pagos[i]->imprimirComprobante();
        }
    }

    for (int i = 0; i < 3; i++) {
        delete pagos[i];
        pagos[i] = nullptr;
    }

    return 0;
}