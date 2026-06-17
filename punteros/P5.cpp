#include <iostream>

int main(){
    int x = 5, y =10, z =15;
    int* p = &x;

    std:: cout << "x: *p=" << *p << "  x=" << x << std:: endl;
    
    *p = 99;
    std:: cout << "Modificar *p=99: x=" << x << std:: endl;

    p = &y;
    std::cout << "y: *p=" << *p << "  y=" << y << std::endl;

    *p = 88;
    std::cout << "Modificar *p=88: y=" << y << std::endl;

    p = &z;
    std::cout << "z: *p=" << *p << "  z=" << z << std::endl;

    *p = 77;
    std::cout << "Modificar *p=77: z=" << z << std::endl;


    return 0;
}