
#line 3 "InterleavingParenthesisDiv2.cpp"
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

int dp[55][55][110];
int n, m;
string s[2];
const int mod = 1000000007;

int solve(int i, int j, int sum) {

    //cout<<i<<" "<<j<<" "<<sum<<endl;

    if (sum < 0) return 0;
    if (i == n && j == m) {
        if (sum == 0) return 1;
        return 0;
    }
    if (dp[i][j][sum] >= 0) return dp[i][j][sum];

    int tmp = 0;

    if (i < n) {
        tmp += solve(i+1, j, sum + (s[0][i]=='('?1:-1));
    }
    if (j < m) {
        tmp += solve(i, j+1, sum + (s[1][j]=='('?1:-1));
    }

    tmp %= mod;

    dp[i][j][sum] = tmp;

    return tmp;
}

class InterleavingParenthesisDiv2 {
	public:
	int countWays(string s1, string s2) {

		s[0] = s1;
		s[1] = s2;
		n = s1.length();
		m = s2.length();

		for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) for (int k=0; k<=n+m; k++) dp[i][j][k] = -1;

		return solve(0, 0, 0);

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
		cout << "Testing InterleavingParenthesisDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507919627;
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
		InterleavingParenthesisDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s1 = "(()";
				string s2 = "())";
				_expected = 19;
				_received = _obj.countWays(s1, s2); break;
			}
			case 1:
			{
				string s1 = ")";
				string s2 = "(";
				_expected = 1;
				_received = _obj.countWays(s1, s2); break;
			}
			case 2:
			{
				string s1 = "(((((";
				string s2 = ")))))";
				_expected = 42;
				_received = _obj.countWays(s1, s2); break;
			}
			case 3:
			{
				string s1 = "()(()";
				string s2 = "))((())";
				_expected = 10;
				_received = _obj.countWays(s1, s2); break;
			}
			case 4:
			{
				string s1 = "()()()()()()()()()()()()()()()";
				string s2 = "()()()()()()()()";
				_expected = 493841617;
				_received = _obj.countWays(s1, s2); break;
			}
			case 5:
			{
				string s1 = "())())))";
				string s2 = "))((((";
				_expected = 0;
				_received = _obj.countWays(s1, s2); break;
			}
			/*case 6:
			{
				string s1 = ;
				string s2 = ;
				_expected = ;
				_received = _obj.countWays(s1, s2); break;
			}*/
			/*case 7:
			{
				string s1 = ;
				string s2 = ;
				_expected = ;
				_received = _obj.countWays(s1, s2); break;
			}*/
			/*case 8:
			{
				string s1 = ;
				string s2 = ;
				_expected = ;
				_received = _obj.countWays(s1, s2); break;
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
