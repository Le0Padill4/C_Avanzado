#include <iostream>

int main() {
    int nota;
    std::cout << "Nota: ";
    std::cin >> nota;

    if (nota >=90){
        std::cout << "A";
    } else if (nota >=80){
        std::cout << "B";
    } else if (nota >=70){
        std::cout << "C";
    } else if (nota >=60){
        std::cout << "D";
    } else {
        std::cout << "F";
    }
    return 0;
}