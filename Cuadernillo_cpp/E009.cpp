#include <iostream>
#include <iomanip>

int main() {
    int a, b, c;
    double prom;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    prom = (double)(a + b + c) / 3;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Promedio: " << prom << std::endl;

    return 0;
}