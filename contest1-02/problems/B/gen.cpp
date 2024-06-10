#include "testlib.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = 200'000;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        edges[i] = {i + 1, rnd.next(0, i)};
    }
    cout << n << " " << n - 1 << "\n";
    auto p = rnd.perm(n);
    for (auto [u, v] : edges) {
        cout << p[u] + 1 << " " << p[v] + 1 << "\n";
    }
}
