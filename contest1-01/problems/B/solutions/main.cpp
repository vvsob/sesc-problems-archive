#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll LLINF = 1e18;
const ll BASE = 257;
const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, a, x, b, y;
    cin >> n >> k >> a >> x >> b >> y;
    ll r1 = x * max(k - a, 0ll) + y * max(k - a - b, 0ll);
    ll r2 = y * max(k - b, 0ll) + x * max(k - a - b, 0ll);
    cout << min(n, max(r1, r2)) << "\n";
}
