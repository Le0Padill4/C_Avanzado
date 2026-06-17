#include <iostream>

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;

    std::cout << "*(p + i):" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << *(p + i) << " ";
    }

    std::cout << std::endl;

    p = arr;

    std::cout << "p++:" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << *p << " ";
        p++;
    }

    std::cout << std::endl;

    return 0;
}