#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int q = atoi(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    string pattern = string(argv[4]);
    
    cout << q << "\n";

    for (int i = 0; i < q; ++i) {
        string s = rnd.next(pattern + string("{") + to_string(n) + string("}"));
        string t = rnd.next(pattern + string("{") + to_string(m) + string("}"));
        cout << s << "\n" << t << "\n";
    }
}
