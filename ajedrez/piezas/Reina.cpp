#include "Reina.hpp"
#include "../Tablero.hpp"
#include "../Utilidades.hpp"

Reina::Reina(Color color) : Pieza(color) {
}

bool Reina::puedeMover(const Posicion& origen, const Posicion& destino,
                       const Tablero& tablero) const {
    // La reina puede moverse recto o en diagonal.
    int filas = valorAbsoluto(destino.fila - origen.fila);
    int columnas = valorAbsoluto(destino.columna - origen.columna);
    bool movimientoRecto = origen.fila == destino.fila or
                           origen.columna == destino.columna;
    bool movimientoDiagonal = filas == columnas;

    // Si no es recto ni diagonal, no es un movimiento de reina
    if (origen == destino or (not movimientoRecto and not movimientoDiagonal)) {
        return false;
    }

    if (tablero.contieneAliada(destino, obtenerColor())) {
        return false;
    }

    // Como la reina no salta, el camino debe estar vacío
    return tablero.caminoLibre(origen, destino);
}

char Reina::obtenerSimbolo() const {
    // Usamos D por dama para no repetir la R del rey
    return obtenerColor() == Color::Blanco ? 'D' : 'd';
}

TipoPieza Reina::obtenerTipo() const {
    return TipoPieza::Reina;
}
