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


class RollingDiceDivOne {
	public:
	long long mostLikely(vector <int> dice) ;
};

long long RollingDiceDivOne::mostLikely(vector <int> dice) {
		
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
		cout << "Testing RollingDiceDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384196337;
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
		RollingDiceDivOne _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dice[] = {6, 6, 8};
				_expected = 11LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 1:
			{
				int dice[] = {10};
				_expected = 1LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 2:
			{
				int dice[] = {2, 3, 4, 5};
				_expected = 9LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 3:
			{
				int dice[] = {1, 10, 1};
				_expected = 3LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 4:
			{
				int dice[] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
				             700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240};
				_expected = 4366828428LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			/*case 5:
			{
				int dice[] = ;
				_expected = LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int dice[] = ;
				_expected = LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dice[] = ;
				_expected = LL;
				_received = _obj.mostLikely(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
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
