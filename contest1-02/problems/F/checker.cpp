#include "testlib.h"
using namespace std;

using ll = long long;

int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);
	
	int oufq = ouf.readInt();
	int ansq = ans.readInt();
	
	if (ansq < 0)	
		quitf(_fail, "Limit is %d, but main solution have made %d queries", 800, 800 - ansq);

	if (oufq < 0)	
		quitf(_wa, "Limit is %d, but solution have made %d queries", 800, 800 - oufq);

    int t = inf.readInt();
	quitf(_ok, "%d numbers guessed successfully, maximum with %d queries", t, 800 - oufq);
}
