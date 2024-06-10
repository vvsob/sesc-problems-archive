#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
using namespace std;

using ll = long long;

const ll INF = 1e18;
    
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> f(n, vector<bool>(m, false));
    vector<vector<bool>> nf(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < m; ++j) {
            f[i][j] = (line[j] == '#');
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            nf[i][j] = f[i][j] || (i > 0 && f[i - 1][j]) || (j > 0 && f[i][j - 1]) || (i > 0 && j > 0 && f[i - 1][j - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (nf[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();
}
