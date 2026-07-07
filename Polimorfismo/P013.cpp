#include <iostream>

class Logger {
public:
    virtual void log(std::string mensaje) const {
        std::cout << "[LOG] " << mensaje << std::endl;
    }

    virtual ~Logger() {}
};

class LoggerFecha : public Logger {
public:
    void log(std::string mensaje) const override {
        Logger::log(mensaje);
        std::cout << "[FECHA] 2024-01-01" << std::endl;
    }
};

class LoggerCompleto : public LoggerFecha {
public:
    void log(std::string mensaje) const override {
        LoggerFecha::log(mensaje);
        std::cout << "[NIVEL] INFO" << std::endl;
    }
};

int main() {
    Logger base;
    LoggerFecha conFecha;
    LoggerCompleto completo;

    std::cout << "-- Logger base:" << std::endl;
    base.log("Sistema iniciado");

    std::cout << std::endl;
    std::cout << "-- LoggerFecha:" << std::endl;
    conFecha.log("Sistema iniciado");

    std::cout << std::endl;
    std::cout << "-- LoggerCompleto:" << std::endl;
    completo.log("Sistema iniciado");

    return 0;
}