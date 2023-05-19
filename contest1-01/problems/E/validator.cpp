#include "testlib.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    string subtask = validator.group();    
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, (int)1e5, "m");
    inf.readEoln();
    string s = inf.readLine(format("[a-z]{%d}", n), "s");
    vector<string> p = inf.readLines(m, "[a-z]+", "p_i");
    inf.readEof();

    int total_size = 0;
    set<string> occur;
    for (int i = 0; i < m; ++i) {
        total_size += p[i].size();
        occur.insert(p[i]);
    }
    
    ensuref(total_size <= (int)1e6, "total dictionary size should not be greater than 1e6.");
    ensuref(occur.size() == m, "dictionary strings should be distinct.");

    if (subtask == "1")
        ensuref(m == 1, "m should be equal 1.");
    if (subtask == "2") {
        ensuref(m <= 1000, "m should not be greater than 1000.");
        int x = p[0].size();
        for (int i = 1; i < m; ++i) {
            ensuref(x == p[i].size(), "all |p_i| should be equal.");
        }
    }
    if (subtask == "3") {
        ensuref(m <= 1000, "m should not be greater than 1000.");
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p[i].size(); ++j) {
                ensuref(p[i][j] == 'a', "all p_i,j should be equal 'a'.");
            }
        }
    }
    if (subtask == "4") {
        ensuref(m <= 1000, "m should not be greater than 1000.");
    }
    if (subtask == "5") {
        int x = p[0].size();
        for (int i = 1; i < m; ++i) {
            ensuref(x == p[i].size(), "all |p_i| should be equal.");
        }
    }
}
