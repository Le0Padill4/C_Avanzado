#include "Tablero.hpp"
#include "piezas/Alfil.hpp"
#include "piezas/Caballo.hpp"
#include "piezas/Peon.hpp"
#include "piezas/Reina.hpp"
#include "piezas/Rey.hpp"
#include "piezas/Torre.hpp"
#include <iostream>

Tablero::Tablero() {
    // Primero dejamos todas las casillas vacías.
    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            casillas[fila][columna] = nullptr;
        }
    }

    // Usamos new porque cada casilla guarda un puntero a Pieza.
    for (int columna = 0; columna < 8; columna++) {
        casillas[1][columna] = new Peon(Color::Negro);
        casillas[6][columna] = new Peon(Color::Blanco);
    }

    // Colocamos las piezas negras en la parte superior de la matriz.
    casillas[0][0] = new Torre(Color::Negro);
    casillas[0][1] = new Caballo(Color::Negro);
    casillas[0][2] = new Alfil(Color::Negro);
    casillas[0][3] = new Reina(Color::Negro);
    casillas[0][4] = new Rey(Color::Negro);
    casillas[0][5] = new Alfil(Color::Negro);
    casillas[0][6] = new Caballo(Color::Negro);
    casillas[0][7] = new Torre(Color::Negro);

    // Las piezas blancas empiezan en la parte inferior del tablero.
    casillas[7][0] = new Torre(Color::Blanco);
    casillas[7][1] = new Caballo(Color::Blanco);
    casillas[7][2] = new Alfil(Color::Blanco);
    casillas[7][3] = new Reina(Color::Blanco);
    casillas[7][4] = new Rey(Color::Blanco);
    casillas[7][5] = new Alfil(Color::Blanco);
    casillas[7][6] = new Caballo(Color::Blanco);
    casillas[7][7] = new Torre(Color::Blanco);
}

Tablero::~Tablero() {
    // Borramos todas las piezas que sigan vivas para evitar fuga de memoria
    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            delete casillas[fila][columna];
            casillas[fila][columna] = nullptr;
        }
    }
}

void Tablero::mostrar() const {
    std::cout << "\n    a b c d e f g h\n";
    std::cout << "   -----------------\n";
    for (int fila = 0; fila < 8; fila++) {
        std::cout << " " << 8 - fila << " |";
        for (int columna = 0; columna < 8; columna++) {
            // nullptr significa que no hay pieza en esa casilla
            if (casillas[fila][columna] == nullptr) {
                std::cout << ".";
            } else {
                std::cout << casillas[fila][columna]->obtenerSimbolo();
            }
            std::cout << " ";
        }
        std::cout << "| " << 8 - fila << "\n";
    }
    std::cout << "   -----------------\n";
    std::cout << "    a b c d e f g h\n\n";
}

bool Tablero::posicionValida(const Posicion& posicion) const {
    return posicion.fila >= 0 and posicion.fila < 8 and
           posicion.columna >= 0 and posicion.columna < 8;
}

Pieza* Tablero::obtenerPieza(const Posicion& posicion) const {
    if (not posicionValida(posicion)) {
        return nullptr;
    }
    return casillas[posicion.fila][posicion.columna];
}

bool Tablero::estaVacia(const Posicion& posicion) const {
    return obtenerPieza(posicion) == nullptr;
}

bool Tablero::contieneAliada(const Posicion& posicion, Color color) const {
    Pieza* pieza = obtenerPieza(posicion);
    return pieza != nullptr and pieza->obtenerColor() == color;
}

bool Tablero::contieneEnemiga(const Posicion& posicion, Color color) const {
    Pieza* pieza = obtenerPieza(posicion);
    return pieza != nullptr and pieza->obtenerColor() != color;
}

bool Tablero::caminoLibre(const Posicion& origen, const Posicion& destino) const {
    int pasoFila = 0;
    int pasoColumna = 0;

    // Calculamos en qué dirección avanzar dentro de la matriz
    if (destino.fila > origen.fila) {
        pasoFila = 1;
    } else if (destino.fila < origen.fila) {
        pasoFila = -1;
    }
    if (destino.columna > origen.columna) {
        pasoColumna = 1;
    } else if (destino.columna < origen.columna) {
        pasoColumna = -1;
    }

    Posicion actual = {origen.fila + pasoFila, origen.columna + pasoColumna};

    // Revisamos las casillas intermedias, sin contar origen ni destino
    while (actual != destino) {
        if (not estaVacia(actual)) {
            return false;
        }
        actual.fila += pasoFila;
        actual.columna += pasoColumna;
    }
    return true;
}

bool Tablero::moverPieza(const Movimiento& movimiento, bool& reyCapturado) {
    reyCapturado = false;

    Pieza* piezaMovida =
        casillas[movimiento.origen.fila][movimiento.origen.columna];

    if (piezaMovida == nullptr) {
        return false;
    }

    Pieza* piezaCapturada =
        casillas[movimiento.destino.fila][movimiento.destino.columna];

    // La partida termina solo si la pieza capturada es un rey
    if (piezaCapturada != nullptr and
        piezaCapturada->obtenerTipo() == TipoPieza::Rey) {
        reyCapturado = true;
    }

    // Si había una pieza rival en el destino, la eliminamos
    delete piezaCapturada;

    casillas[movimiento.destino.fila][movimiento.destino.columna] =
        piezaMovida;

    // Dejamos la casilla anterior vacía
    casillas[movimiento.origen.fila][movimiento.origen.columna] = nullptr;

    piezaMovida->establecerMovida(true);
    return true;
}

void Tablero::promoverPeon(const Posicion& posicion, TipoPieza tipo) {
    Pieza* peon = obtenerPieza(posicion);
    if (peon == nullptr) {
        return;
    }

    // Guardamos el color antes de borrar el peón
    Color color = peon->obtenerColor();
    delete peon;
    casillas[posicion.fila][posicion.columna] = nullptr;

    // Creamos con new la pieza elegida y la dejamos en la misma casilla
    if (tipo == TipoPieza::Torre) {
        casillas[posicion.fila][posicion.columna] = new Torre(color);
    } else if (tipo == TipoPieza::Alfil) {
        casillas[posicion.fila][posicion.columna] = new Alfil(color);
    } else if (tipo == TipoPieza::Caballo) {
        casillas[posicion.fila][posicion.columna] = new Caballo(color);
    } else {
        casillas[posicion.fila][posicion.columna] = new Reina(color);
    }
    casillas[posicion.fila][posicion.columna]->establecerMovida(true);
}
