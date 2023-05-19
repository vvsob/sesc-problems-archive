#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    int n = atoi(argv[2]);
    cout << rnd.next((string)"[A-Z]{" + to_string(n) + (string)"}") << endl;
}
