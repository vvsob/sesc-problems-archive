#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    if (t == 1) {
        // all 'a'        
        int n = 1000;
        string s(n, 'a');
        int m = atoi(argv[2]);
        set<string> p;
        if (m == 1) {
            p.insert("a");
        } else {
            while (p.size() < m) {
                p.insert(string(rnd.next(1, 1000), 'a'));
            }
        }
        cout << n << " " << m << "\n";
        cout << s << "\n";
        for (auto el : p)
            cout << el << "\n";
    } else {
        int n = 1000;
        char alph = argv[3][0];
        string s = rnd.next("[a-%c]{%d}", alph, n);
        int m = atoi(argv[2]);
        set<string> p;
        int len_left = 1e6;
        while (p.size() < m) {
            int max_l = min(50, (int)(len_left - 6 * (m - p.size() - 1)));
            if (rnd.next(0, m / 10) == m / 10)
                max_l = min(1000, (int)(len_left - 6 * (m - p.size() - 1)));
            int l = rnd.next(5, max_l);
            string cur = s.substr(rnd.next(0, n - l), l);
            if (p.count(cur))
                cur = rnd.next("[a-z]{%d}", l);
            if (p.count(cur))
                continue;
            p.insert(cur);
            len_left -= l;
        }
        cout << n << " " << m << "\n";
        cout << s << "\n";
        for (auto el : p)
            cout << el << "\n";
    }
}
