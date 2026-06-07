#include <iostream>

std::string invertir(std::string s) {
    std::string invertida = "";

    for (int i = s.length() - 1; i >= 0; i--) {
        invertida += s[i];
    }

    return invertida;
}

int main() {
    std::string palabra;

    std::cin >> palabra;

    std::cout << "Original: " << palabra << std::endl;
    std::cout << "Invertida: " << invertir(palabra) << std::endl;

    return 0;
}