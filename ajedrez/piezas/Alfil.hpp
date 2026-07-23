#ifndef ALFIL_HPP
#define ALFIL_HPP

#include "../Pieza.hpp"

// El alfil se mueve solamente en diagonal
class Alfil : public Pieza {
public:
    // Recibe el color y lo pasa a la clase base Pieza
    explicit Alfil(Color color);

    // Revisa que el destino esté en diagonal y que el camino esté libre
    bool puedeMover(const Posicion& origen, const Posicion& destino,
                    const Tablero& tablero) const override;

    // Devuelve A para blanco y a para negro
    char obtenerSimbolo() const override;

    // Identifica esta pieza como alfil
    TipoPieza obtenerTipo() const override;
};

#endif
