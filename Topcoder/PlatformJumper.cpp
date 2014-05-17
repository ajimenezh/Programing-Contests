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


class PlatformJumper {
	public:
	int maxCoins(vector <string> platforms, int v, int g) ;
};

bool can[51][51];
int x[51], y[51], c[51];
int n;
int dp[51];

int solve(int i) {
    if (dp[i]>=0) return dp[i];

    int tmp = 0;
    for (int j=0; j<n; j++) if (can[i][j]) tmp = max(tmp, solve(j) + c[j]);

    dp[i] = tmp;
    return tmp;
}

int PlatformJumper::maxCoins(vector <string> platforms, int v, int g) {
	n = platforms.size();
	for (int i=0; i<n; i++) {
        string s = platforms[i];
        stringstream ss(s);
        ss>>x[i]>>y[i]>>c[i];
	}
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (y[i]<=y[j]) continue;
            int deltax = x[i]-x[j];
            long long c1 = (long long)g*deltax*deltax;
            int deltay = y[i]-y[j];
            long long c2 = (long long)v*v*2*deltay;
            if (c1<=c2) can[i][j] = 1;
        }
	}
	for (int i=0; i<n; i++) dp[i] = -1;
	int res = 0;
	for (int i=0; i<n; i++) res = max(res, solve(i) + c[i]);
	return res;
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
		cout << "Testing PlatformJumper (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393588548;
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
		PlatformJumper _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string platforms[] = {"3 10 7", "5 15 7", "8 9 12" };
				int v = 2;
				int g = 10;
				_expected = 14;
				_received = _obj.maxCoins(vector <string>(platforms, platforms+sizeof(platforms)/sizeof(string)), v, g); break;
			}
			case 1:
			{
				string platforms[] = {"0 0 1", "2 4 1", "4 0 1"};
				int v = 1;
				int g = 2;
				_expected = 2;
				_received = _obj.maxCoins(vector <string>(platforms, platforms+sizeof(platforms)/sizeof(string)), v, g); break;
			}
			case 2:
			{
				string platforms[] = {"0 0 1", "5000 5000 10"};
				int v = 100;
				int g = 87;
				_expected = 10;
				_received = _obj.maxCoins(vector <string>(platforms, platforms+sizeof(platforms)/sizeof(string)), v, g); break;
			}
			/*case 3:
			{
				string platforms[] = ;
				int v = ;
				int g = ;
				_expected = ;
				_received = _obj.maxCoins(vector <string>(platforms, platforms+sizeof(platforms)/sizeof(string)), v, g); break;
			}*/
			/*case 4:
			{
				string platforms[] = ;
				int v = ;
				int g = ;
				_expected = ;
				_received = _obj.maxCoins(vector <string>(platforms, platforms+sizeof(platforms)/sizeof(string)), v, g); break;
			}*/
			/*case 5:
			{
				string platforms[] = ;
				int v = ;
				int g = ;
				_expected = ;
				_received = _obj.maxCoins(vector <string>(platforms, platforms+sizeof(platforms)/sizeof(string)), v, g); break;
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
