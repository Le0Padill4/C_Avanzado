#include <iostream>

double celsiusAFahrenheit(double c){
    return (c * 9.0 / 5.0) + 32.0;
}
double fahrenheitACelsius(double f){
    return (f - 32.0) * 5.0 / 9.0;
}
void mostrarConversion(double valor, char tipo){
    if(tipo == 'C'){
        std::cout << valor << " equivale a " << celsiusAFahrenheit(valor) << " F" << std::endl;
    }
    else if(tipo == 'F'){
        std::cout << valor << " equivale a " << fahrenheitACelsius(valor) << " C" << std::endl;
    }
}

int main(){
    double valor;
    char tipo;
    std::cin>>valor>>tipo;
    mostrarConversion(valor, tipo);

    return 0;
}