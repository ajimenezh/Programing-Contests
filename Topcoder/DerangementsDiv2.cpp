
#line 3 "DerangementsDiv2.cpp"
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

long long dp[55][55];
const int mod = 1000000007;

long long f(int n, int m) {

    if (dp[n][m] >= 0) return dp[n][m];

    long long res = 0;

    if (n == 0) {
        if (m == 0) return 1;
        if (m == 1) return 0;
        res = (m-1)*(f(0, m-1) + f(0, m-2));
    }
    else if (m == 0) {
        if (n == 0) return 1;
        res = n*f(n-1, 0);
    }
    else {

        res = n*f(n, m-1) + (m>1?(m-1)*(f(n, m-1) + f(n, m-2)):0);

    }

    res %= mod;

    dp[n][m] = res;

    return res;
}

class DerangementsDiv2 {
	public:
	int count(int n, int m) {

        for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) dp[i][j] = -1;

        return f(n, m);
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
		cout << "Testing DerangementsDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507935680;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DerangementsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 0;
				int m = 2;
				_expected = 1;
				_received = _obj.count(n, m); break;
			}
			case 1:
			{
				int n = 2;
				int m = 1;
				_expected = 4;
				_received = _obj.count(n, m); break;
			}
			case 2:
			{
				int n = 1;
				int m = 2;
				_expected = 3;
				_received = _obj.count(n, m); break;
			}
			case 3:
			{
				int n = 3;
				int m = 5;
				_expected = 21234;
				_received = _obj.count(n, m); break;
			}
			case 4:
			{
				int n = 20;
				int m = 27;
				_expected = 88437461;
				_received = _obj.count(n, m); break;
			}
			/*case 5:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.count(n, m); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.count(n, m); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.count(n, m); break;
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
