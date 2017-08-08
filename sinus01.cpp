//sinus01(x)
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double sinus(double x, int n){
    int num = 0;
    double s = 0;
    double piece = x;
    for(int i = 1; i <= n; i++){
        s = s + piece;
        num = num + 2;
        piece = -piece * x * x/(num * (num + 1));
        }
    return s;
}

int main(){
    double x;
    int n = 7;
    cout << "enter x =";
    cin >> x;
    cout << "\n";
    for(int i = 1; i <= n; i++){
        cout << i << ":sin("<< x <<") = " << sinus(x, i) << endl;
        }
    cout << "\n";
    cout << "Test value:" << sin(x) << endl;
    return 0;
}
