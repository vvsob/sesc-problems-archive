#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <random>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll res = 0;
    for (ll x = 1; x < n; ++x) {
        ll l = 0, r = n;
        while (r - l > 1) {
            ll y = (l + r) / 2;
            if (x * x + y * y <= n * n) {
                l = y;
            } else {
                r = y;
            }
        }
        res += l;
    }
    cout << 4 * res + 4 * n + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}
