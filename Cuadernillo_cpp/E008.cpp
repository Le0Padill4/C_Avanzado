#include <iostream>

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string nom;
    int edad;
    double estat;

    std::cin >> nom;
    std::cin >> edad;
    std::cin >> estat;

    std::cout << "=== Ficha Personal ===" << std::endl;
    std::cout << "Nombre  : " << nom << std::endl;
    std::cout << "Edad    : " << edad << " años" << std::endl;
    std::cout << "Estatura: " << estat << " m" << std::endl;

    return 0;
}