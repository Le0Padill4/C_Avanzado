/*
a) Salida:
Entero: 42
Double: 3.14
Texto: hola
Suma: 7

b) Hay 4 versiones de imprimir(). Se diferencian por la lista de parametros: int, double, string, 2 ints

c) En la etapa de compilacion.

d) void imprimir(bool b) {
        if (b) {
            printf("Verdadero\n");
        } else {
            printf("Falso\n");
        }
    }

Si se llamara imp.imprimir("hola"), "hola" es const char*.
El compilador puede preferir convertir ese puntero a bool antes que construir un string
*/