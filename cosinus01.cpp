//cosinus01(x)
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double cosinus(double x, int n){
    int num = 0;
    double s = 0;
    double piece = 1;
    for(int i = 1; i <= n; i++){
        s = s + piece;
        num = num + 2;
        piece = -piece * x * x/((num - 1) * num);
        }
    return s;
}

int main(){
    double x;
    int n = 3;
    cout << "enter x =";
    cin >> x;
    cout << "\n";
    for(int i = 1; i <= n; i++){
        cout << i << ":cos("<< x <<") = " << cosinus(x, i) << endl;
        }
    cout << "\n";
    cout << "Test value:" << cos(x) << endl;
    return 0;
}
