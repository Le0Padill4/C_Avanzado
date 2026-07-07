/*
a) No funciona polimorficamente porque enviar() no es virtual enviarTodas() llamaria Notificacion::enviar para todos los elementos
b) La palabra es virtual: virtual void enviar() en la clase Notificacion
c) Con enviar() virtual, NotificacionPush no obliga a cambiar enviarTodas()
Solo se agrega la clase nueva y se implementa enviar()

d) Sin destructor virtual, delete por Notificacion* no destruiria bien la hija
Si la hija tuviera memoria dinamica, podria quedar memoria sin liberar

e) No ocurre slicing porque se usa un puntero Notificacion* a un objeto existente
Slicing ocurre cuando se copia por valor, no cuando se apunta o referencia

*/
