#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n, k, a, x, b, y;
    n = inf.readInt(1, (int)1e9, "n");
    inf.readSpace();
    k = inf.readInt(0, (int)1e9, "k");
    inf.readEoln();
    a = inf.readInt(0, (int)1e9, "a");
    inf.readSpace();
    x = inf.readInt(0, (int)1e9, "x");
    inf.readEoln();
    b = inf.readInt(0, (int)1e9, "b");
    inf.readSpace();
    y = inf.readInt(0, (int)1e9, "y");
    inf.readEoln();
    inf.readEof();
    string subtask = validator.group();
    if (subtask == "1") {
        ensuref(a == 0, "a == 0 should be true");
        ensuref(x == 0, "x == 0 should be true");
    } else if (subtask == "2") {
        ensuref(a == 0, "a == 0 should be true");
        ensuref(b == 0, "b == 0 should be true");
    } else if (subtask == "3") {
        ensuref(a == b, "a == b should be true");
    } else if (subtask == "4") {
        ensuref(x == y, "x == y should be true");
    }
}
