#ifndef MOVIMIENTO_HPP
#define MOVIMIENTO_HPP

#include "Posicion.hpp"

// Un movimiento guarda la casilla desde donde sale la pieza y la casilla a la que quiere llegar
struct Movimiento {
    Posicion origen;
    Posicion destino;
};

#endif
