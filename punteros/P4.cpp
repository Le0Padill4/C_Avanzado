#include <iostream>

int main() {
    int entero = 42;
    double decimal = 3.14;
    char letra = 'A';
    bool booleano = true;

    int* puntero = &entero;
    double* pundecimal = &decimal;
    char* punlerta = &letra;
    bool* punbool = &booleano;

    std:: cout << "int: valor=" << entero << " dir=" << puntero<< " *ptr=" << *puntero << std::endl;

    std::cout << "double: valor=" << decimal << " dir=" << pundecimal << " *ptr=" << *pundecimal << std::endl;

    std::cout << "char: valor=" << letra << " dir=" << static_cast<void*>(punlerta) << " *ptr=" << *punlerta << std::endl;

    std::cout << "bool: valor=" << booleano << " dir=" << punbool << " *ptr=" << *punbool << std::endl;
    return 0;
}