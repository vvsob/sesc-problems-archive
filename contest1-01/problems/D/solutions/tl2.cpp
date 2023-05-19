#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int n, d;
vector<ll> a;
vector<ll> p, s;

ll go(int i) {
    if (2 * i + 1 == n) {
        return max(p[i], s[i]);
    }
    if (2 * i < n) {
        return p[i];
    }
    return s[i];
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

    p.assign(n, 0);
    s.assign(n, 0);
    p[0] = a[0];
    s.back() = a.back();
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n - 2; i >= 0; --i)
        s[i] = s[i + 1] + a[i];

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
