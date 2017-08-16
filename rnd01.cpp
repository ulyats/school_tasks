//rnd01.cpp
#include <iostream>
#include<stdio.h>
#include <iomanip>
//#include <fstream>
#include <stdlib.h>
using namespace std;
//RAND_MAX = 32767;

int main(void)
{
int N = 10;
for(int i = 1; i <= N; i++) {
  cout << rand() << endl;
  }
cout << "\n";
for(int i = 1; i <= N; i++) {
  cout << rand() % 20 << endl;
  }
cout << "\n";
for(int i = 1; i <= N; i++) {
  cout << (double)rand()/RAND_MAX << endl;
  }

return 0;
}
