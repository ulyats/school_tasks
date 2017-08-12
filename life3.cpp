//life1.cpp
#include <iostream>
#include<stdio.h>
#include <iomanip>
#include <fstream>
using namespace std;

int a[20][20];
int b[20][20];

int main() {
int N, T, t, sum;
ifstream infile("life1.txt");
infile >> N;
infile >> T;
if (N > 20) N = 20;
cout << "N = "  << N << " " << "T = "  << T << endl;
for (int i = 0; i <= N + 1; i++) {
 for (int j = 0; j <= N + 1; j++) {
  a[i][j] = 0;
 }
}
for (int i = 1; i <= N; i++) {
 for (int j = 1; j <= N; j++) {
  infile >> a[i][j];
 }
}
infile.close();
cout << "\n";

cout << "a[N][N](t=0):" << endl;
for (int i = 1; i <= N; i++) {
 for (int j = 1; j <= N; j++) {
  cout << setw(2) << a[i][j];
 }
 cout << "\n";
}
cout << "\n";

for (t = 1;  t <= T; t++) {
 for (int i = 1; i <= N; i++) {
  for (int j = 1; j <= N; j++) {
   sum = 0;
   sum = sum + a[i-1][j-1];
   sum = sum + a[i-1][j];
   sum = sum + a[i-1][j+1];
   sum = sum + a[i][j-1];
   sum = sum + a[i][j+1];
   sum = sum + a[i+1][j-1];
   sum = sum + a[i+1][j];
   sum = sum + a[i+1][j+1];
   b[i][j] = sum;
  }
 }
 for (int i = 1;  i <= N;  i++) {
  for (int j = 1;  j <= N;  j++) {
   if ((a[i][j] == 1) && (b[i][j] < 2) || (b[i][j] > 3))
    a[i][j] = 0;
   else if ((a[i][j] == 0) && (b[i][j] == 3))
    a[i][j] = 1;
  }
 }
 cout << "a[N][N](t=" << t << "):" << endl;
 for (int i = 1; i <= N; i++) {
  for (int j = 1; j <= N; j++) {
   cout << setw(2) << a[i][j];
  }
  cout << "\n";
 }
cout << "\n";
}

return 0;
}
