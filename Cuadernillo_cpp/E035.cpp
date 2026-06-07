#include <iostream>

bool esPar(int n){
    int resultado = n % 2;
    if(resultado == 0){
        return true;
    }else{
        return false;
    }
}

void imprimirPares(int inicio, int fin){
    for(int i = inicio; i <= fin; i++){
        if(esPar(i)){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main(){
    int inicio, fin;
    std::cin >> inicio >> fin;
    imprimirPares(inicio, fin);
    return 0;
}