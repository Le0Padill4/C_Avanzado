#include <iostream>
#include <cctype>

bool esVocal(char c) {
    c = static_cast<char>(std::tolower(c));

    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
    char palabra[] = "programacion";
    char* p = palabra;

    int longi = 0;
    int vocales = 0;

    while (*p != '\0') {
        longi++;
        p++;
    }

    std::cout << "Longitud  : " << longi << std::endl;
    p = palabra;

    std::cout << "Mayusculas: ";
    while (*p != '\0') {
        char mayuscula = static_cast<char>(std::toupper(*p));
        std::cout << mayuscula;
        p++;
    }

    std::cout << std::endl;

    p = palabra;

    while (*p != '\0') {
        if (esVocal(*p)) {
            vocales++;
        }
        p++;
    }

    std::cout << "Vocales   : " << vocales << std::endl;

    return 0;
}