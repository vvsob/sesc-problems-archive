#include "testlib.h"
using namespace std;

using ll = long long;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int m = inf.readInt(1, 10, "m");
    inf.readEoln();
    for (int i = 1; i <= m; ++i) {
        int k = inf.readInt(1, 10, "k");
        inf.readSpace();
        vector<string> words = inf.readWords(k, "[a-z]+");
        inf.readEoln();
    }
    string text = inf.readLine();
    for (auto c : text) {
        ensuref(('a' <= c && c <= 'z') || c == ' ' || c == '.', "Text should only constist of latin letters, spaces and periods.");
    }
    ensuref(text.length() <= 10000, "Text length should not be greater than 10000.");
    inf.readEof();
}
