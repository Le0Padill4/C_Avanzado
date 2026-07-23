#include "Rey.hpp"
#include "../Tablero.hpp"
#include "../Utilidades.hpp"

Rey::Rey(Color color) : Pieza(color) {
}

bool Rey::puedeMover(const Posicion& origen, const Posicion& destino,
                     const Tablero& tablero) const {
    // En esta versión sencilla el rey solo revisa moverse una casilla
    int filas = valorAbsoluto(destino.fila - origen.fila);
    int columnas = valorAbsoluto(destino.columna - origen.columna);
    bool unaCasilla = filas <= 1 and columnas <= 1 and origen != destino;

    return unaCasilla and not tablero.contieneAliada(destino, obtenerColor());
}

char Rey::obtenerSimbolo() const {
    // Mayúscula para blancas y minúscula para negras
    return obtenerColor() == Color::Blanco ? 'R' : 'r';
}

TipoPieza Rey::obtenerTipo() const {
    return TipoPieza::Rey;
}
