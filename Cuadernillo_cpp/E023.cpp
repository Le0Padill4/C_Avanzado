#include <iostream>

int main() {
    int num;
    int p = 0;
    int s = 1;
    int next;

    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        if (i == 1) {
            std::cout << p << " ";
        } 
        else if (i == 2) {
            std::cout << s << " ";
        } 
        else {
            next = p + s;
            std::cout << next << " ";
            p = s;
            s = next;
        }
    }

    std::cout << std::endl;

    return 0;
}