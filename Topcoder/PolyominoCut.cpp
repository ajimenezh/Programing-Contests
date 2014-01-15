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


class PolyominoCut {
	public:
	int count(int k, int width, int height) ;
};

int PolyominoCut::count(int k, int width, int height) {
		
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
		cout << "Testing PolyominoCut (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379801117;
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
		PolyominoCut _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				int width = 10;
				int height = 20;
				_expected = 200;
				_received = _obj.count(k, width, height); break;
			}
			case 1:
			{
				int k = 3;
				int width = 10;
				int height = 10;
				_expected = 480;
				_received = _obj.count(k, width, height); break;
			}
			case 2:
			{
				int k = 8;
				int width = 800;
				int height = 800;
				_expected = 1704053350;
				_received = _obj.count(k, width, height); break;
			}
			/*case 3:
			{
				int k = ;
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.count(k, width, height); break;
			}*/
			/*case 4:
			{
				int k = ;
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.count(k, width, height); break;
			}*/
			/*case 5:
			{
				int k = ;
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.count(k, width, height); break;
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
