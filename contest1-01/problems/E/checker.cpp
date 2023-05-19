#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Node {
    vector<int> next;
    bool t;
    Node() : next(26, -1), t(false) {}
};

vector<Node> trie;

void add(string& p) {
    int cur = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (trie[cur].next[p[i] - 'a'] == -1) {
            trie[cur].next[p[i] - 'a'] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].next[p[i] - 'a'];
    }
    trie[cur].t = true;
}

void get(int start, vector<int>& entries) {
    int cur = 0;
    // for (int i = start; i < n; ++i) {
    //     if (trie[cur].next[s[i] - 'a'] == -1)
    //         return;
    //     cur = trie[cur].next[s[i] - 'a'];
    //     if (trie[cur].t)
    //         entries.push_back(i + 1);
    // }
}

int n, m;
string s;

int readAns(InStream& in, vector<int>& res) {
    int c;
    c = in.readInt(0, n, "letter count");
    res = in.readInts(n, -1, n, "letter's word");
    int w = 1, cnt = 0;
    int i = 0;
    while (i < n) {
        if (res[i] == -1) {
            i++;
            continue;
        }
        if (res[i] != w)
            return -1;
        int cur = 0;
        while (res[i] == w) {
            if (trie[cur].next[s[i] - 'a'] == -1)
                return -1;
            cur = trie[cur].next[s[i] - 'a'];
            cnt++;
            i++;
        }
        if (!trie[cur].t)
            return -1;
        w++;
    }
    if (cnt != c)
        return -1;
    return c;
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
    m = inf.readInt();
    inf.readEoln();
    s = inf.readLine();

    trie.emplace_back();

    for (int i = 0; i < m; ++i) {
        string p = inf.readLine();
        add(p);
    }

    vector<int> ans_res, ouf_res;
    int ans_c = readAns(ans, ans_res);
    if (ans_c == -1)
        quitf(_fail, "Jury's answer is not valid.");
    int ouf_c = readAns(ouf, ouf_res);
    if (ouf_c == -1)
        quitf(_wa, "Participant's answer is not valid.");
    if (ans_c > ouf_c)
        quitf(_wa, "Participant's answer is not optimal.");
    if (ans_c == ouf_c)
        quitf(_ok, "Participant's answer is correct.");
    quitf(_fail, "Participant found solution more optimal than jury's.");
}
