#include <iostream>

int main(){

    do{
        std::cout << "Ingrese un nota(0-100): ";
        int nota;
        std::cin >> nota;

        if(nota < 0 or nota > 100){
            std::cout << "Valor invalido. Intente de nuevo." << std::endl;
        } else {
            std::cout << "Nota aceptada: " << nota << std::endl;
            break; 
        }
    } while (true);

    return 0;
}