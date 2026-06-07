#include <iostream>

int main() {
    int n, m;
    int matriz[100][100];

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matriz[i][j];

            if (j < m - 1) {
                std::cout << "  ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}