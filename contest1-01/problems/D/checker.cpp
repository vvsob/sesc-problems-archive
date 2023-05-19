#include "testlib.h"
using namespace std;

typedef long long ll;

ll n, d;

pair<ll, ll> readAns(InStream& inf) {
    ll x, s;
    x = inf.readInt(1, n, "x");
    s = inf.readLong((ll)-1e18, (ll)1e18, "s");
    return {x, s};
}

int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    n = inf.readInt();
    d = inf.readInt();

    vector<ll> a = inf.readLongs(n);
    
    vector<ll> p(n, 0), s(n, 0);
    p[0] = a[0];
    s.back() = a.back();
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n - 2; i >= 0; --i)
        s[i] = s[i + 1] + a[i];

    auto [jury_x, jury_s] = readAns(ans);
    auto [out_x, out_s] = readAns(ouf);

    // Check participants solution
    ll res_out = (ll)1e18;
    for (int i = max(0ll, out_x - 1 - d); i < min(n, out_x + d); ++i) {
        if (i * 2 + 1 == n)
            res_out = min(res_out, max(p[i], s[i]));
        else if (i * 2 < n)
            res_out = min(res_out, p[i]);
        else
            res_out = min(res_out, s[i]);
    }

    // Check jury's solution
    ll res_jury = (ll)1e18;
    for (int i = max(0ll, jury_x - 1 - d); i < min(n, jury_x + d); ++i) {
        if (i * 2 + 1 == n)
            res_jury = min(res_jury, max(p[i], s[i]));
        else if (i * 2 < n)
            res_jury = min(res_jury, p[i]);
        else
            res_jury = min(res_jury, s[i]);
    }

    if (res_jury != jury_s)
        quitf(_fail, "Jury's s is not correct for given x. Expected s: %d, found: %d", res_jury, jury_s);

    if (res_out != out_s)
        quitf(_wa, "Participant's s is not correct for given x.");
    
    if (res_out < jury_s)
        quitf(_wa, "Participant's answer is not optimal.");
    
    if (res_out == jury_s)
        quitf(_ok, "The answer is correct.");
    
    quitf(_fail, "Participant found solution more optimal than jury's. Participant: %d, jury: %d", out_s, jury_s);
}
