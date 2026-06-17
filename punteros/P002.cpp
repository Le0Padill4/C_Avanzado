#include <iostream>

int main(){
    int x = 10;
    int* p = &x;
    std::cout << "x antes: " << x << std::endl;
    *p = 50;
    std::cout << "x despues: " << x << std::endl;

    *p = 200;
    std::cout << "x final: " << x << std::endl;

    return 0;
}