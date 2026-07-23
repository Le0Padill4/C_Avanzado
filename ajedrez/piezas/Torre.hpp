#ifndef TORRE_HPP
#define TORRE_HPP

#include "../Pieza.hpp"

// La torre se mueve en línea recta por filas o columnas
class Torre : public Pieza {
public:
    // Recibe el color y lo pasa a la clase base Pieza
    explicit Torre(Color color);

    // Revisa que el movimiento sea recto y que el camino esté libre
    bool puedeMover(const Posicion& origen, const Posicion& destino,
                    const Tablero& tablero) const override;

    // Devuelve T para blanco y t para negro
    char obtenerSimbolo() const override;

    // Identifica esta pieza como torre
    TipoPieza obtenerTipo() const override;
};

#endif
