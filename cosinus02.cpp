//cosinus02(x)
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double cosinus(double x){
    int num = 0;
    double eps = 0.0000001;
    double s = 0;
    double piece = 1;
    while((-eps > piece) || (piece > eps)){
        s = s + piece;
        num = num + 2;
        piece = -piece * x * x/((num - 1) * num);
        }
    return s;
}

int main(){
    double x;
    cout << "enter x =";
    cin >> x;
    cout << "\n";
    cout << "value:" << cosinus(x) << endl;
    cout << "\n";
    cout << "Test value:" << cos(x) << endl;
    return 0;
}
