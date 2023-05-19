#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int n, d;
vector<ll> a;

ll go(int i) {
    if (2 * i + 1 == n) {
        ll r1 = 0, r2 = 0;
        for (int j = i; j >= 0; --j)
            r1 += a[j];
        for (int j = i; j < n; ++j)
            r2 += a[j];
        return max(r1, r2);
    }
    if (2 * i < n) {
        ll r = 0;
        for (int j = i; j >= 0; --j)
            r += a[j];
        return r;
    }
    ll r = 0;
    for (int j = i; j < n; ++j)
        r += a[j];
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("catapult.in", "r", stdin);
    // freopen("catapult.out", "w", stdout);
    
    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll res = -INF, resInd = -1;
    for (int place = 0; place < n; ++place) {
        ll cur = INF;
        for (int land = max(0, place - d); land <= min(n - 1, place + d); ++land) {
            cur = min(cur, go(land));
        }
        if (cur > res) {
            resInd = place;
            res = cur;
        }
    }
    cout << resInd + 1 << " " << res << "\n";
}
