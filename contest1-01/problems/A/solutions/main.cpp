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
    string s;
    cin >> s;
    string sesc = "SESC";
    int cnt = 0, j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != sesc[j])
            continue;
        j++;
        if (j >= sesc.size()) {
            cnt++;
            j = 0;
        }
    }
    cout << cnt << "\n";
}
