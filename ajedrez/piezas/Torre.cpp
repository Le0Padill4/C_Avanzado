#include "Torre.hpp"
#include "../Tablero.hpp"

Torre::Torre(Color color) : Pieza(color) {
}

bool Torre::puedeMover(const Posicion& origen, const Posicion& destino,
                       const Tablero& tablero) const {
    // Mover a la misma casilla no cuenta como jugada
    if (origen == destino) {
        return false;
    }

    // La torre solo se mueve por la misma fila o la misma columna
    if (origen.fila != destino.fila and origen.columna != destino.columna) {
        return false;
    }

    if (tablero.contieneAliada(destino, obtenerColor())) {
        return false;
    }

    // No puede saltar piezas que estén entre el origen y el destino
    return tablero.caminoLibre(origen, destino);
}

char Torre::obtenerSimbolo() const {
    // Mayúscula para blancas y minúscula para negras
    return obtenerColor() == Color::Blanco ? 'T' : 't';
}

TipoPieza Torre::obtenerTipo() const {
    return TipoPieza::Torre;
}
