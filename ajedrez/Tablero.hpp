#ifndef TABLERO_HPP
#define TABLERO_HPP

#include "Movimiento.hpp"
#include "Pieza.hpp"

class Tablero {
private:
    // Cada casilla guarda un puntero a una pieza
    // Si la casilla está vacía, el puntero contiene nullptr
    Pieza* casillas[8][8];

public:
    // El constructor crea y coloca todas las piezas en sus posiciones iniciales
    Tablero();

    // El destructor libera la memoria de las piezas que todavía se encuentran en el tablero
    ~Tablero();

    Tablero(const Tablero&) = delete;
    Tablero& operator=(const Tablero&) = delete;

    // Muestra el tablero y los símbolos de las piezas en consola
    void mostrar() const;

    // Comprueba que una posición se encuentre dentro de las 8 filas y 8 columnas
    bool posicionValida(const Posicion& posicion) const;

    // Devuelve la pieza que está en una posición.
    // Si la casilla está vacía o no existe, devuelve nullptr
    Pieza* obtenerPieza(const Posicion& posicion) const;

    // Indica si una casilla no contiene ninguna pieza
    bool estaVacia(const Posicion& posicion) const;

    // Comprueba si en la posición existe una pieza del mismo color que el jugador
    bool contieneAliada(
        const Posicion& posicion,
        Color color
    ) const;

    // Comprueba si en la posición existe una pieza de un color diferente
    bool contieneEnemiga(
        const Posicion& posicion,
        Color color
    ) const;

    // Revisa que no existan piezas entre el origen y el destino
    // Esta función se usa principalmente para la torre, el alfil y la reina
    bool caminoLibre(
        const Posicion& origen,
        const Posicion& destino
    ) const;

    // Mueve una pieza de forma directa.
    // Si captura al rey, lo avisa con reyCapturado.
    bool moverPieza(
        const Movimiento& movimiento,
        bool& reyCapturado
    );

    // Reemplaza un peón que llegó a la última fila
    // por la pieza elegida por el jugador
    void promoverPeon(
        const Posicion& posicion,
        TipoPieza tipo
    );
};

#endif
