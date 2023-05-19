#include "testlib.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    // args: [n][vi]
    int n, d;
    vector<ll> a;
    n = atoi(argv[1]);
    d = n / 2;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        a[i] = rnd.any(vector<ll>{atoll(argv[2]), -atoll(argv[2])});
    cout << n << " " << d << "\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << (i < n - 1 ? " " : "\n");
}
