#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP

#include "Posicion.hpp"
#include <string>

// Devuelve el valor absoluto de un número
inline int valorAbsoluto(int numero) {
    if (numero < 0) {
        return -numero;
    }

    return numero;
}

// Convierte una letra mayúscula en minúscula
// Si la letra ya está en minúscula o no es una letra
// simplemente se devuelve sin cambios
inline char convertirAMinuscula(char letra) {
    if (letra >= 'A' and letra <= 'Z') {
        return static_cast<char>(
            letra + ('a' - 'A')
        );
    }

    return letra;
}

// Convierte un texto como "e2" en una posición de la matriz
// La letra representa la columna y el número representa la fila
inline bool textoAPosicion(
    const std::string& texto,
    Posicion& posicion
) {
    // Una posición válida siempre debe tener dos caracteres.
    if (texto.length() != 2) {
        return false;
    }

    // Permitimos que el usuario escriba la columna en mayúscula o minúscula.
    char columna = convertirAMinuscula(texto[0]);
    char fila = texto[1];

    // Comprobamos que la columna esté entre a y h y que la fila esté entre 1 y 8.
    if (
        columna < 'a' or columna > 'h' or
        fila < '1' or fila > '8'
    ) {
        return false;
    }

    // Convertimos la letra en una columna entre 0 y 7
    posicion.columna = columna - 'a';

    // El tablero se guarda de arriba hacia abajo,
    // por eso convertimos la fila del ajedrez a la fila de la matriz
    posicion.fila = 8 - (fila - '0');

    return true;
}

#endif
