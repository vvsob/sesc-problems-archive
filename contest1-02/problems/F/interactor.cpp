#include "testlib.h"
using namespace std;

using ll = long long;

int dsum(const string& x) {
    int res = 0;
    for (auto d : x) {
        res += d - '0';
    }
    return res;
}

bool answer(const string& guess, const string& correct) {
    int guess_sum = dsum(guess);
    int correct_sum = dsum(correct);
    bool found = false;
    if (guess == correct) {
        cout << "+" << endl;
        found = true;
    } else if (correct_sum < guess_sum) {
        cout << '<' << endl;
    } else if (correct_sum > guess_sum) {
        cout << '>' << endl;
    } else {
        cout << "=" << endl;
    }
    cout.flush();
    return found;
}

void stop_illegal() {
    cout << "-" << endl;
    cout.flush();
}

int main(int argc, char ** argv){
	registerInteraction(argc, argv);
    int t = inf.readInt();
    inf.readEoln();
    cout << t << endl;
    int min_left = 800;
    for (int i = 0; i < t; ++i) {
        setTestCase(i + 1);
        string correct = inf.readLine("[0-9]{4}");
        cout.flush();
        int left = 800;
        bool found = false;
        while(left > 0 && !found){
            left--;
            string s = ouf.readLine("[0-9]{4}");
            found = answer(s, correct);
        }
        if(!found) {
            stop_illegal();
            quitf(_wa, "couldn't guess the number with 500 questions");
        }
        min_left = min(min_left, left);
    }
    tout << min_left << endl;
    quitf(_ok, "guessed all numbers correct!");
}
