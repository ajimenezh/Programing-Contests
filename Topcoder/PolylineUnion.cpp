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


class PolylineUnion {
	public:
	int countComponents(vector <string> polylines) ;
};

int PolylineUnion::countComponents(vector <string> polylines) {
		
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
		cout << "Testing PolylineUnion (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394279546;
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
		PolylineUnion _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string polylines[] = {"0,0-10,10 0,10-10,0"};
				_expected = 1;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 1:
			{
				string polylines[] = {"0,0-10,5 5,0-15,5-10,10-5,5"};
				_expected = 2;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 2:
			{
				string polylines[] = {"1","3,0-5,5 4,0-4,20"};
				_expected = 2;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 3:
			{
				string polylines[] = {"10,0-10,1-9,2-9,3-8,4 ","8,2-9,2-10,3 ","12,2-11,2-9,1"};
				_expected = 1;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 4:
			{
				string polylines[] = {"0,0-10,0-0,0 20,0-8,0-20,0"};
				_expected = 1;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 5:
			{
				string polylines[] = {"1,1 2,2 3,3 4,4 3,3-4,4"};
				_expected = 3;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 6:
			{
				string polylines[] = {"10,10-20,10 20,10-15,18 15,18-10,10"};
				_expected = 1;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			case 7:
			{
				string polylines[] = {"1,1 1,1"};
				_expected = 1;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}
			/*case 8:
			{
				string polylines[] = ;
				_expected = ;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string polylines[] = ;
				_expected = ;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string polylines[] = ;
				_expected = ;
				_received = _obj.countComponents(vector <string>(polylines, polylines+sizeof(polylines)/sizeof(string))); break;
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
