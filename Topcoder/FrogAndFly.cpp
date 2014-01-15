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


class FrogAndFly {
	public:
	double visibility(int hwall, int dfrog, int dfly, int ylow, int yhigh, vector <int> xwindow, vector <int> ywindow) ;
};

double FrogAndFly::visibility(int hwall, int dfrog, int dfly, int ylow, int yhigh, vector <int> xwindow, vector <int> ywindow) {
		
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
		cout << "Testing FrogAndFly (1100.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380052250;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1100.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FrogAndFly _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int hwall = 10;
				int dfrog = 10;
				int dfly = 10;
				int ylow = 5;
				int yhigh = 15;
				int xwindow[] = {5, 5, 15, 15};
				int ywindow[] = {5, 15, 15, 5};
				_expected = 0.5;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}
			case 1:
			{
				int hwall = 14;
				int dfrog = 10;
				int dfly = 10;
				int ylow = 5;
				int yhigh = 15;
				int xwindow[] = {5, 5, 15, 15};
				int ywindow[] = {5, 15, 15, 5};
				_expected = 0.02;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}
			case 2:
			{
				int hwall = 10;
				int dfrog = 5;
				int dfly = 10;
				int ylow = 5;
				int yhigh = 15;
				int xwindow[] = {10, 20, 15};
				int ywindow[] = {5, 5, 15};
				_expected = 0.4166666666666665;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}
			case 3:
			{
				int hwall = 0;
				int dfrog = 1;
				int dfly = 20;
				int ylow = 10;
				int yhigh = 100;
				int xwindow[] = {0, 10, 20, 30, 15};
				int ywindow[] = {20, 10, 10, 20, 40};
				_expected = 1.0;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}
			case 4:
			{
				int hwall = 100;
				int dfrog = 30;
				int dfly = 10;
				int ylow = 20;
				int yhigh = 40;
				int xwindow[] = {10, 20, 30, 20};
				int ywindow[] = {20, 10, 20, 30};
				_expected = 0.0;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}
			/*case 5:
			{
				int hwall = ;
				int dfrog = ;
				int dfly = ;
				int ylow = ;
				int yhigh = ;
				int xwindow[] = ;
				int ywindow[] = ;
				_expected = ;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int hwall = ;
				int dfrog = ;
				int dfly = ;
				int ylow = ;
				int yhigh = ;
				int xwindow[] = ;
				int ywindow[] = ;
				_expected = ;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int hwall = ;
				int dfrog = ;
				int dfly = ;
				int ylow = ;
				int yhigh = ;
				int xwindow[] = ;
				int ywindow[] = ;
				_expected = ;
				_received = _obj.visibility(hwall, dfrog, dfly, ylow, yhigh, vector <int>(xwindow, xwindow+sizeof(xwindow)/sizeof(int)), vector <int>(ywindow, ywindow+sizeof(ywindow)/sizeof(int))); break;
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
