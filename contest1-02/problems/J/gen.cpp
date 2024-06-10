#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

pair<int, int> go(int x, int y, char d) {
    if (d == 'u')
        return {x, y + 1};
    if (d == 'd')
        return {x, y - 1};
    if (d == 'r')
        return {x + 1, y};
    if (d == 'l')
        return {x - 1, y};
    return {x, y};
}

bool check(int n, int m, int x, int y, char d) {
    auto [x1, y1] = go(x, y, d);
    return 0 <= x1 && x1 <= n && 0 <= y1 && y1 <= m;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    cout << n << " " << m << "\n";
    int q = 1'000'000;
    cout << q << "\n";
    int x = 0, y = 0;
    const string dirs = "udrl";
    while (q--) {
        char d = rnd.any(dirs);
        while (!check(n, m, x, y, d)) {
            d = rnd.any(dirs);
        }
        cout << d;
        auto p = go(x, y, d);
        x = p.first, y = p.second;
    }
    cout << "\n";
}
