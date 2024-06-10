#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    for (int i = 0; i < n - 1; ++i) {
        string line = inf.readString(format("[.#]{%d}", m), "line");
        ensuref(line.back() == '.', "last column must be empty");
    }
    string lastLine = inf.readString(format("[.]{%d}", m), "last line");
    inf.readEof();
}
