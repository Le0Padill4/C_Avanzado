#include "Pieza.hpp"

// Al crear una pieza todavía no se ha movido
Pieza::Pieza(Color colorPieza) : color(colorPieza), seHaMovido(false) {
}

// El destructor queda vacío, pero debe existir para borrar hijos con Pieza*
Pieza::~Pieza() {
}

// Devuelve si la pieza es blanca o negra
Color Pieza::obtenerColor() const {
    return color;
}

// Se usa para reglas sencillas como el primer movimiento del peón
bool Pieza::fueMovida() const {
    return seHaMovido;
}

// El tablero marca una pieza como movida después de moverla
void Pieza::establecerMovida(bool estado) {
    seHaMovido = estado;
}
