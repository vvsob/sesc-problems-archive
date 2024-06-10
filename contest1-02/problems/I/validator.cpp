#include "testlib.h"
using namespace std;
 
using ll = long long;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int q = inf.readInt(1, 100'000, "q");
    inf.readEoln();
    ll totalLen = 0;
    for (int i = 1; i <= q; ++i) {
        setTestCase(i);
        string s, t;
        s = inf.readLine("[a-z]{1, 200000}", "s");
        t = inf.readLine("[a-z]{1, 200000}", "t");
        totalLen += s.length() + t.length();
    }
    inf.readEof();
    ensuref(totalLen <= 200'000, "Total length should be \leq 200'000");
}
