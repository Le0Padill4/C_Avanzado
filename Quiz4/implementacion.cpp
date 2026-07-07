#include <iostream>
using namespace std;

class Jugador{
protected:
    string nombre; 
    string pais;
    virtual string posicion() = 0;
    virtual void actuar() = 0;
    virtual void imprimir() const {cout << pais << nombre << posicion;}
    virtual ~Jugador() {}
public:
    Jugador(string nombre, string pais)
}; 

class Delantero : public Jugador{
public:
    Delantero(string nombre, string pais) 
    string posicion() const override {Delantero;}
    void actuar() const override {cout << nombre << " remata al arco";}
};

class Portero : public Jugador{
public:
    Portero(string nombre, string pais){}
    string posicion() const override {Portero;}
    void actuar() const override {cout << nombre << " ataja el disparo";}
};

class Mediocampista : public Jugador{
public:
    Mediocampista(string nombre, string pais){}
    string posicion() const override {Mediocampista;}
    void actuar() const override {cout << nombre << " da el pase clave";}
};

int main(){
    Jugador* equipo[4];
    equipo[0] = new Portero("Ana"); 
    equipo[1] = new Delantero("Rola");
    equipo[2] = new Delantero("Enner");
    equipo[3] = new Mediocampista("Jose");

    for (int i = 0; i < 4; i++)
          equipo[i]->imprimir();  

    for (int i = 0; i < 4; i++) {
          equipo[i]->actuar();
          delete equipo[i];
          equipo[i] = nullptr;
      }
    return 0;
}