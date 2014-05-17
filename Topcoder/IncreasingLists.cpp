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


class IncreasingLists {
	public:
	string makeIncreasingList(string mask) ;
};

string IncreasingLists::makeIncreasingList(string mask) {
		
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
		cout << "Testing IncreasingLists (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397047508;
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
		IncreasingLists _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string mask = "??";
				_expected = "10";
				_received = _obj.makeIncreasingList(mask); break;
			}
			case 1:
			{
				string mask = "???";
				_expected = "1,2";
				_received = _obj.makeIncreasingList(mask); break;
			}
			case 2:
			{
				string mask = "?????????,9";
				_expected = "1,2,3,4,5,9";
				_received = _obj.makeIncreasingList(mask); break;
			}
			case 3:
			{
				string mask = "??????????,9";
				_expected = "impossible";
				_received = _obj.makeIncreasingList(mask); break;
			}
			case 4:
			{
				string mask = "?,10,?????????????????,16,??";
				_expected = "impossible";
				_received = _obj.makeIncreasingList(mask); break;
			}
			case 5:
			{
				string mask = "?2?5??7?,??";
				_expected = "12,50,70,71";
				_received = _obj.makeIncreasingList(mask); break;
			}
			case 6:
			{
				string mask = "???????????????????????????????,???";
				_expected = "1,10,11,100,101,102,103,104,105,106";
				_received = _obj.makeIncreasingList(mask); break;
			}
			/*case 7:
			{
				string mask = ;
				_expected = ;
				_received = _obj.makeIncreasingList(mask); break;
			}*/
			/*case 8:
			{
				string mask = ;
				_expected = ;
				_received = _obj.makeIncreasingList(mask); break;
			}*/
			/*case 9:
			{
				string mask = ;
				_expected = ;
				_received = _obj.makeIncreasingList(mask); break;
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
