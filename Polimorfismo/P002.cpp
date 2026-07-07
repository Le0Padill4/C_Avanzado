/*
Sin virtual:
- llamada 1: Forma::dibujar
- llamada 2: Circulo::dibujar
- llamada 3: Forma::dibujar
- llamada 4: Forma::dibujar

Con virtual:
- llamada 1: Forma::dibujar
- llamada 2: Circulo::dibujar
- llamada 3: Forma::dibujar
- llamada 4: Circulo::dibujar

La llamada 4 cambia porque el puntero es Forma*, pero el objeto real es Circulo. 
*/
