#ifndef REY_HPP
#define REY_HPP

#include "../Pieza.hpp"

// El rey se mueve una sola casilla en cualquier dirección
class Rey : public Pieza {
public:
    // Recibe el color y lo pasa a la clase base Pieza
    explicit Rey(Color color);

    // Revisa que el rey avance como máximo una casilla
    bool puedeMover(const Posicion& origen, const Posicion& destino,
                    const Tablero& tablero) const override;

    // Devuelve R para blanco y r para negro
    char obtenerSimbolo() const override;

    TipoPieza obtenerTipo() const override;
};

#endif
