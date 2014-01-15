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


class LeftRightDigitsGame2 {
	public:
	string minNumber(string digits, string lowerBound) ;
};

string LeftRightDigitsGame2::minNumber(string digits, string lowerBound) {
		
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
		cout << "Testing LeftRightDigitsGame2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383330592;
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
		LeftRightDigitsGame2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string digits = "565";
				string lowerBound = "556";
				_expected = "556";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 1:
			{
				string digits = "565";
				string lowerBound = "566";
				_expected = "655";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 2:
			{
				string digits = "565";
				string lowerBound = "656";
				_expected = "";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 3:
			{
				string digits = "9876543210";
				string lowerBound = "5565565565";
				_expected = "5678943210";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 4:
			{
				string digits = "8016352";
				string lowerBound = "1000000";
				_expected = "1086352";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			/*case 5:
			{
				string digits = ;
				string lowerBound = ;
				_expected = ;
				_received = _obj.minNumber(digits, lowerBound); break;
			}*/
			/*case 6:
			{
				string digits = ;
				string lowerBound = ;
				_expected = ;
				_received = _obj.minNumber(digits, lowerBound); break;
			}*/
			/*case 7:
			{
				string digits = ;
				string lowerBound = ;
				_expected = ;
				_received = _obj.minNumber(digits, lowerBound); break;
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
