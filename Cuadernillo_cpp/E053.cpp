#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::string nombres[100];
    double notas[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> nombres[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> notas[i];
    }

    int indiceMejor = 0;

    for (int i = 1; i < n; i++) {
        if (notas[i] > notas[indiceMejor]) {
            indiceMejor = i;
        }
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Mejor estudiante: "
              << nombres[indiceMejor]
              << " con nota "
              << notas[indiceMejor]
              << std::endl;

    return 0;
}