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


class ChipArea {
	public:
	double maxArea(int skip, int n) ;
};

double ChipArea::maxArea(int skip, int n) {
		
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
		cout << "Testing ChipArea (1100.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393676484;
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
		ChipArea _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int skip = 0;
				int n = 3;
				_expected = 0.6058657896932963;
				_received = _obj.maxArea(skip, n); break;
			}
			case 1:
			{
				int skip = 3;
				int n = 3;
				_expected = 0.6885306552897291;
				_received = _obj.maxArea(skip, n); break;
			}
			case 2:
			{
				int skip = 7995;
				int n = 25000;
				_expected = 0.002543062783060902;
				_received = _obj.maxArea(skip, n); break;
			}
			case 3:
			{
				int skip = 0;
				int n = 3000;
				_expected = 0.0053171745173182395;
				_received = _obj.maxArea(skip, n); break;
			}
			case 4:
			{
				int skip = 2657;
				int n = 2;
				_expected = 0.4487007515408176;
				_received = _obj.maxArea(skip, n); break;
			}
			case 5:
			{
				int skip = 12321;
				int n = 2;
				_expected = 0.615729203993725;
				_received = _obj.maxArea(skip, n); break;
			}
			case 6:
			{
				int skip = 15952;
				int n = 2;
				_expected = 0.8629558001353441;
				_received = _obj.maxArea(skip, n); break;
			}
			case 7:
			{
				int skip = 2215;
				int n = 3;
				_expected = 0.8157487800137614;
				_received = _obj.maxArea(skip, n); break;
			}
			/*case 8:
			{
				int skip = ;
				int n = ;
				_expected = ;
				_received = _obj.maxArea(skip, n); break;
			}*/
			/*case 9:
			{
				int skip = ;
				int n = ;
				_expected = ;
				_received = _obj.maxArea(skip, n); break;
			}*/
			/*case 10:
			{
				int skip = ;
				int n = ;
				_expected = ;
				_received = _obj.maxArea(skip, n); break;
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
