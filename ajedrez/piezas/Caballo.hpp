#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "../Pieza.hpp"

// El caballo se mueve en forma de L y puede saltar piezas.
class Caballo : public Pieza {
public:
    // Recibe el color y lo pasa a la clase base Pieza.
    explicit Caballo(Color color);

    // Revisa la forma de L del caballo.
    bool puedeMover(const Posicion& origen, const Posicion& destino,
                    const Tablero& tablero) const override;

    // Devuelve C para blanco y c para negro.
    char obtenerSimbolo() const override;

    // Identifica esta pieza como caballo.
    TipoPieza obtenerTipo() const override;
};

#endif
