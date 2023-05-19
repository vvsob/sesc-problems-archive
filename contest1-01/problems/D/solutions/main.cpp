#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

struct KeepMin {
    deque<ll> dq;

    ll get() {
        return dq.front();
    }

    void push(ll x) {
        while (!dq.empty() && dq.back() > x)
            dq.pop_back();
        dq.push_back(x);
    }

    void pop(ll x) {
        if (dq.front() == x)
            dq.pop_front();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("catapult.in", "r", stdin);
    // freopen("catapult.out", "w", stdout);

    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> p(n, 0), s(n, 0);
    p[0] = a[0];
    s.back() = a.back();
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n - 2; i >= 0; --i)
        s[i] = s[i + 1] + a[i];

    KeepMin keep;

    for (int i = 0; i < d + 1; ++i) {
        if (i * 2 + 1 == n)
            keep.push(max(p[i], s[i]));
        else if (i * 2 < n)
            keep.push(p[i]);
        else
            keep.push(s[i]);
    }

    ll res = keep.get(), resInd = d;
    for (int i = d + 1; i - d < n; ++i) {
        if (i < n) {
            if (i * 2 + 1 == n)
                keep.push(max(p[i], s[i]));
            else if (i * 2 < n)
                keep.push(p[i]);
            else
                keep.push(s[i]);
        }
        int j = i - 2 * d - 1;
        if (j >= 0) {
            if (j * 2 + 1 == n)
                keep.pop(max(p[j], s[j]));
            else if (j * 2 < n)
                keep.pop(p[j]);
            else
                keep.pop(s[j]);
        }

        if (keep.get() > res) {
            res = keep.get();
            resInd = i;
        }
    }
    cout << resInd - d + 1 << " " << res << "\n";
}
