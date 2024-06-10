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

inline int coords(int i, int j) {
	return i * 8 + j;
}

int cnt;

void gen(int left, int n, vector<pair<int, int>>& cans, const bitset<64>& used) {
	if (left == 0) {
		cnt++;
		return;
	}
	int si = 0, sj = 0;
	if (!cans.empty()) {
		si = cans.back().first;
		sj = cans.back().second;
	}
	for (int i = si; i < n; ++i) {
		for (int j = (i == si ? sj : 0); j < n; ++j) {
			if (used[coords(i, j)])
				continue;
			bitset<64> new_used = used;
			for (int d = 0; d < n; ++d) {
				if (i + d < n && j + d < n)
					new_used[coords(i + d, j + d)] = true;
				if (i + d < n && j - d >= 0)
					new_used[coords(i + d, j - d)] = true;
				if (i - d >= 0 && j + d < n)
					new_used[coords(i - d, j + d)] = true;
				if (i - d >= 0 && j - d >= 0)
					new_used[coords(i - d, j - d)] = true;
			}
			cans.push_back({ i, j });
			gen(left - 1, n, cans, new_used);
			cans.pop_back();
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	bitset<64> used;
	vector<pair<int, int>> cans;
	gen(k, n, cans, used);
	cout << cnt << "\n";
}