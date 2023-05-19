#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    int n = rnd.next(1, (int)1e9);
    int k = rnd.next(1, atoi(argv[2]));
    cout << n << " " << k << endl;
}
