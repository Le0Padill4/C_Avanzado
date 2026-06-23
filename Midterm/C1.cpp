#include <iostream>

class RegistroTemperaturas{
private:
    double* lecturas;
    int capacidad;
    int cantidad;
public:
    RegistroTemperaturas(int cap) : cantidad(cap) {
          lecturas = new double{};
      }
    ~RegistroTemperaturas() {
          delete[] lecturas;
          lecturas = nullptr;
      }
    void agregar(double temp){

    }

    double promedio(int capacidad) const{
    double prom = 0;
    double tot = 0;
    for (int i = 0; i < capacidad; i++){
        lecturas[i] = lecturas[i];
        prom = tot/capacidad;
    }
    std :: cout << prom;
    if (cantidad == 0){
        return 0.0;
    }
    }
    double maxima() const{
    int max = 0;
    for (int i = 0; i < capacidad; i++){
        max;
    }
    }

    double minimo() const{

    }

    void imprimir() const{

    }
};