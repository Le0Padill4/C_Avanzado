#include <iostream>

int main(){
    int n;
    std::cin >> n;
    if (n <0){
        std::cout << "Número negativo" << std::endl;
    }
    int cont = 0;
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            cont++;
        }    }
    if (cont == 2){ 
        std::cout << n <<" Es primo" << std::endl;
    } else {
        std::cout << n <<" No es primo" << std::endl;
    }


    return 0;
}