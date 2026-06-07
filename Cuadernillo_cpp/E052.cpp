#include <iostream>
#include <cctype>

std::string invertir(std::string palabra) {
    std::string invertida = "";

    for (int i = palabra.length() - 1; i >= 0; i--) {
        invertida += std::tolower(palabra[i]);
    }

    return invertida;
}

int main() {
    std::string palabra;
    std::string palabraMinuscula = "";

    std::cin >> palabra;

    for (int i = 0; i < palabra.length(); i++) {
        palabraMinuscula += std::tolower(palabra[i]);
    }

    if (palabraMinuscula == invertir(palabra)) {
        std::cout << "\"" << palabra << "\" es palindromo." << std::endl;
    } else {
        std::cout << "\"" << palabra << "\" no es palindromo." << std::endl;
    }

    return 0;
}