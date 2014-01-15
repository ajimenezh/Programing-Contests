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


class LittleElephantAndRGB {
	public:
	long long getNumber(vector <string> list, int minGreen) ;
};

long long LittleElephantAndRGB::getNumber(vector <string> list, int minGreen) {
		
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
		cout << "Testing LittleElephantAndRGB (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1382948729;
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
		LittleElephantAndRGB _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string list[] = {"GRG"};
				int minGreen = 2;
				_expected = 1LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 1:
			{
				string list[] = {"GG", "GG"};
				int minGreen = 3;
				_expected = 9LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 2:
			{
				string list[] = {"GRBGRBBRG"};
				int minGreen = 2;
				_expected = 11LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 3:
			{
				string list[] = {"RRBRBBRRR", "R", "B"};
				int minGreen = 1;
				_expected = 0LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 4:
			{
				string list[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"};
				int minGreen = 4;
				_expected = 12430LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			/*case 5:
			{
				string list[] = ;
				int minGreen = ;
				_expected = LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}*/
			/*case 6:
			{
				string list[] = ;
				int minGreen = ;
				_expected = LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}*/
			/*case 7:
			{
				string list[] = ;
				int minGreen = ;
				_expected = LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
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
