#ifndef POSICION_HPP
#define POSICION_HPP

// Esta estructura guarda una posición dentro del tablero
// La fila y la columna tendrán valores entre 0 y 7
struct Posicion {
    // Fila de la matriz del tablero
    int fila;

    // Columna de la matriz del tablero
    int columna;

    // Compara dos posiciones.
    // Retorna true si tienen la misma fila y la misma columna
    bool operator==(const Posicion& otra) const {
        return fila == otra.fila and
               columna == otra.columna;
    }

    // Comprueba si dos posiciones son diferentes
    // Reutilizamos el operador == y negamos su resultado
    bool operator!=(const Posicion& otra) const {
        return not (*this == otra);
    }
};

#endif
