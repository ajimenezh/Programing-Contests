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


class SlowDigitalClock {
	public:
	string firstCorrectTime(string currentTime, string clockTime, int secsPerMinute) ;
};

string SlowDigitalClock::firstCorrectTime(string currentTime, string clockTime, int secsPerMinute) {
		
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
		cout << "Testing SlowDigitalClock (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380051940;
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
		SlowDigitalClock _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string currentTime = "01:11";
				string clockTime = "21:09";
				int secsPerMinute = 61;
				_expected = "01:12";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			case 1:
			{
				string currentTime = "01:10";
				string clockTime = "21:09";
				int secsPerMinute = 61;
				_expected = "01:12";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			case 2:
			{
				string currentTime = "12:50";
				string clockTime = "05:21";
				int secsPerMinute = 125;
				_expected = "12:50";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			case 3:
			{
				string currentTime = "05:46";
				string clockTime = "23:50";
				int secsPerMinute = 240;
				_expected = "11:10";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			case 4:
			{
				string currentTime = "12:34";
				string clockTime = "23:45";
				int secsPerMinute = 197;
				_expected = "02:11";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			case 5:
			{
				string currentTime = "12:34";
				string clockTime = "23:45";
				int secsPerMinute = 300;
				_expected = "";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			case 6:
			{
				string currentTime = "00:00";
				string clockTime = "00:01";
				int secsPerMinute = 86;
				_expected = "01:22";
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}
			/*case 7:
			{
				string currentTime = ;
				string clockTime = ;
				int secsPerMinute = ;
				_expected = ;
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}*/
			/*case 8:
			{
				string currentTime = ;
				string clockTime = ;
				int secsPerMinute = ;
				_expected = ;
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
			}*/
			/*case 9:
			{
				string currentTime = ;
				string clockTime = ;
				int secsPerMinute = ;
				_expected = ;
				_received = _obj.firstCorrectTime(currentTime, clockTime, secsPerMinute); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
