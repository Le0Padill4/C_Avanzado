/* 
Fragmento A: no compila. Animal es abstracta por hablar() = 0
Correccion A: crear una clase hija que implemente hablar(), o no instanciar Animal

Fragmento B: no compila. habla() override no coincide con hablar()
Correccion B: habla() por hablar() en Perro

Fragmento C: compila, pero delete por Animal* sin destructor virtual puede causar problemas de memoria
Correccion C: declarar virtual ~Animal() para que tambien se llame ~Perro()

Fragmento D: no compila. Circulo sigue siendo abstracta porque no implementa area()
Correccion D: agregar double area() override en Circulo

*/