#include <iostream>
using namespace std;
int main(){
    int i;
    double a[3];
    double b[3];
    double c[3];
    cout << "a = ";
    for(i = 0; i < 3; i++) cin >> a[i];
    cout << "b = ";
    for(i = 0; i < 3; i++) cin >> b[i];
    for(i = 0; i < 3; i++) c[i]=a[(i + 1) % 3] * b[(i + 2) % 3] - a[(i + 2) % 3] * b[(i + 1) % 3];
    cout << "[a.b] =";
    for(i = 0; i < 3; i++)
       cout << " " << c[i];
    cout << endl;
    return 0;
}
