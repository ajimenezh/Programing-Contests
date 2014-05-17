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


class LaserShooting {
	public:
	double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) ;
};

double LaserShooting::numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
		
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
		cout << "Testing LaserShooting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396875092;
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
		LaserShooting _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1};
				int y1[] = {-1};
				int y2[] = {1};
				_expected = 0.5;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1,2};
				int y1[] = {-1,-2};
				int y2[] = {1,2};
				_expected = 1.0;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {3,4,7,1};
				int y1[] = {1,2,3,4};
				int y2[] = {4,3,2,1};
				_expected = 0.4623163952488826;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {134,298,151,942};
				int y1[] = {-753,-76,19,568};
				int y2[] = {440,689,-39,672};
				_expected = 1.444210260641501;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y1[] = ;
				int y2[] = ;
				_expected = ;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y1[] = ;
				int y2[] = ;
				_expected = ;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y1[] = ;
				int y2[] = ;
				_expected = ;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
