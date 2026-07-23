#include "Peon.hpp"
#include "../Tablero.hpp"
#include "../Utilidades.hpp"

Peon::Peon(Color color) : Pieza(color) {
}

bool Peon::puedeMover(const Posicion& origen, const Posicion& destino,
                      const Tablero& tablero) const {
    // Las blancas suben en la matriz y las negras bajan.
    int direccion = obtenerColor() == Color::Blanco ? -1 : 1;
    int diferenciaFila = destino.fila - origen.fila;
    int diferenciaColumna = valorAbsoluto(destino.columna - origen.columna);

    // Avance normal de una casilla, solo si está vacía.
    if (diferenciaColumna == 0 and diferenciaFila == direccion) {
        return tablero.estaVacia(destino);
    }

    // En su primer movimiento puede avanzar dos casillas si no hay piezas
    if (diferenciaColumna == 0 and diferenciaFila == 2 * direccion and
        not fueMovida()) {
        Posicion intermedia = {origen.fila + direccion, origen.columna};
        return tablero.estaVacia(intermedia) and tablero.estaVacia(destino);
    }

    // El peón captura solamente una casilla en diagonal
    if (diferenciaColumna == 1 and diferenciaFila == direccion) {
        return tablero.contieneEnemiga(destino, obtenerColor());
    }

    return false;
}

char Peon::obtenerSimbolo() const {
    // Mayúscula para blancas y minúscula para negras
    return obtenerColor() == Color::Blanco ? 'P' : 'p';
}

TipoPieza Peon::obtenerTipo() const {
    return TipoPieza::Peon;
}
