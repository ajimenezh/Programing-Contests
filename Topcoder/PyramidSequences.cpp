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

long long gcd(long long a, long long b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

class PyramidSequences {
	public:
	long long distinctPairs(int N, int M) ;
};

long long PyramidSequences::distinctPairs(int N, int M) {
    N--; M--;
	long long g = gcd(N,M);
	long long ans = (long long)N*M/g;
	int n = N/g;
	int m = M/g;
	ans = ans + 1 - (long long)(n+1)*(m+1)/2 +n + m;
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
		cout << "Testing PyramidSequences (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381003661;
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
		PyramidSequences _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 4;
				_expected = 6LL;
				_received = _obj.distinctPairs(N, M); break;
			}
			case 1:
			{
				int N = 3;
				int M = 5;
				_expected = 5LL;
				_received = _obj.distinctPairs(N, M); break;
			}
			case 2:
			{
				int N = 43;
				int M = 76;
				_expected = 895LL;
				_received = _obj.distinctPairs(N, M); break;
			}
			case 3:
			{
				int N = 2;
				int M = 1000000000;
				_expected = 1000000000LL;
				_received = _obj.distinctPairs(N, M); break;
			}
			case 4:
			{
				int N = 100000;
				int M = 95555;
				_expected = 4777750000LL;
				_received = _obj.distinctPairs(N, M); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = LL;
				_received = _obj.distinctPairs(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = LL;
				_received = _obj.distinctPairs(N, M); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				_expected = LL;
				_received = _obj.distinctPairs(N, M); break;
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
