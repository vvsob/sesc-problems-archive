#include "testlib.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    // args: [n]
    int n = atoi(argv[1]);
    string s(n, ' ');
    string sesc = "SESC";
    for (int i = 0; i < n; ++i)
        s[i] = sesc[i % sesc.size()];
    cout << s << "\n";
}