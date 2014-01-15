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


class Spacetsk {
	public:
	int countsets(int L, int H, int K) ;
};

int Spacetsk::countsets(int L, int H, int K) {
		
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
		cout << "Testing Spacetsk (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383689369;
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
		Spacetsk _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 1;
				int H = 1;
				int K = 2;
				_expected = 4;
				_received = _obj.countsets(L, H, K); break;
			}
			case 1:
			{
				int L = 1;
				int H = 1;
				int K = 1;
				_expected = 4;
				_received = _obj.countsets(L, H, K); break;
			}
			case 2:
			{
				int L = 2;
				int H = 2;
				int K = 1;
				_expected = 9;
				_received = _obj.countsets(L, H, K); break;
			}
			case 3:
			{
				int L = 2;
				int H = 2;
				int K = 2;
				_expected = 23;
				_received = _obj.countsets(L, H, K); break;
			}
			case 4:
			{
				int L = 5;
				int H = 5;
				int K = 3;
				_expected = 202;
				_received = _obj.countsets(L, H, K); break;
			}
			case 5:
			{
				int L = 561;
				int H = 394;
				int K = 20;
				_expected = 786097180;
				_received = _obj.countsets(L, H, K); break;
			}
			/*case 6:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
			}*/
			/*case 7:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
			}*/
			/*case 8:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
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
