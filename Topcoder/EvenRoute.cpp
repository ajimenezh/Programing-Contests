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


class EvenRoute {
	public:
	string isItPossible(vector <int> x, vector <int> y, int wantedParity) ;
};

string EvenRoute::isItPossible(vector <int> x, vector <int> y, int wantedParity) {
		
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
		cout << "Testing EvenRoute (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384116900;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EvenRoute _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {-1,-1,1,1};
				int y[] = {-1,1,1,-1};
				int wantedParity = 0;
				_expected = "CAN";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 1:
			{
				int x[] = {-5,-3,2};
				int y[] = {2,0,3};
				int wantedParity = 1;
				_expected = "CAN";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 2:
			{
				int x[] = {1001, -4000};
				int y[] = {0,0};
				int wantedParity = 1;
				_expected = "CAN";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 3:
			{
				int x[] = {11, 21, 0};
				int y[] = {-20, 42, 7};
				int wantedParity = 0;
				_expected = "CANNOT";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 4:
			{
				int x[] = {0, 6};
				int y[] = {10, -20};
				int wantedParity = 1;
				_expected = "CANNOT";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int wantedParity = ;
				_expected = ;
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int wantedParity = ;
				_expected = ;
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int wantedParity = ;
				_expected = ;
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
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
