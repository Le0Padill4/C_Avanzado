#include <iostream>

int cuadrado(int num){
    return num * num;
}


int main(){
    int num;
    std::cin>> num;
    std::cout<< "El cuadrado de " << num << " es " << cuadrado(num) << std::endl;

    return 0;
}