#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class CountingSeries {
	public:
	long long countThem(long long a, long long b, long long c, long long d, long long upperBound) ;
};

long long v[80];
int m;

long long CountingSeries::countThem(long long a, long long b, long long c, long long d, long long upperBound) {
	if (c<=upperBound) v[m++] = c;
	if (d!=1) {
        long long tmp = c;
        while (tmp <= upperBound/d) {
           tmp *= d;
           v[m++] = tmp;
        }
	}

	long long ans = m;
	if (a<=upperBound) {
        ans += (upperBound-a)/b + 1;
	}
	for (int i=0; i<m; i++) {
        if (v[i]>=a && (v[i]-a)%b==0) ans--;
	}

	return ans;
};

//BEGIN CUT HERE
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
		cout << "Testing CountingSeries (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1386146830;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CountingSeries _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long a = 1LL;
				long long b = 1LL;
				long long c = 1LL;
				long long d = 2LL;
				long long upperBound = 1000LL;
				_expected = 1000LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 1:
			{
				long long a = 3LL;
				long long b = 3LL;
				long long c = 1LL;
				long long d = 2LL;
				long long upperBound = 1000LL;
				_expected = 343LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 2:
			{
				long long a = 40LL;
				long long b = 77LL;
				long long c = 40LL;
				long long d = 100000LL;
				long long upperBound = 40LL;
				_expected = 1LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 3:
			{
				long long a = 452LL;
				long long b = 24LL;
				long long c = 4LL;
				long long d = 5LL;
				long long upperBound = 600LL;
				_expected = 10LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 4:
			{
				long long a = 234LL;
				long long b = 24LL;
				long long c = 377LL;
				long long d = 1LL;
				long long upperBound = 10000LL;
				_expected = 408LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			/*case 5:
			{
				long long a = LL;
				long long b = LL;
				long long c = LL;
				long long d = LL;
				long long upperBound = LL;
				_expected = LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}*/
			/*case 6:
			{
				long long a = LL;
				long long b = LL;
				long long c = LL;
				long long d = LL;
				long long upperBound = LL;
				_expected = LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}*/
			/*case 7:
			{
				long long a = LL;
				long long b = LL;
				long long c = LL;
				long long d = LL;
				long long upperBound = LL;
				_expected = LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
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

//END CUT HERE
