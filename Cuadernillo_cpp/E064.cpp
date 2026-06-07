#include <iostream>

int main() {
    int x = 100;
    int* p = &x;
    int** pp = &p;

    std::cout << "x   = " << x << std::endl;
    std::cout << "*p  = " << *p << std::endl;
    std::cout << "**pp = " << **pp << std::endl;

    return 0;
}