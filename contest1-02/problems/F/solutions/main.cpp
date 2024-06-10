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

int dsum(const string& x) {
    int res = 0;
    for (auto d : x) {
        res += d - '0';
    }
    return res;
}

string get_code(int x) {
    string res(4, '0');
    for (int i = 3; i >= 0; --i) {
        res[i] = (x % 10) + '0';
        x /= 10;
    }
    return res;
}

char ask(int x) {
    cout << get_code(x) << endl;
    char ans;
    cin >> ans;
    return ans;
}

vector<vector<int>> codes;

void precalc() {
    codes.resize(37);
    for (int i = 0; i < 10000; ++i) {
        string s = get_code(i);
        codes[dsum(s)].push_back(i);
    }
}

void solve() {
    // find dsum
    int xsum = 0;
    for (int i = 0; i < 37; ++i) {
        char ans = ask(codes[i][0]);
        if (ans == '=') {
            xsum = dsum(get_code(i));
            break;
        } else if (ans == '+') {
            return;
        }
    }
    for (auto code : codes[xsum]) {
        char ans = ask(code);
        if (ans == '+') {
            return;
        }
    }
}

int main() {
    precalc();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}