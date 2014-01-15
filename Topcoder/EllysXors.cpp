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


class EllysXors {
	public:
	long long getXor(long long L, long long R) ;
};

long long f(int x, long long t) {

    if (x>0) t -= (1LL<<x) - 1;
    long long res = 0;

    res += (t / (1LL<<(x+1)))*(1LL<<x);

    if (t%(1LL<<(x+1))>0 && t%(1LL<<(x+1))<=(1LL<<(x))) res += t%(1LL<<(x+1));

    return res;

}

long long EllysXors::getXor(long long L, long long R) {
	long long ans = 0;
	for (int i=0; i<35; i++) {
        if ((f(i,R)-f(i,L-1))&1) ans += 1LL<<i;
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
		cout << "Testing EllysXors (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384026221;
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
		EllysXors _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long L = 3LL;
				long long R = 10LL;
				_expected = 8LL;
				_received = _obj.getXor(L, R); break;
			}
			case 1:
			{
				long long L = 5LL;
				long long R = 5LL;
				_expected = 5LL;
				_received = _obj.getXor(L, R); break;
			}
			case 2:
			{
				long long L = 13LL;
				long long R = 42LL;
				_expected = 39LL;
				_received = _obj.getXor(L, R); break;
			}
			case 3:
			{
				long long L = 666LL;
				long long R = 1337LL;
				_expected = 0LL;
				_received = _obj.getXor(L, R); break;
			}
			case 4:
			{
				long long L = 1234567LL;
				long long R = 89101112LL;
				_expected = 89998783LL;
				_received = _obj.getXor(L, R); break;
			}
			/*case 5:
			{
				long long L = LL;
				long long R = LL;
				_expected = LL;
				_received = _obj.getXor(L, R); break;
			}*/
			/*case 6:
			{
				long long L = LL;
				long long R = LL;
				_expected = LL;
				_received = _obj.getXor(L, R); break;
			}*/
			/*case 7:
			{
				long long L = LL;
				long long R = LL;
				_expected = LL;
				_received = _obj.getXor(L, R); break;
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
