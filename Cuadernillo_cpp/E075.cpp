#include <iostream>

int main() {
    int a = 42;              // Variable en stack
    int* b = new int(42);    // Variable en heap

    std::cout << "Stack: " << a << "    Heap: " << *b << std::endl;

    *b = 99;

    std::cout << "Stack: " << a << "    Heap: " << *b << std::endl;

    delete b;
    b = nullptr;

    std::cout << "Heap liberado." << std::endl;

    return 0;
}