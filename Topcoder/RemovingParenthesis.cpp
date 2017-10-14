
#line 3 "RemovingParenthesis.cpp"
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

int n;
string s;
int dp[1<<20];

int solve(int mask) {

    if (mask == (1<<n)-1) return 1;

    if (dp[mask] >= 0) return dp[mask];

    int i = 0;
    while (((1<<i)&mask)!=0) i++;

    int res = 0;

    if (s[i] == '(') {
        for (int j=i+1; j<n; j++) if (((1<<j)&mask)==0 && s[j] == ')') {
            res += solve(mask ^ (1<<i) ^ (1<<j));
        }

    }

    dp[mask] = res;

    return res;

}

class RemovingParenthesis {
	public:
	int countWays(string _s) {

		s = _s;
		n = s.length();
		for (int i=0; i<(1<<n); i++) dp[i] = -1;

		return solve(0);
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing RemovingParenthesis (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507996963;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RemovingParenthesis _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "()()()()()";
				_expected = 1;
				_received = _obj.countWays(s); break;
			}
			case 1:
			{
				string s = "(((())))" ;
				_expected = 24;
				_received = _obj.countWays(s); break;
			}
			case 2:
			{
				string s = "((()()()))" ;
				_expected = 54;
				_received = _obj.countWays(s); break;
			}
			case 3:
			{
				string s = "(())(())(())" ;
				_expected = 8;
				_received = _obj.countWays(s); break;
			}
			case 4:
			{
				string s = "((()))(()(()))((()))";
				_expected = 432;
				_received = _obj.countWays(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.countWays(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.countWays(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.countWays(s); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
