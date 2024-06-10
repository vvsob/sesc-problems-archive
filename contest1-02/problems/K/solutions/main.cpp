#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <random>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<ll>> s(n, vector<ll>(n)), g(n, vector<ll>(n)), lis(n, vector<ll>(n)), lss(n, vector<ll>(n)), inverses(n, vector<ll>(n));

	for (int i = 0; i < n; ++i) {
		s[i][i] = a[i];
		g[i][i] = abs(a[i]);
		lis[i][i] = 1;
		lss[i][i] = max(0ll, a[i]);
		inverses[i][i] = 0;
		set<ll> st = { a[i] };
		cout << a[i] << " " << 0 << " " << abs(a[i]) << " " << (a[i] == 0 ? 1 : 0) << " " << 1 << " " << 1 << " " << lss[i][i] << " " << 0 << "\n";
		for (int j = i + 1; j < n; ++j) {
			st.insert(a[j]);
			s[i][j] = s[i][j - 1] + a[j];
			g[i][j] = gcd(g[i][j - 1], abs(a[j]));
			lis[i][j] = 1;
			lss[i][j] = max(lis[i][j - 1], a[j]);
			inverses[i][j] = inverses[i][j - 1] + 1;
			for (int k = i; k < j; ++k) {
				if (a[j] > a[k]) {
					lis[i][j] = max(lis[i][j], lis[i][k] + 1);
					inverses[i][j]++;
				}
				lss[i][j] = max(lss[i][j], s[k][j]);
			}
			ll mex = 0;
			for (auto el : st) {
				if (el == mex) {
					mex++;
				}
			}
			cout << s[i][j] << " " << (*prev(st.end()) - *st.begin()) << " " << g[i][j] << " " << mex << " " << st.size() << " " << lis[i][j] << " " << lss[i][j] << " " << inverses[i][j] << "\n";
		}
	}
}
