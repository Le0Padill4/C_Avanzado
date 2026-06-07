#include <iostream>
#include <string>

int main() {
    int n;
    std::string nombres[100];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> nombres[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". " << nombres[i] << std::endl;
    }

    return 0;
}