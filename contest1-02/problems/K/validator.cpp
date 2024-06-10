#include "testlib.h"
using namespace std;

using ll = long long;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 500, "n");
    inf.readEoln();
    vector<int> nums = inf.readInts(n, -1000, 1000, "a_i");
    inf.readEoln();
    inf.readEof();
}
