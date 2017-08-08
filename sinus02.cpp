//sinus02(x)
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double sinus(double x){
    int num = 0;
    double eps = 0.0000001;
    double s = 0;
    double piece = x;
    while((-eps > piece) || (piece > eps)){
        s = s + piece;
        num = num + 2;
        piece = -piece * x * x/(num * (num + 1));
        }
    return s;
}

int main(){
    double x;
    cout << "enter x =";
    cin >> x;
    cout << "\n";
    cout << "value:" << sinus(x) << endl;
    cout << "\n";
    cout << "Test value:" << sin(x) << endl;
    return 0;
}
