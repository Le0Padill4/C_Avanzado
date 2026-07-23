#ifndef PEON_HPP
#define PEON_HPP

#include "../Pieza.hpp"

// El peón avanza hacia adelante y captura en diagonal
class Peon : public Pieza {
public:
    // Recibe el color y lo pasa a la clase base Pieza
    explicit Peon(Color color);

    // Revisa avance normal, primer avance doble y captura diagonal
    bool puedeMover(const Posicion& origen, const Posicion& destino,
                    const Tablero& tablero) const override;

    // Devuelve P para blanco y p para negro
    char obtenerSimbolo() const override;

    // Identifica esta pieza como peón
    TipoPieza obtenerTipo() const override;
};

#endif
