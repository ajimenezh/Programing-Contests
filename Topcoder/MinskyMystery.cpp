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


class MinskyMystery {
	public:
	int computeAnswer(long long N) ;
};

int MinskyMystery::computeAnswer(long long N) {
		
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
		cout << "Testing MinskyMystery (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384453930;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MinskyMystery _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 2LL;
				_expected = 9;
				_received = _obj.computeAnswer(N); break;
			}
			case 1:
			{
				long long N = 3LL;
				_expected = 27;
				_received = _obj.computeAnswer(N); break;
			}
			case 2:
			{
				long long N = 4LL;
				_expected = 16;
				_received = _obj.computeAnswer(N); break;
			}
			case 3:
			{
				long long N = 2401LL;
				_expected = 59058;
				_received = _obj.computeAnswer(N); break;
			}
			case 4:
			{
				long long N = 24LL;
				_expected = 86;
				_received = _obj.computeAnswer(N); break;
			}
			/*case 5:
			{
				long long N = LL;
				_expected = ;
				_received = _obj.computeAnswer(N); break;
			}*/
			/*case 6:
			{
				long long N = LL;
				_expected = ;
				_received = _obj.computeAnswer(N); break;
			}*/
			/*case 7:
			{
				long long N = LL;
				_expected = ;
				_received = _obj.computeAnswer(N); break;
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
