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

string s;
int n, m;

void get(int start, vector<int>& entries) {
    int cur = 0;
    for (int i = start; i < n; ++i) {
        if (trie[cur].next[s[i] - 'a'] == -1)
            return;
        cur = trie[cur].next[s[i] - 'a'];
        if (trie[cur].t)
            entries.push_back(i + 1);
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    trie.emplace_back();

    cin >> n >> m;
    cin >> s;
    
    for (int i = 0; i < m; ++i) {
        string p;
        cin >> p;
        add(p);
    }

    vector<pair<int, int>> segments;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        get(i, tmp);
        for (auto j : tmp)
            segments.emplace_back(i, j);
    }

    sort(segments.begin(), segments.end(), cmp);
    vector<int> pind(segments.size());
    vector<int> dp(segments.size());
    vector<int> pred(segments.size(), -1);
    for (int i = 0; i < segments.size(); ++i) {
        int l = -1, r = segments.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (segments[mid].second <= segments[i].first)
                l = mid;
            else
                r = mid;
        }
        ll prev_ind = -1, prev_res = 0;
        if (l != -1) {
            prev_ind = pind[l];
            prev_res = dp[pind[l]];
        }
        dp[i] = prev_res + segments[i].second - segments[i].first;
        pred[i] = prev_ind;
        pind[i] = i;
        if (i > 0 && dp[pind[i - 1]] > dp[i])
            pind[i] = pind[i - 1];
    }
    
    int max_ind = 0;
    for (int i = 1; i < segments.size(); ++i)
        if (dp[i] > dp[max_ind])
            max_ind = i;

    if (segments.size() == 0) {
        cout << "0\n";
        for (int i = 0; i < n; ++i)
            cout << "-1 ";
        cout << "\n";
        return 0;
    }
    cout << dp[max_ind] << "\n";
    vector<pair<int, int>> pick;
    int cur = max_ind;
    while (cur != -1) {
        pick.push_back(segments[cur]);
        cur = pred[cur];
    }

    sort(pick.begin(), pick.end());
    vector<int> res(n, -1);
    for (int k = 0; k < pick.size(); ++k) {
        for (int i = pick[k].first; i < pick[k].second; ++i) {
            res[i] = k + 1;
        }
    }
    for (auto el : res)
        cout << el << " ";
    cout << "\n";
}
