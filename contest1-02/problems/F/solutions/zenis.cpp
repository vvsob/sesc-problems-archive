#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--) {
		bool b = 0;
		int l = 0, r = 37;
		while (r - l > 1) {
			int m = (r + l) / 2, m1 = m;
			string s;
			while (m > 0) {
				if (m >= 9) {
					s.push_back('9');
					m -= 9;
				}
				else {
					s.push_back(to_string(m)[0]);
					m = 0;
				}
			}
			while (s.size() < 4) {
				s.push_back('0');
			}
			cout << s << endl;
			char q;
			cin >> q;
			if (q == '<') {
				r = m1;
			}
			if (q == '>') {
				l = m1;
			}
			if (q == '+') {
				l = m1;
				b = 1;
				break;
			}
			if (q == '=') {
				l = m1;
				break;
			}
		}
		if (b == 1) {
			continue;
		}
		for (int i = 0; i <= min(9, l); i++) {
			for (int j = 0; j <= min(9, l - i); j++) {
				for (int k = 0; k <= min(9, l - i - j); k++) {
					if (l - i - j - k > 9) {
						continue;
					}
					cout << i << j << k << l - i - j - k << endl;
					char q;
					cin >> q;
					if (q == '-') {
						q = q / 0;
					}
					if (q == '=') {
						continue;
					}
					b = 1;
					break;
				}
				if (b == 1) {
					break;
				}
			}
			if (b == 1) {
				break;
			}
		}
	}
}