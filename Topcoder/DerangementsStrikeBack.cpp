
#line 3 "DerangementsStrikeBack.cpp"
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

long long dp[100010];
const int mod = 1000000007;

long long fact(int n) {

    long long res = 1;
    for (int i=1; i<=n; i++) res = (res*i)%mod;

    return res;

}

long long f(int n, int m) {

    if (dp[m] >= 0) return dp[m];

    long long res = 0;

    if (n == 0) {
        if (m == 0) res = 1;
        else if (m == 1) res = 0;
        else res = (m-1)*(f(0, m-1) + f(0, m-2));
    }
    else if (m == 0) {
        res = 1;
    }
    else {

        res = n*f(n, m-1) + (m>1?(m-1)*(f(n, m-1) + f(n, m-2)):0);

    }

    res %= mod;

    dp[m] = res;

    return res;
}


class DerangementsStrikeBack {
	public:
	int count(int n, int m) {

		for (int j=0; j<=m; j++) dp[j] = -1;

		for (int j=1; j<=m; j++) f(n, j);

		long long res = 0;

		for (int i=1; i<=m; i++) res ^= dp[i];

        return res;
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
		cout << "Testing DerangementsStrikeBack (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507977819;
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
		DerangementsStrikeBack _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 0;
				int m = 3;
				_expected = 3;
				_received = _obj.count(n, m); break;
			}
			case 1:
			{
				int n = 1;
				int m = 3;
				_expected = 9;
				_received = _obj.count(n, m); break;
			}
			case 2:
			{
				int n = 3;
				int m = 3;
				_expected = 73;
				_received = _obj.count(n, m); break;
			}
			case 3:
			{
				int n = 4;
				int m = 1;
				_expected = 4;
				_received = _obj.count(n, m); break;
			}
			case 4:
			{
				int n = 70;
				int m = 39;
				_expected = 319676671;
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
