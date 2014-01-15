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


class TurntableService {
	public:
	int calculateTime(vector <string> favorites) ;
};

int TurntableService::calculateTime(vector <string> favorites) {
		
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
		cout << "Testing TurntableService (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379268938;
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
		TurntableService _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string favorites[] = {"0 2", "1", "0 1"};
				_expected = 32;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
			}
			case 1:
			{
				string favorites[] = {"0", "0", "0"};
				_expected = 49;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
			}
			case 2:
			{
				string favorites[] = {"4", "1", "2", "3", "0"};
				_expected = 50;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
			}
			case 3:
			{
				string favorites[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"};
				_expected = 35;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
			}
			/*case 4:
			{
				string favorites[] = ;
				_expected = ;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string favorites[] = ;
				_expected = ;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string favorites[] = ;
				_expected = ;
				_received = _obj.calculateTime(vector <string>(favorites, favorites+sizeof(favorites)/sizeof(string))); break;
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
