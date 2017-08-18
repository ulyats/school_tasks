//root01.cpp
#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    double y;
    y = (x - 1)*(x - 1)*(x - 1);
    return y;
}

int main(){
    double x, x1, x2, y1, y2, y, eps;
    eps = 0.001;

    x1 = 0.0;
    x2 = 2.0;
    y1 = f(x1);
    y2 = f(x2);
    if (0 < y1 * y2)
      cout << "no root" << endl;
    if ((-eps < y1) && (y1 < eps))
      cout << "x = " << x1 << endl;
    if ((-eps < y2) && (y2 < eps))
      cout << "x = " << x2 << endl;

    while (eps < (x2-x1)) {
    x = (x1 + x2) / 2;
    y = f(x);
    if (y1 * y < 0.0)
      x2 = x;
    else
      x1 = x;
    }
    cout << "x = " << x << endl;

    return 0;
}
