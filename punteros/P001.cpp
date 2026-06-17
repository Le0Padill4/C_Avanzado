#include <iostream>

int main(){
    int num = 25;
    int* puntero = &num;

    std:: cout << "Valor: " << num << std::endl;
    std:: cout << "Dirección: " << &num << std::endl;
    std:: cout << "Dirección en el puntero: " << puntero << std::endl;
    std:: cout << "Valor al que apunta: " << *puntero << std::endl;

    return 0;
}