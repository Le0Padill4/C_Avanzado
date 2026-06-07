#include <iostream>

int main() {
    int mes;

    std::cin >> mes;

    switch (mes) {
        case 1:
            std::cout << "Mes 1: Enero" << std::endl;
            break;
        case 2:
            std::cout << "Mes 2: Febrero" << std::endl;
            break;
        case 3:
            std::cout << "Mes 3: Marzo" << std::endl;
            break;
        case 4:
            std::cout << "Mes 4: Abril" << std::endl;
            break;
        case 5:
            std::cout << "Mes 5: Mayo" << std::endl;
            break;
        case 6:
            std::cout << "Mes 6: Junio" << std::endl;
            break;
        case 7:
            std::cout << "Mes 7: Julio" << std::endl;
            break;
        case 8:
            std::cout << "Mes 8: Agosto" << std::endl;
            break;
        case 9:
            std::cout << "Mes 9: Septiembre" << std::endl;
            break;
        case 10:
            std::cout << "Mes 10: Octubre" << std::endl;
            break;
        case 11:
            std::cout << "Mes 11: Noviembre" << std::endl;
            break;
        case 12:
            std::cout << "Mes 12: Diciembre" << std::endl;
            break;
        default:
            std::cout << "Mes invalido" << std::endl;
            break;
    }

    return 0;
}
