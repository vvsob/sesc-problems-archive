#include "testlib.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // args: [subtask number][from][to]
    int subtask = atoi(argv[1]);
    int from = atoi(argv[2]);
    int to = atoi(argv[3]);

    for (int currentTest = from; currentTest <= to; ++currentTest) {
        startTest(currentTest);
        int n, m;
        string s;
        set<string> p;
        if (subtask == 1) {
            n = rnd.next(1, 1000);
            m = 1;
            s = rnd.next(format("[a-z]{%d}", n));
            while(p.size() < m) {
                int l = rnd.next(1, 5);
                if (rnd.next(0, 4) == 4)
                    l = rnd.next(6, 1000);
                if (rnd.next(0, 2) == 2 && l <= n) {
                    p.insert(s.substr(rnd.next(0, n - l), l));
                } else {
                    p.insert(rnd.next(format("[a-z]{%d}", l)));
                }
            }
        }
        if (subtask == 2) {
            n = rnd.next(1, 1000);
            m = rnd.next(1, 1000);
            s = rnd.next(format("[a-z]{%d}", n));
            int l = rnd.next(1, 1000);
            if (m > 26)
                l = max(2, l);
            if (m > 26 * 26)
                l = max(3, l);
            while (p.size() < m) {
                if (rnd.next(0, 2) == 2 && l <= n) {
                    p.insert(s.substr(rnd.next(0, n - l), l));
                } else {
                    p.insert(rnd.next(format("[a-z]{%d}", l)));
                }
            }
        }
        if (subtask == 3) {
            n = rnd.next(1, 1000);
            int max_m = 10;
            if (rnd.next(0, 4) == 4)
                max_m = 1000;
            m = rnd.next(1, max_m);
            s.resize(n);
            int k = rnd.next(1, 10);
            for (int i = 0; i < n; ++i) {
                if (rnd.next(0, k) == k)
                    s[i] = rnd.next("[b-z]{1}")[0];
                else
                    s[i] = 'a';
            }
            while (p.size() < m) {
                int max_l = 7;
                if (rnd.next(0, 5) == 5)
                    max_l = 1000;
                int l = rnd.next(2, max_l);
                p.insert(rnd.next(format("a{%d}", l)));
            }
        }
        if (subtask == 4) {
            n = rnd.next(1, 1000);
            m = rnd.next(1, 1000);
            s = rnd.next(format("[a-z]{%d}", n));
            while (p.size() < m) {
                int l = rnd.next(1, 1000);
                if (rnd.next(0, 2) == 2 && l <= n) {
                    p.insert(s.substr(rnd.next(0, n - l), l));
                } else {
                    p.insert(rnd.next(format("[a-z]{%d}", l)));
                }
            }
        }
        if (subtask == 5) {
            n = rnd.next(1, 1000);
            m = rnd.next(1, (int)1e5);
            s = rnd.next(format("[a-z]{%d}", n));
            int l = rnd.next(1, (int)(1e6) / m);
            if (m > 26)
                l = max(2, l);
            if (m > 26 * 26)
                l = max(3, l);
            if (m > 26 * 26 * 26)
                l = max(4, l);
            while (p.size() < m) {
                if (rnd.next(0, 999) == 999 && l <= n) {
                    p.insert(s.substr(rnd.next(0, n - l), l));
                } else {
                    p.insert(rnd.next(format("[a-z]{%d}", l)));
                }
            }
        }
        if (subtask == 6) {
            n = rnd.next(1, 1000);
            m = rnd.next(1, (int)1e5);
            s = rnd.next(format("[a-z]{%d}", n));
            int len_left = 1e6;
            while (p.size() < m) {
                int max_l = min(1000, (int)(len_left - 6 * (m - p.size() - 1)));
                if (rnd.next(0, 9999) == 9999)
                    max_l = min((int)1e5, (int)(len_left - 6 * (m - p.size() - 1)));
                int l = rnd.next(5, max_l);
                string cur = rnd.next(format("[a-z]{%d}", l));
                if (rnd.next(0, 499) == 499 && l <= n) 
                    cur = s.substr(rnd.next(0, n - l), l);
                if (p.count(cur))
                    continue;
                p.insert(cur);
                len_left -= l;
            }
        }
        cout << n << " " << m << "\n";
        cout << s << "\n";
        for (auto el : p)
            cout << el << "\n";
    }
}