#include <iostream>

int main(){
    int arr[] = {3, 6, 9, 12, 15};
    int* p = arr;

    std::cout << "arr[i]: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "*(arr+i): ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(arr + i) << " ";
    }

    std::cout << std::endl;

    std::cout << "p++: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *p << " ";
        p++;
    }

    std::cout << std::endl;

    return 0;
}