#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

string get_code(int x) {
    string res(4, '0');
    for (int i = 3; i >= 0; --i) {
        res[i] = (x % 10) + '0';
        x /= 10;
    }
    return res;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int l = atoi(argv[1]);
    int r = atoi(argv[2]);

    int t = (r - l) + 1;
    cout << t << "\n";
    for (int i = l; i <= r; ++i) {
        cout << get_code(i) << "\n";
    }
}
