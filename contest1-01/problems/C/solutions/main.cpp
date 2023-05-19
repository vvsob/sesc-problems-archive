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

map<int, int> letters = { {1, 4}, {2, 3}, {3, 3}, {4, 6}, {5, 4}, {6, 5}, {7, 4}, {8, 6}, {9, 6}, {10, 6}, {11, 11}, {12, 10}, {13, 10}, {14, 12}, {15, 10}, {16, 11}, {17, 10}, {18, 12}, {19, 12} };
map<int, int> tens = { {2, 8}, {3, 8}, {4, 5}, {5, 9}, {6, 10}, {7, 9}, {8, 11}, {9, 9} };
map<int, int> hundreths = { {1, 3}, {2, 6}, {3, 6}, {4, 9}, {5, 7}, {6, 8}, {7, 7}, {8, 9}, {9, 9} };

int f(int x) {
    if (x == 1e9)
        return 12;
    if (x >= 1e6) {
        int lpart = x / (int)1e6;
        int d = 9;
        if (lpart % 10 == 1 && lpart % 100 != 11)
            d = 7;
        if (lpart % 10 >= 2 && lpart % 10 <= 4 && (lpart % 100 < 12 || lpart % 100 > 14))
            d = 8;
        return f(lpart) + d + f(x % (int)1e6);
    }
    if (x >= 1e3) {
        int lpart = x / (int)1e3;
        int d = 5;
        if (lpart % 10 == 1 && lpart % 100 != 11)
            d = 6;
        if (lpart % 10 >= 2 && lpart % 10 <= 4 && (lpart % 100 < 12 || lpart % 100 > 14))
            d = 6;
        return f(lpart) + d + f(x % (int)1e3);
    }
    if (x >= 100) {
        return hundreths[x / 100] + f(x % 100);
    }
    if (x >= 20) {
        return tens[x / 10] + letters[x % 10];
    }
    return letters[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    map<int, int> seen;
    seen[n] = 0;
    int d = 0;
    while (k > 0) {
        n = f(n);
        k--;
        if (seen.find(n) != seen.end())
            break;
        d++;
        seen[n] = d;
    }

    if (k == 0) {
        cout << n << "\n";
        return 0;
    }

    int h = d - seen[n];
    k -= (k / (h + 1)) * (h + 1);
    while (k > 0) {
        k--;
        n = f(n);
    }
    cout << n << "\n";
}
