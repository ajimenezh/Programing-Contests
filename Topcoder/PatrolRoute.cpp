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


class PatrolRoute {
	public:
	int countRoutes(int X, int Y, int minT, int maxT) ;
};

long long sumx[20100];
long long sumy[20100];

int PatrolRoute::countRoutes(int x, int y, int minT, int maxT) {

    for (int i=1; i<=x; i++) {
        for (int k=i+2; k<=x; k++) {
            sumx[2*(k-i)] += (k-i-1);
        }
    }
    for (int i=1; i<=y; i++) {
        for (int k=i+2; k<=y; k++) {
            sumy[2*(k-i)] += (k-i-1);
        }
    }

    for (int i=1; i<=maxT; i++) sumy[i] += sumy[i-1];

    long long ans = 0;
    int mod = 1000000007;
    for (int i=0; i<=maxT; i++) if (sumx[i]) {
        int L = minT-i;
        L = max(0,L-1);
        int R = maxT-i;
        R = max(0,R);
        ans = (ans + 6*(sumy[R]-sumy[L])*sumx[i]%mod)%mod;
    }

	return (int)ans;
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
		cout << "Testing PatrolRoute (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384074575;
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
		PatrolRoute _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X = 3;
				int Y = 3;
				int minT = 1;
				int maxT = 20000;
				_expected = 6;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 1:
			{
				int X = 3;
				int Y = 3;
				int minT = 4;
				int maxT = 7;
				_expected = 0;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 2:
			{
				int X = 4;
				int Y = 6;
				int minT = 9;
				int maxT = 12;
				_expected = 264;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 3:
			{
				int X = 7;
				int Y = 5;
				int minT = 13;
				int maxT = 18;
				_expected = 1212;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 4:
			{
				int X = 4000;
				int Y = 4000;
				int minT = 4000;
				int maxT = 14000;
				_expected = 859690013;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			/*case 5:
			{
				int X = ;
				int Y = ;
				int minT = ;
				int maxT = ;
				_expected = ;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}*/
			/*case 6:
			{
				int X = ;
				int Y = ;
				int minT = ;
				int maxT = ;
				_expected = ;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}*/
			/*case 7:
			{
				int X = ;
				int Y = ;
				int minT = ;
				int maxT = ;
				_expected = ;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
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
