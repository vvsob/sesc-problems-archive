#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    string s = inf.readLine("[A-Z]{1,100000}", "s");
    inf.readEof();
}
