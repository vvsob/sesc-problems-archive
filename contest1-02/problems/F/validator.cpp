#include "testlib.h"
using namespace std;

using ll = long long;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 200, "t");
    inf.readEoln();
    for (int i = 1; i <= t; ++i) {
        setTestCase(i);
        string x = inf.readLine("[0-9]{4}", "correct number");
    }
    inf.readEof();
}
