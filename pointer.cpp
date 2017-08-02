#include <iostream>

int main(){
    double a(-5.00313e-138);
    std::cout << &a << std::endl;
    int* b((int*)&a);
    std::cout << b << std::endl;
    std::cout << *b << std::endl;
    std::cout << sizeof(int) << " " << sizeof(double) << std::endl;
    return 0;
}

