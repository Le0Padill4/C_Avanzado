#include <iostream>
#include <iomanip>

int main() {
    const double PI = 3.14159;
    double radio;
    double area;
    double perimetro;

    std::cin >> radio;

    area = PI * radio * radio;
    perimetro = 2 * PI * radio;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Radio: " << radio << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimetro: " << perimetro << std::endl;

    return 0;
}