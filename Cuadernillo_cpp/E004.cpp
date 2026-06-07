#include <iostream>
#include <iomanip>

int main(){
    double a, b;
    std::cout<<"Entrada: ";
    std::cin>>a>>b;
    std::cout<<std::fixed<<std::setprecision(2);
    std::cout<<"Total a pagar: "<<a+b<<std::endl;
    return 0;
}