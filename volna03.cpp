//labirint02.cpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int m, n;
int  a[100][100];
int b1[100][100];
int b2[100][100];
int b3[100][100];

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
    FILE *fr;
    fr = fopen("dataA1.dat", "r");
    fscanf(fr, "%d%d", &m, &n);
    if(m > 100) m = 100;
    if(n > 100) n = 100;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fscanf(fr, "%d", &a[i][j]);
        }
    }
    fclose(fr);
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
            printf("%3d", b3[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";

    printf("b3CLEAR: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
           if(b3[i][j] == 2)
           printf("%c", 35);
            else if(b3[i][j] == b3[1][1])
                  printf("%c", 42);
                else printf(" ");
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
