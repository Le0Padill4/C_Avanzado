#include <iostream>

int main(){
    int n;
    int posi = 0;
    int nega = 0;
    while (n != 0)
    {    
        std::cin >> n;
        if (n > 0){
            posi++;
        }
        else if (n < 0){
            nega++;
        }
    }
    std::cout << "Positivos: " << posi << std::endl;
    std::cout << "Negativos: " << nega << std::endl;
    return 0;
}