#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "Tablero.hpp"
#include <string>

// Esta clase controla la partida completa: turnos, entrada del usuario y cierre del juego
class Juego {
private:
    // El tablero guarda las piezas y sabe moverlas de una casilla a otra
    Tablero tablero;

    // Indica a quién le toca jugar en este momento
    Color turnoActual;

    // Muestra las instrucciones iniciales para escribir jugadas
    void mostrarInstrucciones() const;

    // Lee una línea como "e2 e4" y la convierte en un movimiento
    bool leerMovimiento(Movimiento& movimiento);

    // Revisa las reglas comunes antes de permitir que una pieza se mueva
    bool movimientoBasicoValido(const Movimiento& movimiento, Color color) const;

    // Cambia un peón por otra pieza cuando llega al final del tablero
    void realizarPromocion(const Posicion& posicion);

    // Devuelve el nombre del color para los mensajes de turno
    std::string nombreColor(Color color) const;

public:
    // Crea una partida nueva con las blancas empezando
    Juego();

    // Ejecuta el ciclo principal hasta que un rey sea capturado
    void iniciar();
};

#endif
