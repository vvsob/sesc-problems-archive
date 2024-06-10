#include "testlib.h"
#include <vector>
using namespace std;

using ll = long long;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    int q = inf.readInt(1, 1'000'000, "q");
    inf.readEoln();
    string seq = inf.readLine(string("[a-z]{") + to_string(q) + string("}"), "commands");
    int x = 0, y = 0;
    for (int i = 0; i < q; ++i) {
        ensuref(seq[i] == 'u' || seq[i] == 'd' || seq[i] == 'r' || seq[i] == 'l', "commands must be in [urdl]");
        if (seq[i] == 'u')
            y++;
        else if (seq[i] == 'd')
            y--;
        else if (seq[i] == 'r')
            x++;
        else if (seq[i] == 'l')
            x--;
        ensuref(0 <= x && x <= n, "x coordinate must be in range [0, n]");
        ensuref(0 <= y && y <= m, "y coordinate must be in range [0, m]");
    }
    inf.readEof();
}
