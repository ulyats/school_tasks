//labirint01.cpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
const int m = 7;
const int n = 7;
int a[m][n] = {
1,1,1,1,1,1,1,
1,0,1,0,0,0,1,
1,0,1,0,1,0,1,
1,0,0,0,0,0,1,
1,0,1,0,1,0,1,
1,0,1,0,0,0,1,
1,1,1,1,1,1,1
};
int b1[m][n];
int b2[m][n];

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
