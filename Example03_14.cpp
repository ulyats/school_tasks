#include <iostream>
using namespace std;
int main(){
    const int N = 3;
    int i, j, k;
    double A[N][N];
    double B[N][N];
    double C[N][N];
    cout << "Matrix A:\n";
    for(i = 0; i < N; i++){
       for(j = 0; j < N; j++){
          cin >> A[i][j];
        }
    }
    cout << "Matrix B:\n";
    for(i = 0; i < N; i++){
       for(j = 0; j < N; j++){
          cin >> B[i][j];
        }
    }
    cout << "Matrix C=AB:\n";
    for(i = 0; i < N; i++){
       for(j = 0; j < N; j++){
          C[i][j] = 0;
          for(k = 0; k < N; k++)
             C[i][j] += A[i][k] * B[k][j];
          cout << C[i][j] << " ";
       }
       cout << endl;
    }
    return 0;
}
