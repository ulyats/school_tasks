#include <iostream>

class Pair {
public:
    int a;
    int b;
    Pair(const int c, const int d): a(c), b(d){}
    ~Pair() {}
    Pair(const Pair& cat): a(cat.a), b(cat.b){}
    void output(){
        std::cout << a << b;
    }
    Pair& operator*=(int dog){
        a *= dog;
        b *= dog;
        return *this;
    }
};
int main(){
    Pair e(2, 7);
    (e *= 10) *= 20;
    e.output();
    return 0;
}

