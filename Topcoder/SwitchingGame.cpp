#line 2 "SwitchingGame.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

class SwitchingGame
{
        public:
        int timeToWin(vector <string> states) {

            int n = states.size();
            int m = states[0].length();

            string s;
            for (int i=0; i<m; i++) {
                s += '-';
            }

            int tot = 0;
            for (int k=0; k<n; k++) {
                bool off = 0, on = 0;
                for (int i=0; i<m; i++) {
                    if (states[k][i]=='-' && s[i]=='+') off = 1;
                    if (states[k][i]=='+' && s[i]=='-') on = 1;
                }
                for (int i=0; i<m; i++) {
                    if (states[k][i]!='?') s[i] = states[k][i];
                    else {
                        for (int j=k+1; j<n; j++) {
                            if (states[j][i]!='?') {
                                if (states[j][i]=='+' && on) s[i] = '+';
                                if (states[j][i]=='-' && off) s[i] = '-';
                                break;
                            }
                        }
                    }
                }
                tot += on;
                tot += off;
                tot++;
            }

            return tot;

        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"++--",
 "--++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, timeToWin(Arg0)); }
	void test_case_1() { string Arr0[] = {"+-++",
 "+-++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, timeToWin(Arg0)); }
	void test_case_2() { string Arr0[] = {"++",
 "+?",
 "?+",
 "++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, timeToWin(Arg0)); }
	void test_case_3() { string Arr0[] = {"+",
 "?",
 "?",
 "?",
 "-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, timeToWin(Arg0)); }
	void test_case_4() { string Arr0[] = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, timeToWin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        SwitchingGame ___test;
        ___test.run_test(-1);

        system("pause"); //Windows Only

        return 0;
}
// END CUT HERE
