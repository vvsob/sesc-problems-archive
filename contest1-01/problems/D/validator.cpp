#include "testlib.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    string subtask = validator.group();    
    int n = inf.readInt(1, (int)1e6, "n");
    inf.readSpace();
    int d = inf.readInt(0, n - 1, "d");
    inf.readEoln();
    vector<ll> a = inf.readLongs(n, (ll)-1e12, (ll)1e12, "v_i");
    inf.readEoln();
    inf.readEof();
    if (subtask == "1")
        ensuref(n <= 100, "n should not be greater than 100.");
    if (subtask == "2")
        ensuref(n <= 5000, "n should not be greater than 5000.");
    if (subtask == "3") {
        for (auto el : a)
            ensuref(el >= 0, "v_i should not be less than 0.");
    }
    if (subtask == "4") {
        for (auto el : a)
            ensuref(-1000 <= el <= 1000, "abs(v_i) should not be greater than 1000.");
    }
}
