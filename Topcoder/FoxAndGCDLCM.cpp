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


class FoxAndGCDLCM {
	public:
	long long get(long long G, long long L) ;
};

long long gcd(long long a, long long b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

long long FoxAndGCDLCM::get(long long G, long long L) {
	if (G==0 || G>L || L%G!=0) return -1;
	long long t = L/G;

	long long sum = 100000000000000LL;
	bool done = 0;
	for (int i=1; (long long)i*i<=t; i++) if (t%i==0 && gcd(i,t/i)==1) {
        sum = min(sum, (long long)(i + t/i)*G);
        done = 1;
	}

	if (!done) return -1;
	return sum;
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
		cout << "Testing FoxAndGCDLCM (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384272521;
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
		FoxAndGCDLCM _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long G = 2LL;
				long long L = 20LL;
				_expected = 14LL;
				_received = _obj.get(G, L); break;
			}
			case 1:
			{
				long long G = 5LL;
				long long L = 8LL;
				_expected = -1LL;
				_received = _obj.get(G, L); break;
			}
			case 2:
			{
				long long G = 1000LL;
				long long L = 100LL;
				_expected = -1LL;
				_received = _obj.get(G, L); break;
			}
			case 3:
			{
				long long G = 100LL;
				long long L = 1000LL;
				_expected = 700LL;
				_received = _obj.get(G, L); break;
			}
			case 4:
			{
				long long G = 10LL;
				long long L = 950863963000LL;
				_expected = 6298430LL;
				_received = _obj.get(G, L); break;
			}
			/*case 5:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
			}*/
			/*case 6:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
			}*/
			/*case 7:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
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
