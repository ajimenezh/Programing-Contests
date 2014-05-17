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


class MarriageProblemRevised {
	public:
	int neededMarriages(vector <string> preferences) ;
};

int MarriageProblemRevised::neededMarriages(vector <string> preferences) {
		
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
		cout << "Testing MarriageProblemRevised (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393593507;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MarriageProblemRevised _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string preferences[] = {"111"};
				_expected = 1;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 1:
			{
				string preferences[] = {"100", "010", "001"};
				_expected = 3;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 2:
			{
				string preferences[] = {"00", "00"};
				_expected = -1;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 3:
			{
				string preferences[] = {"0001", "0001", "0001", "1111"};
				_expected = 2;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 4:
			{
				string preferences[] = {"11101011","00011110","11100100","01010000","01000010","10100011","01110110","10111111"};
				_expected = 3;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			/*case 5:
			{
				string preferences[] = ;
				_expected = ;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string preferences[] = ;
				_expected = ;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string preferences[] = ;
				_expected = ;
				_received = _obj.neededMarriages(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
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
