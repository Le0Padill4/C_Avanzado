#include <iostream>
#include <iomanip>

void calcularCirculo(double radio, double &area, double &per){
    const double PI = 3.14159;
    area = PI * radio * radio;
    per = 2 * PI * radio;
    std::cout << std::fixed << std::setprecision(2);
    std::cout<< "Radio: " << radio << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimetro: " << per << std::endl;
}

int main(){
    double n;
    std::cin>> n;
    double area, per;
    calcularCirculo(n, area, per);

    return 0;
}