#include <iostream>

int main(){
    int a;
    std ::cout << "Entrada: " << std::endl;
    std ::cin >> a;
    if (a > 0){
        std ::cout << "El numero es positivo" << std ::endl;
    } else if (a < 0){
        std ::cout << "El numero es negativo" << std ::endl;
    } else {
        std ::cout << "El numero es cero" << std ::endl;
    }

}