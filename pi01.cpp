//pi01.cpp
#include <iostream>
#include<stdio.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(void)
{
    int N1,N2,nCIRCLE,nSQUARE;
    double rnd1, rnd2, a, x, y, r;
    N1 = 10;
    N2 = 100000;
    a = 2;
    nSQUARE = 0;
    nCIRCLE = 0;
    for(int i = 1; i <= N1; i++) {
      for(int j = 1; j <= N2; j++) {
        rnd1 = (double)rand()/RAND_MAX;
    //    rnd1 = static_cast<double>(rand())/RAND_MAX;
        x = (2 * rnd1 - 1) * a;
        rnd2 = (double)rand()/RAND_MAX;
    //    rnd2 = static_cast<double>(rand())/RAND_MAX;
        y = (2 * rnd2 - 1) * a;
        r = sqrt(x * x + y * y);
        nSQUARE = nSQUARE + 1;
        if (r < a)
          nCIRCLE = nCIRCLE + 1;
        }
      cout << 4.0*nCIRCLE/nSQUARE << endl;
    //  cout << 4*(double)nSIRCLE/nQUADRATE << endl;
      }

    return 0;
}
