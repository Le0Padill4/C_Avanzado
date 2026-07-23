#include "Caballo.hpp"
#include "../Tablero.hpp"
#include "../Utilidades.hpp"

Caballo::Caballo(Color color) : Pieza(color) {
}

bool Caballo::puedeMover(const Posicion& origen, const Posicion& destino, const Tablero& tablero) const {
    // El caballo siempre mueve dos casillas en un sentido y una en el otro.
    int filas = valorAbsoluto(destino.fila - origen.fila);
    int columnas = valorAbsoluto(destino.columna - origen.columna);
    bool formaDeL = (filas == 2 and columnas == 1) or
                    (filas == 1 and columnas == 2);

    // Puede saltar, así que solo importa que no capture una pieza aliada.
    return formaDeL and not tablero.contieneAliada(destino, obtenerColor());
}

char Caballo::obtenerSimbolo() const {
    // Usamos C porque R queda para el rey.
    return obtenerColor() == Color::Blanco ? 'C' : 'c';
}

TipoPieza Caballo::obtenerTipo() const {
    return TipoPieza::Caballo;
}
