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


class ColorfulCoins {
	public:
	int minQueries(vector<long long> values) ;
};

int dp[65][65];
long long c[64][64];
int n;

int solve(int l, int r) {
    if (r==n) return 1;
    if (dp[l][r]>=0) return dp[l][r];

    vector<int> all;
    int tmp = 100;

    for (int i=l+1; i<=r; i++) {
        int k = min(70LL, c[i][i-1]);
        all.push_back(k);
    }

    sort(all.begin(), all.end());
    for (int i=0; i<all.size(); i++) {
        if (all[i]<i+1) {
            dp[l][r] = 100;
            return 100;
        }
    }

    tmp = min(solve(l, r+1), solve(r+1, r+1)+1);

    if (solve(l, r+2)!=100 && solve(r+1, r+1)>3) tmp = min(tmp, solve(r+1, r+1));

    dp[l][r] = tmp;
    return tmp;
}

int ColorfulCoins::minQueries(vector<long long> values) {
	for (int i=0; i<values.size(); i++) {
        for (int j=0; j<i; j++) c[i][j] = values[i] / values[j] - 1;
	}
	n = values.size();
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[i][j] = -1;
	int res = solve(0,0);
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
		cout << "Testing ColorfulCoins (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397143831;
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
		ColorfulCoins _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long values[] = {1};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 1:
			{
				long long values[] = {270,810,2430};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 2:
			{
				long long values[] = {1, 2, 4};
				_expected = 2;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 3:
			{
				long long values[] = {1, 2, 4, 8, 16};
				_expected = 3;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 4:
			{
				long long values[] = {1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 262440, 787320, 3149280,
				                       9447840, 28343520, 56687040, 170061120, 510183360LL, 1530550080LL, 3061100160LL,
				                       9183300480LL, 27549901440LL, 82649704320LL, 247949112960LL, 1239745564800LL, 3719236694400LL,
				                       14876946777600LL, 44630840332800LL, 223154201664000LL, 669462604992000LL, 2008387814976000LL,
				                       6025163444928000LL, 12050326889856000LL, 24100653779712000LL, 72301961339136000LL,
				                       289207845356544000LL, 867623536069632000LL};
				_expected = 4;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			/*case 5:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 6:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 7:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
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
