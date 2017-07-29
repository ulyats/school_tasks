#include <iostream>

int main(){
    int a, b, x(1);
    std::cin >> a >> b;
    while(b > 0){
        if(b % 2 == 0) {
            b = b / 2;
            a = a * a;
        } else {
            --b;
            x = x * a;
        }
    }

    std::cout << x;
    return 0;

}
