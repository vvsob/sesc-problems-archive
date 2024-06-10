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

struct Point {
	bool u = false, r = false, d = false, l = false;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<Point>> grid(n + 1, vector<Point>(m + 1));
	int q;
	cin >> q;
	int i = 0, j = 0;
	while (q--) {
		char c;
		cin >> c;
		if (c == 'u') {
			grid[i][j].u = true;
			j++;
			grid[i][j].d = true;
		} else if (c == 'd') {
			grid[i][j].d = true;
			j--;
			grid[i][j].u = true;
		} else if (c == 'r') {
			grid[i][j].r = true;
			i++;
			grid[i][j].l = true;
		} else if (c == 'l') {
			grid[i][j].l = true;
			i--;
			grid[i][j].r = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			cnt += (grid[i][j].u + grid[i][j].d + grid[i][j].r + grid[i][j].l >= 3);
		}
	}
	cout << cnt << "\n";
}