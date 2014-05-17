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


class RadarFinder {
	public:
	int possibleLocations(int x1, int y1, int r1, int x2, int y2, int r2) ;
};

int RadarFinder::possibleLocations(int x1, int y1, int r1, int x2, int y2, int r2) {
    if (x1==x2 && y1==y2) {
        if (r1==r2) return -1;
        else return 0;
    }
    long long k = (long long)(x1-x2)*(x1-x2) + (long long)(y1-y2)*(y1-y2);
    if (k > (long long)r1*r1 + (long long)r2*r2 + 2LL*(long long)r1*r2) return 0;
    if (k == (long long)r1*r1 + (long long)r2*r2 + 2LL*(long long)r1*r2) return 1;
    return 2;
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
		cout << "Testing RadarFinder (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392294823;
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
		RadarFinder _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1 = 0;
				int y1 = 0;
				int r1 = 13;
				int x2 = 40;
				int y2 = 0;
				int r2 = 37;
				_expected = 2;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
			}
			case 1:
			{
				int x1 = 0;
				int y1 = 0;
				int r1 = 3;
				int x2 = 0;
				int y2 = 7;
				int r2 = 4;
				_expected = 1;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
			}
			case 2:
			{
				int x1 = 0;
				int y1 = 0;
				int r1 = 5;
				int x2 = 10;
				int y2 = 10;
				int r2 = 3;
				_expected = 0;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
			}
			case 3:
			{
				int x1 = 0;
				int y1 = 0;
				int r1 = 1;
				int x2 = 0;
				int y2 = 0;
				int r2 = 1;
				_expected = -1;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
			}
			case 4:
			{
				int x1 = 0;
				int y1 = 0;
				int r1 = 5;
				int x2 = 1;
				int y2 = 0;
				int r2 = 4;
				_expected = 1;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
			}
			/*case 5:
			{
				int x1 = ;
				int y1 = ;
				int r1 = ;
				int x2 = ;
				int y2 = ;
				int r2 = ;
				_expected = ;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
			}*/
			/*case 6:
			{
				int x1 = ;
				int y1 = ;
				int r1 = ;
				int x2 = ;
				int y2 = ;
				int r2 = ;
				_expected = ;
				_received = _obj.possibleLocations(x1, y1, r1, x2, y2, r2); break;
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
