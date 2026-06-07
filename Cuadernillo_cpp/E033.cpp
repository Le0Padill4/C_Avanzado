#include <iostream>
#include <iomanip>

double mayor(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

double mayor(double a, double b, double c) {
    double mayorValor = a;

    if (b > mayorValor) {
        mayorValor = b;
    }

    if (c > mayorValor) {
        mayorValor = c;
    }

    return mayorValor;
}

int main() {
    double a, b;
    double x, y, z;

    std::cin >> a >> b;
    std::cin >> x >> y >> z;

    std::cout << "Mayor de 2: " << mayor(a, b) << std::endl;
    std::cout << "Mayor de 3: " << mayor(x, y, z) << std::endl;

    return 0;
}