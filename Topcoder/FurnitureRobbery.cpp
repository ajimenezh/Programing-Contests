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


class FurnitureRobbery {
	public:
	int leastPushes(vector <string> plan) ;
};

int FurnitureRobbery::leastPushes(vector <string> plan) {
		
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
		cout << "Testing FurnitureRobbery (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393589005;
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
		FurnitureRobbery _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string plan[] = {"......",
				                 ".BBB.X",
				                 ".B.B.X",
				                 "DDCC.Y",
				                 "..AAAY"};
				_expected = 13;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 1:
			{
				string plan[] = {"......",
				                 ".BBB.X",
				                 ".B.B.X",
				                 "....YY",
				                 "..AAAY"};
				_expected = 11;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 2:
			{
				string plan[] = {"...C.C",
				                 "BBBCCC",
				                 "B.B...",
				                 ".XX..Y",
				                 "..AAAY"};
				_expected = 13;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 3:
			{
				string plan[] = {"......",
				                 "ZBBBXY",
				                 "ZBBBXY",
				                 "EAAACC",
				                 "E.DDCC"};
				_expected = 20;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 4:
			{
				string plan[] = {"......",
				                 "BBB...",
				                 "BCBC..",
				                 ".CCC.Y",
				                 "..AAAY"};
				_expected = 16;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 5:
			{
				string plan[] = {".C",
				                 "BC",
				                 "BC",
				                 "B.",
				                 "AA"};
				_expected = -1;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			/*case 6:
			{
				string plan[] = ;
				_expected = ;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string plan[] = ;
				_expected = ;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string plan[] = ;
				_expected = ;
				_received = _obj.leastPushes(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
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
