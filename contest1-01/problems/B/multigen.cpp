#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    // args: [subtask number][from][to]
    int subtask = atoi(argv[1]);
    int from = atoi(argv[2]);
    int to = atoi(argv[3]);

    for (int currentTest = from; currentTest <= to; ++currentTest) {
        startTest(currentTest);
        int n, k, a, x, b, y;
        if (subtask == 1) {
            // a = 0, x = 0
            n = rnd.next(1, (int)1e9);
            k = rnd.next(0, (int)1e9);
            a = 0;
            x = 0;
            b = rnd.next(0, (int)1e9);
            y = rnd.next(0, (int)1e9);
        } else if (subtask == 2) {
            // a = 0, b = 0
            n = rnd.next(1, (int)1e9);
            k = rnd.next(0, (int)1e9);
            a = 0;
            x = rnd.next(0, (int)1e9);
            b = 0;
            y = rnd.next(0, (int)1e9);
        } else if (subtask == 3) {
            // a = b
            n = rnd.next(1, (int)1e9);
            k = rnd.next(0, (int)1e9);
            a = rnd.next(0, (int)1e9);
            x = rnd.next(0, (int)1e9);
            b = a;
            y = rnd.next(0, (int)1e9);
        } else if (subtask == 4) {
            // x = y
            n = rnd.next(1, (int)1e9);
            k = rnd.next(0, (int)1e9);
            a = rnd.next(0, (int)1e9);
            x = rnd.next(0, (int)1e9);
            b = rnd.next(0, (int)1e9);
            y = x;
        } else if (subtask == 5) {
            // any
            n = rnd.next(1, (int)1e9);
            k = rnd.next(0, (int)1e9);
            a = rnd.next(0, (int)1e9);
            x = rnd.next(0, (int)1e9);
            b = rnd.next(0, (int)1e9);
            y = rnd.next(0, (int)1e9);
        }
        cout << n << " " << k << "\n";
        cout << a << " " << x << "\n";
        cout << b << " " << y << "\n";
    }
}