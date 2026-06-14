#include <iostream>
#include <iomanip>

class Matematica {
public:
    static int maximo(int a, int b) {
        if (a > b) {
            return a;
        }

        return b;
    }

    static int minimo(int a, int b) {
        if (a < b) {
            return a;
        }

        return b;
    }

    static bool esPrimo(int n) {
        if (n <= 1) {
            return false;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    static double potencia(double base, int exp) {
        double resultado = 1.0;

        for (int i = 0; i < exp; i++) {
            resultado *= base;
        }

        return resultado;
    }
};

int main() {
    std::cout << "Maximo(8, 3): " << Matematica::maximo(8, 3) << std::endl;
    std::cout << "Minimo(8, 3): " << Matematica::minimo(8, 3) << std::endl;

    std::cout << "Es primo 7: " << (Matematica::esPrimo(7) ? "SI" : "NO") << std::endl;
    std::cout << "Es primo 9: " << (Matematica::esPrimo(9) ? "SI" : "NO") << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "2 elevado a 10: " << Matematica::potencia(2.0, 10) << std::endl;

    return 0;
}