#include <iostream>
using namespace std;
int main(){
    int i;
    double a[3];
    double b[3];
    double res = 0;
    cout << "a = ";
    for(i = 0; i < 3; i++) cin >> a[i];
    cout << "b = ";
    for(i = 0; i < 3; i++) cin >> b[i];
    for(i = 0; i < 3; i++) res += a[i] * b[i];
    cout << "a.b = " << res << endl;
    return 0;
}
