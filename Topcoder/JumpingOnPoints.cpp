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


class JumpingOnPoints {
	public:
	long long sumOfDistances(int N, int S, vector <int> params) ;
};

long long JumpingOnPoints::sumOfDistances(int N, int S, vector <int> params) {
		
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
		cout << "Testing JumpingOnPoints (1500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1387133575;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		JumpingOnPoints _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int S = 0;
				int params[] = {0, 0, 5, 100, 0, 0, 5, 100, 0, 0, 10, 100, 1, 1, 0, 100};
				_expected = 150000000000000LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 3;
				int S = 1;
				int params[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
				_expected = 18LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 4;
				int S = 0;
				int params[] = {0, 1, 1, 100, 0, 1, 1, 100, 1, 1, 0, 100, 0, 0, 1, 2};
				_expected = 6LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 60000;
				int S = 0;
				int params[] = {0, 1, 1, 1000000000, 0, 1, 1, 1000000000, 1, 1, 0, 1000000000, 999999999, 1, 0, 1000000000};
				_expected = 1799969998200030000LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 6;
				int S = 0;
				int params[] = {0, 1, 5, 15, 0, 1, 5, 10, 0, 0, 0, 1,1,1,1,3};
				_expected = 8LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 1000;
				int S = 286;
				int params[] = {11111, 11111, 111111, 11111111, 12121, 12111, 13131, 11111111, 13, 14444, 44312, 222211, 13131, 328655, 11373, 999999993};
				_expected = 738940004832LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int S = ;
				int params[] = ;
				_expected = LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int S = ;
				int params[] = ;
				_expected = LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int S = ;
				int params[] = ;
				_expected = LL;
				_received = _obj.sumOfDistances(N, S, vector <int>(params, params+sizeof(params)/sizeof(int))); break;
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
