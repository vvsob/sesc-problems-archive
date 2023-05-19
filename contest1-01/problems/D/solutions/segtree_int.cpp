#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

const int INF = 1e18;

int n, d;
vector<int> p, s;
vector<int> ptree, stree;

void build(int v, int l, int r) {
    if (r - l == 1) {
        ptree[v] = p[l];
        stree[v] = s[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    ptree[v] = min(ptree[2 * v + 1], ptree[2 * v + 2]);
    stree[v] = min(stree[2 * v + 1], stree[2 * v + 2]);
}

int pget(int v, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql)
        return INF;
    if (ql <= l && r <= qr)
        return ptree[v];
    int mid = (l + r) / 2;
    return min(pget(2 * v + 1, l, mid, ql, qr), pget(2 * v + 2, mid, r, ql, qr));
}

int sget(int v, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql)
        return INF;
    if (ql <= l && r <= qr)
        return stree[v];
    int mid = (l + r) / 2;
    return min(sget(2 * v + 1, l, mid, ql, qr), sget(2 * v + 2, mid, r, ql, qr));
}

int get(int l, int r) {
    int mid = n / 2;
    if (n % 2 == 0) {
        int res = INF;
        if (l < mid)
            res = min(res, pget(0, 0, n, l, min(r + 1, mid)));
        if (r >= mid)
            res = min(res, sget(0, 0, n, max(l, mid), r + 1));
        return res;
    }

    if (l <= mid && r >= mid) {
        int res = max(s[mid], p[mid]);
        if (l < mid)
            res = min(res, pget(0, 0, n, l, mid));
        if (r > mid)
            res = min(res, sget(0, 0, n, mid + 1, r + 1));
        return res;
    }

    if (r < mid)
        return pget(0, 0, n, l, r + 1);
    return sget(0, 0, n, l, r + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("catapult.in", "r", stdin);
    // freopen("catapult.out", "w", stdout);

    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    p.assign(n, 0), s.assign(n, 0);
    p[0] = a[0];
    s.back() = a.back();
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n - 2; i >= 0; --i)
        s[i] = s[i + 1] + a[i];

    ptree.assign(4 * n, 0), stree.assign(4 * n, 0);

    build(0, 0, n);

    int resInd = -1, res = -INF;
    for (int i = 0; i < n; ++i) {
        if (get(max(0, i - d), min(n - 1, i + d)) > res) {
            resInd = i;
            res = get(max(0, i - d), min(n - 1, i + d));
        }
    }
    cout << resInd + 1 << " " << res << "\n";
}
