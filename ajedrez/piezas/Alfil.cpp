#include "Alfil.hpp"
#include "../Tablero.hpp"
#include "../Utilidades.hpp"

Alfil::Alfil(Color color) : Pieza(color) {
}

bool Alfil::puedeMover(const Posicion& origen, const Posicion& destino,
                       const Tablero& tablero) const {
    // En una diagonal cambia la misma cantidad de filas y columnas
    int filas = valorAbsoluto(destino.fila - origen.fila);
    int columnas = valorAbsoluto(destino.columna - origen.columna);

    if (filas == 0 or filas != columnas) {
        return false;
    }

    // No puede caer sobre una pieza del mismo color
    if (tablero.contieneAliada(destino, obtenerColor())) {
        return false;
    }

    // El alfil no puede saltar piezas en el camino
    return tablero.caminoLibre(origen, destino);
}

char Alfil::obtenerSimbolo() const {
    // Mayúscula para blancas y minúscula para negras
    return obtenerColor() == Color::Blanco ? 'A' : 'a';
}

TipoPieza Alfil::obtenerTipo() const {
    return TipoPieza::Alfil;
}
