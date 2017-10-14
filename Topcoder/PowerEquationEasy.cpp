
#line 3 "PowerEquationEasy.cpp"
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

long long f[24];
bool vis[1000010];

int gcd(int a, int b) {
    if (b == 0) return a;
    if (a < b) return gcd(b, a);
    return gcd(b, a%b);
}

class PowerEquationEasy {
	public:
	int count(int n) {

        int mod = 1000000007;

		long long res = (long long) n*n;

		for (int i=1; i<24; i++) {
            for (int j=1; j<=i; j++) {
                for (int k=1; k<=i; k++) {
                    f[i] += n*gcd(j, k)/max(j, k);
                    f[i] %= res;
                }
            }
		}

		for (int i=2; i<=n; i++) if (!vis[i]) {
            int x = i;
            int k = 1;
            while (x<=n) {
                k++;
                vis[x] = true;
                x *= i;
            }
            res += f[k-1];
            res %= mod;
		}

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
		cout << "Testing PowerEquationEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508017933;
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
		PowerEquationEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				_expected = 6;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 15;
				_received = _obj.count(n); break;
			}
			case 2:
			{
				int n = 100;
				_expected = 21620;
				_received = _obj.count(n); break;
			}
			case 3:
			{
				int n = 22306;
				_expected = 68467;
				_received = _obj.count(n); break;
			}
			case 4:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.count(n); break;
			}
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
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
