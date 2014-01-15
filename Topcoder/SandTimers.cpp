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


class SandTimers {
	public:
	vector <int> badIntervals(vector <int> timers, int maxInterval, int maxTime) ;
};

vector <int> SandTimers::badIntervals(vector <int> timers, int maxInterval, int maxTime) {
		
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
		cout << "Testing SandTimers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379883472;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SandTimers _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int timers[] = { 5, 7 };
				int maxInterval = 10;
				int maxTime = 10;
				int __expected[] = {1, 6, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}
			case 1:
			{
				int timers[] = { 2, 10, 20 };
				int maxInterval = 30;
				int maxTime = 40;
				int __expected[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}
			case 2:
			{
				int timers[] = { 2, 5, 9 };
				int maxInterval = 360;
				int maxTime = 360;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}
			case 3:
			{
				int timers[] = { 4 };
				int maxInterval = 23;
				int maxTime = 47;
				int __expected[] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15, 17, 18, 19, 21, 22, 23 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}
			case 4:
			{
				int timers[] = { 20, 13 };
				int maxInterval = 30;
				int maxTime = 30;
				int __expected[] = {1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 28, 29, 30 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}
			case 5:
			{
				int timers[] = { 20, 17, 13 };
				int maxInterval = 25;
				int maxTime = 30;
				int __expected[] = {18, 19 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}
			/*case 6:
			{
				int timers[] = ;
				int maxInterval = ;
				int maxTime = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}*/
			/*case 7:
			{
				int timers[] = ;
				int maxInterval = ;
				int maxTime = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
			}*/
			/*case 8:
			{
				int timers[] = ;
				int maxInterval = ;
				int maxTime = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.badIntervals(vector <int>(timers, timers+sizeof(timers)/sizeof(int)), maxInterval, maxTime); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
