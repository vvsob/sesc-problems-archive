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
    string s, t;
    cin >> s >> t;
    vector<int> scnt(26, 0), tcnt(26, 0);
    for (int i = 0; i < t.size(); ++i) {
        scnt[s[i] - 'a']++;
        tcnt[t[i] - 'a']++;
    }
    ll res = scnt == tcnt;
    for (int i = t.size(); i < s.size(); ++i) {
        scnt[s[i - t.size()] - 'a']--;
        scnt[s[i] - 'a']++;
        res += scnt == tcnt;
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    while (q--)
        solve();
}
