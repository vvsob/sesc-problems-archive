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

vector<bool> sieve;

void solve() {
    ll l, r;
    cin >> l >> r;
    sieve.assign(r + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i * i <= r; ++i) {
        if (!sieve[i])
            continue;
        for (int j = i * i; j <= r; j += i) {
            sieve[j] = false;
        }
    }
    ll res = 0;
    for (int i = l; i <= r; ++i) {
        if (sieve[i] && sieve[i - 2]) {
            // cout << i - 2 << " " << i << "\n";
            res++;
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}
