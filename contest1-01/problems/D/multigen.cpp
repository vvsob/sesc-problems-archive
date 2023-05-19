#include "testlib.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    // args: [subtask number][from][to]
    int subtask = atoi(argv[1]);
    int from = atoi(argv[2]);
    int to = atoi(argv[3]);

    for (int currentTest = from; currentTest <= to; ++currentTest) {
        startTest(currentTest);
        int n, d;
        vector<ll> a;
        if (subtask == 1) {
            // n <= 100
            n = rnd.next(1, 100);
            d = rnd.next(0, n - 1);
            a.resize(n);
            for (int i = 0; i < n; ++i)
                a[i] = rnd.next((ll)-1e12, (ll)1e12);
        }
        if (subtask == 2) {
            // n <= 5000
            n = rnd.next(1, 5000);
            d = rnd.next(0, n - 1);
            a.resize(n);
            for (int i = 0; i < n; ++i)
                a[i] = rnd.next((ll)-1e12, (ll)1e12);
        }
        if (subtask == 3) {
            // v_i >= 0
            n = rnd.next(1, (int)1e6);
            d = rnd.next(0, n - 1);
            a.resize(n);
            for (int i = 0; i < n; ++i)
                a[i] = rnd.next(0ll, (ll)1e12);
        }
        if (subtask == 4) {
            // |v_i| <= 1000
            n = rnd.next(1, (int)1e6);
            d = rnd.next(0, n - 1);
            a.resize(n);
            for (int i = 0; i < n; ++i)
                a[i] = rnd.next(-1000, 1000);
        }
        if (subtask == 5) {
            // any
            n = rnd.next(1, (int)1e6);
            d = rnd.next(0, n - 1);
            a.resize(n);
            for (int i = 0; i < n; ++i)
                a[i] = rnd.next((ll)-1e12, (ll)1e12);
        }
        cout << n << " " << d << "\n";
        for (int i = 0; i < n; ++i)
            cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
}