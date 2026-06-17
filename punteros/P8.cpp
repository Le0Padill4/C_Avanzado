#include <iostream>

int main(){
    int x = 42;
    int* p = &x;
    int** pp = &p;

    std::cout << "x    = " << x << std::endl;
    std::cout << "*p   = " << *p << std::endl;
    std::cout << "**pp = " << **pp << std::endl;
    std::cout << "dir x via &x : " << &x << std::endl;
    std::cout << "dir x via p  : " << p << std::endl;
    std::cout << "dir x via *pp: " << *pp << std::endl;
    std::cout << "dir p via &p : " << &p << std::endl;
    std::cout << "dir p via pp : " << pp << std::endl;

    **pp = 99;

    std::cout << "x despues de **pp=99: " << x << std::endl;
    return 0;  
}