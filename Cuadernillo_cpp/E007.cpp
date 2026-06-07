#include <iostream>
#include <iomanip>

int main(){
    double celsius;
    std::cout << "Ingresa la temperatura en celsius: ";
    std::cin >> celsius;
    double fahrenheit = (celsius * 9/5) + 32;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << celsius <<" C = " << fahrenheit << " F" << std::endl;
    return 0;
}