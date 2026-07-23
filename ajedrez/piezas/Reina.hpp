#ifndef REINA_HPP
#define REINA_HPP

#include "../Pieza.hpp"

// La reina combina el movimiento de torre y alfil
class Reina : public Pieza {
public:
    // Recibe el color y lo pasa a la clase base Pieza
    explicit Reina(Color color);

    // Revisa movimientos rectos o diagonales con camino libre
    bool puedeMover(const Posicion& origen, const Posicion& destino,
                    const Tablero& tablero) const override;

    // Devuelve D para blanco y d para negro
    char obtenerSimbolo() const override;

    // Identifica esta pieza como reina
    TipoPieza obtenerTipo() const override;
};

#endif
