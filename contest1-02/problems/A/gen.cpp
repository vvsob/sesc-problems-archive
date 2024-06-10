#include "testlib.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = 1000, m = 1000;
    vector<vector<bool>> field(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            field[i][j] = rnd.next(1, 3) == 1 && (i != n - 1) && (j != m - 1);
        }
    }
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (field[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
}
