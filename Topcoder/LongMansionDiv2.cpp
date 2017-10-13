
#line 3 "LongMansionDiv2.cpp"
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

class LongMansionDiv2 {
	public:
	long long minimalTime(int M, vector <int> t) {

		int sum = 0;
		int m = 1000000;

		for (int i=0; i<t.size(); i++) {
            sum += t[i];
            m = min(m, t[i]);
		}

		long long res = (long long)m*(M-1) + sum;

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
		cout << "Testing LongMansionDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507903830;
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
		LongMansionDiv2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int M = 3;
				int t[] = {1, 2, 1};
				_expected = 6LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int M = 4;
				int t[] = {3, 2, 4, 2};
				_expected = 17LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int M = 5;
				int t[] = {3, 2, 5, 4, 2, 8};
				_expected = 32LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int M = 1000000000;
				int t[] = {1000};
				_expected = 1000000000000LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int M = 1;
				int t[] = {1};
				_expected = 1LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 5:
			{
				int M = ;
				int t[] = ;
				_expected = LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int M = ;
				int t[] = ;
				_expected = LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int M = ;
				int t[] = ;
				_expected = LL;
				_received = _obj.minimalTime(M, vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
