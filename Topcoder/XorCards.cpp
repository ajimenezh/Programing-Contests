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


class XorCards {
	public:
	long long numberOfWays(vector<long long> number, long long limit) ;
};

long long XorCards::numberOfWays(vector<long long> number, long long limit) {
		
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
		cout << "Testing XorCards (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381008521;
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
		XorCards _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long number[] = {1,2};
				long long limit = 2LL;
				_expected = 3LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}
			case 1:
			{
				long long number[] = {5,5};
				long long limit = 3LL;
				_expected = 2LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}
			case 2:
			{
				long long number[] = {1,2,3,4,5,6,7};
				long long limit = 5LL;
				_expected = 96LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}
			case 3:
			{
				long long number[] = {123, 456, 789, 147, 258, 369, 159, 357};
				long long limit = 500LL;
				_expected = 125LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}
			case 4:
			{
				long long number[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				long long limit = 1000000000000000LL;
				_expected = 4294967296LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}
			case 5:
			{
				long long number[] = {1000000000000000, 999999999999999};
				long long limit = 65535LL;
				_expected = 2LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}
			/*case 6:
			{
				long long number[] = ;
				long long limit = LL;
				_expected = LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}*/
			/*case 7:
			{
				long long number[] = ;
				long long limit = LL;
				_expected = LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
			}*/
			/*case 8:
			{
				long long number[] = ;
				long long limit = LL;
				_expected = LL;
				_received = _obj.numberOfWays(vector<long long>(number, number+sizeof(number)/sizeof(long long)), limit); break;
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
