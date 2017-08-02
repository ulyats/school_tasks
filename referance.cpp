#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Hello, I am constructor\n";
    }

    MyClass(const MyClass&) {
        std::cout << "Hello, I am copy constructor\n";
    }
};

void FuncWithoutCopyArguments(const MyClass& var) {
    std::cout << "Hello, I am FuncWithoutCopyArguments\n";
}

void FuncWithCopyArguments(MyClass var) {
    std::cout << "Hello, I am FuncWithCopyArguments\n";
}


int main(){
    int a(5);
    int& b(a);
    ++b;
    std::cout << a << " " << b << std::endl;
    MyClass var;
    std::cout << "Before calling\n";
    FuncWithoutCopyArguments(var);
    FuncWithCopyArguments(var);
    return 0;
}

