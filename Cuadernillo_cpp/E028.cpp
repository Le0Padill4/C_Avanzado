#include <iostream>
#include <iomanip>

double calcularIMC(double peso, double altura){
    double IMC;
    IMC = peso / (altura * altura);
    return IMC;
}
int main(){
    double peso, altura;
    std::cin >> peso >> altura;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "IMC: " << calcularIMC(peso, altura) << std::endl;
    return 0;
}