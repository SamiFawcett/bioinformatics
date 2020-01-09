#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    double prob;

    double k = (double) atoi(argv[1]);
    double m = (double) atoi(argv[2]);
    double n = (double) atoi(argv[3]);



    prob = ((k*k - k) + 2*(k*m) + 2*(k*n) + (.75*(m*m - m)) + 2*(.5*m*n))/((k + m + n)*(k + m + n -1));

    cout << prob << endl;
    return 0;
}
