#include "Juego.hpp"
#include "Utilidades.hpp"
#include <iostream>
#include <sstream>

// La partida siempre empieza con el turno de las piezas blancas
Juego::Juego() : turnoActual(Color::Blanco) {
}

// Muestra las reglas básicas
void Juego::mostrarInstrucciones() const {
    std::cout << "AJEDREZ BASICO EN CONSOLA\n";
    std::cout << "Ingrese las jugadas con el formato e2 e4.\n";
    std::cout << "Las piezas blancas se muestran con mayusculas.\n";
    std::cout << "Esta version termina cuando un rey es capturado.\n";
    std::cout << "No incluye jaque mate real, ahogado, enroque,\n";
    std::cout << "captura al paso, repeticion de movimientos ni regla de cincuenta movimientos.\n";
}

// Devuelve el nombre del color para mostrarlo en los mensajes
std::string Juego::nombreColor(Color color) const {
    if (color == Color::Blanco) {
        return "blancas";
    }

    return "negras";
}

// Lee una jugada escrita por el usuario, por ejemplo: e2 e4
bool Juego::leerMovimiento(Movimiento& movimiento) {
    std::cout << "Turno de " << nombreColor(turnoActual) << ": ";

    std::string linea;

    // Solo dejamos de leer si la entrada falla, por ejemplo si ya no llega texto
    if (not std::getline(std::cin, linea)) {
        return false;
    }

    // Separamos la entrada en casilla de origen y casilla de destino
    std::istringstream entrada(linea);
    std::string origen;
    std::string destino;
    std::string sobrante;

    // También comprobamos que el usuario no escriba información adicional
    if (not (entrada >> origen >> destino) or (entrada >> sobrante)) {
        std::cout << "Formato incorrecto. Ejemplo: e2 e4\n";

        // Usamos una posición inválida para que el programa ignore esta jugada
        movimiento.origen = {-1, -1};

        return true;
    }

    // Convertimos textos como e2 en posiciones de la matriz
    if (
        not textoAPosicion(origen, movimiento.origen) or
        not textoAPosicion(destino, movimiento.destino)
    ) {
        std::cout << "Las casillas deben estar entre a1 y h8.\n";
        movimiento.origen = {-1, -1};
    }

    return true;
}

// Comprueba que la pieza exista, sea del jugador actual y tenga permitido realizar ese movimiento
bool Juego::movimientoBasicoValido(
    const Movimiento& movimiento,
    Color color
) const {
    if (
        not tablero.posicionValida(movimiento.origen) or
        not tablero.posicionValida(movimiento.destino)
    ) {
        return false;
    }

    Pieza* pieza = tablero.obtenerPieza(movimiento.origen);

    if (pieza == nullptr or pieza->obtenerColor() != color) {
        return false;
    }

    // Gracias al polimorfismo, cada pieza revisa su propio movimiento
    return pieza->puedeMover(
        movimiento.origen,
        movimiento.destino,
        tablero
    );
}

// Permite cambiar un peón cuando llega al extremo contrario del tablero
void Juego::realizarPromocion(const Posicion& posicion) {
    Pieza* pieza = tablero.obtenerPieza(posicion);

    // Solo se puede promocionar una pieza que realmente sea un peón
    if (
        pieza == nullptr or
        pieza->obtenerTipo() != TipoPieza::Peon
    ) {
        return;
    }

    // El peón debe haber llegado a la primera o última fila
    if (posicion.fila != 0 and posicion.fila != 7) {
        return;
    }

    char opcion = 'D';

    // Seguimos preguntando hasta recibir una opción válida
    while (true) {
        std::cout
            << "Promocion "
            << "(D = Reina, T = Torre, A = Alfil, C = Caballo): ";

        std::string linea;
        std::getline(std::cin, linea);

        if (linea.length() == 1) {
            opcion = convertirAMinuscula(linea[0]);

            if (
                opcion == 'd' or
                opcion == 't' or
                opcion == 'a' or
                opcion == 'c'
            ) {
                break;
            }
        }

        std::cout << "Opcion no valida.\n";
    }

    // La reina es la opción inicial si el jugador escribe D
    TipoPieza tipo = TipoPieza::Reina;

    if (opcion == 't') {
        tipo = TipoPieza::Torre;
    } else if (opcion == 'a') {
        tipo = TipoPieza::Alfil;
    } else if (opcion == 'c') {
        tipo = TipoPieza::Caballo;
    }

    tablero.promoverPeon(posicion, tipo);
}

void Juego::iniciar() {
    mostrarInstrucciones();

    bool partidaTerminada = false;

    while (not partidaTerminada) {
        tablero.mostrar();

        Movimiento movimiento;

        // leerMovimiento solo devuelve false si no pudo leer desde la consola.
        if (not leerMovimiento(movimiento)) {
            break;
        }

        // Una entrada incorrecta deja el origen con valores inválidos
        if (not tablero.posicionValida(movimiento.origen)) {
            continue;
        }

        if (not tablero.posicionValida(movimiento.destino)) {
            std::cout << "Las casillas deben estar entre a1 y h8.\n";
            continue;
        }

        if (movimiento.origen == movimiento.destino) {
            std::cout
                << "El origen y el destino no pueden ser iguales.\n";
            continue;
        }

        Pieza* pieza = tablero.obtenerPieza(movimiento.origen);

        if (pieza == nullptr) {
            std::cout << "No hay una pieza en esa posicion.\n";
            continue;
        }

        // Cada jugador solo puede mover sus propias piezas
        if (pieza->obtenerColor() != turnoActual) {
            std::cout << "Esa pieza no corresponde a su turno.\n";
            continue;
        }

        if (tablero.contieneAliada(movimiento.destino, turnoActual)) {
            std::cout << "No puede capturar una pieza propia.\n";
            continue;
        }

        if (not movimientoBasicoValido(movimiento, turnoActual)) {
            std::cout << "Movimiento invalido para esa pieza.\n";
            continue;
        }

        bool reyCapturado = false;

        // El tablero mueve la pieza y elimina una pieza rival si la había
        tablero.moverPieza(movimiento, reyCapturado);

        // Después del movimiento revisamos si el peón debe promocionar
        realizarPromocion(movimiento.destino);

        if (reyCapturado) {
            tablero.mostrar();

            std::cout
                << "El rey fue capturado. Fin de la partida.\n";

            // La partida solo termina cuando se captura al rey contrario.
            partidaTerminada = true;
        } else {
            // Si la partida continúa, cambiamos el turno
            turnoActual =
                turnoActual == Color::Blanco
                    ? Color::Negro
                    : Color::Blanco;
        }
    }
}
