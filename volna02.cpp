//labirint02.cpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int m, n;
int  a[100][100];
int b1[100][100];
int b2[100][100];

void clear(void){
    for(int i = 0; i < m; i++){
        for(int j = 0;j < n; j++){
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
    int mark;
    printf("input m =");
    cin >> m;
    printf("input n =");
    cin >> n;
    printf("input a[i][j]");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << "\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1) printf("%c", 35);
            else if(a[i][j] == 0) printf(" ");
        }
        cout << "\n";
    }
    cout << "\n";

    clear();
    mark = wave(1, 1, 5, 5);
    printf("mark = %d \n", mark);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%3d", a[i][j]);
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
    mark = wave(5, 5, 1, 1);
    printf("mark = %d \n", mark);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%3d", a[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            b2[i][j] = a[i][j];
        }
    }

    printf("sum: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%3d", b1[i][j] + b2[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
