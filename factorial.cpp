#include <iostream>

int factorial(int number){
    if (number == 0) {
        return 1;
    }
    return factorial(number - 1) * number;


}
int main() {
    int number(10);
    std::cout << factorial(number);
    return 0;
}

