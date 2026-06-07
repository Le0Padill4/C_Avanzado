#include <iostream>

int main() {
    int n;
    std::cin >> n;
        if (n == 0){
            std::cout << n << "! = 1" << std::endl;
        }
        else {
            int factorial = 1;
            for (int j = 1; j <= n; ++j) {
                factorial *= j;
            }
            std::cout << n << "! = " << factorial << std::endl;
        }
    return 0;
}