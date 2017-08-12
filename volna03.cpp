//labirint03.cpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>

int m, n;
int  a[20][20];
int b1[20][20];
int b2[20][20];
int b3[20][20];

void clear(void){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
        if(a[i][j] != 1) a[i][j] = 0;
        }
    }
}

int wave(int iA, int jA, int iB, int jB){
    int mark = 0;
    int num = 2;
    a[iA][jA] = num;
    for(int k = 0; k <= m * n; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == num){
                    if(a[i + 1][j] == 0){
                      a[i + 1][j] = num + 1;
                      mark = 1;
                     }
                     if(a[i - 1][j] == 0){
                      a[i - 1][j] = num + 1;
                      mark = 1;
                     }
                     if(a[i][j + 1] == 0){
                      a[i][j + 1] = num + 1;
                      mark = 1;
                     }
                     if(a[i][j - 1] == 0){
                      a[i][j - 1] = num + 1;
                      mark = 1;
                     }
                    }
            }
        }
    num++;
    if(a[iB][jB] != 0) break;
    }
    return mark;
}

int main(){
    int iA, jA, iB, jB, mark;
    ifstream input("dataA1.dat");
    input >> m;
    input >> n;
    if(m > 20) m = 20;
    if(n > 20) n = 20;
    input >> iA;
    input >> jA;
    input >> iB;
    input >> jB;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            input >> a[i][j];
        }
    }
    input.close();
    cout << "\n";

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1) cout << static_cast<char>(35);
            else if(a[i][j] == 0) cout << (" ");
        }
        cout << "\n";
    }
    cout << "\n";

    clear();
    mark = wave(iA, jA, iB, jB);
    printf("mark = %d \n", mark);
    cout << "\n";
    printf("b1; \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            b1[i][j] = a[i][j];
        }
    }
    clear();
    mark = wave(iB, jB, iA, jA);
    cout << "\n";
    printf("b2: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            b2[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            b3[i][j] = b1[i][j] + b2[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    printf("b3 = b1 + b2: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << setw(3) << b3[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    printf("b3CLEAR: \n");
    int b311 = b3[1][1];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
           if(b3[i][j] == 2)
           cout << setw(3) << static_cast<char>(35);
            else if(b3[i][j] == b311)
                 cout << setw(3) << static_cast<char>(42);
                else cout << setw(3) << static_cast<char>(0);;
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
