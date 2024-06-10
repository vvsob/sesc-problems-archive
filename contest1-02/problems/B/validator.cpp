#include "testlib.h"
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 200'000, "n");
    inf.readSpace();
    int m = inf.readInt(1, n - 1, "m");
    inf.readEoln();
    g.resize(n);
    vis.assign(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        u = inf.readInt(1, n, "u");
        inf.readSpace();
        v = inf.readInt(1, n, "v");
        inf.readEoln();
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    inf.readEof();

    dfs(0);
    for (int u = 0; u < n; ++u) {
        ensuref(vis[u], "graph should be connected");
    }
}
