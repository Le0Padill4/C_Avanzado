# Ajedrez básico en C++

Proyecto de consola para practicar programación orientada a objetos. Incluye
clases, herencia, polimorfismo, punteros y memoria dinámica. Las piezas se
mueven con reglas básicas y la partida termina cuando un jugador captura al rey
contrario.

No incluye jaque mate real, ahogado, enroque, captura al paso, repetición de
movimientos ni regla de cincuenta movimientos. Mantiene una promoción sencilla
de peones.

## Compilar y ejecutar

```bash
cmake -S . -B build
cmake --build build
./build/ajedrez
```

También se puede compilar directamente con el compilador:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp Juego.cpp Tablero.cpp Pieza.cpp piezas/*.cpp -o ajedrez
./ajedrez
```

Las jugadas se escriben indicando origen y destino, por ejemplo `e2 e4`.
Las piezas blancas usan letras mayúsculas y las negras, minúsculas.
