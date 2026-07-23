#ifndef PIEZA_HPP
#define PIEZA_HPP
// Incluimos Posicion porque las piezas necesitan conocer desde dónde se mueven y hacia dónde quieren ir
#include "Posicion.hpp"

class Tablero;

// enum class obliga a escribir Color::Blanco o Color::Negro, lo que hace el código más claro
enum class Color {
    Blanco,
    Negro
};

// Tipos de piezas que existen en el juego
enum class TipoPieza {
    Peon,
    Torre,
    Caballo,
    Alfil,
    Reina,
    Rey
};

// Pieza es la clase base de todas las piezas del ajedrez
// No se crearán objetos directamente de esta clase porque es abstracta
class Pieza {
private:
    // Todas las piezas tienen un color para saber de qué jugador son
    Color color;

    // Sirve sobre todo para saber si el peón todavía puede avanzar dos casillas
    bool seHaMovido;

public:
    // Constructor de la pieza
    Pieza(Color colorPieza);

    // Es virtual porque el tablero borra piezas usando punteros Pieza*
    virtual ~Pieza();

    // Devuelve el color de la pieza
    Color obtenerColor() const;

    // Indica si esta pieza ya se movió alguna vez
    bool fueMovida() const;

    // Marca si la pieza ya fue movida
    void establecerMovida(bool estado);

    // Cada pieza debe implementar su propia forma de moverse
    // Por eso Pieza es abstracta y se usa polimorfismo con Pieza*
    virtual bool puedeMover(const Posicion& origen,
    const Posicion& destino,
    const Tablero& tablero) const = 0;

    // Cada pieza decide qué letra se muestra en el tablero
    virtual char obtenerSimbolo() const = 0;

    // Permite saber si una pieza capturada o promocionada es de cierto tipo
    virtual TipoPieza obtenerTipo() const = 0;
};

#endif
