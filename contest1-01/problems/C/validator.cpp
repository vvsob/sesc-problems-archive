#include "testlib.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, (int)1e9, "n");
    inf.readSpace();
    int k = inf.readInt(1, (int)1e9, "k");
    inf.readEoln();
    inf.readEof();
}
