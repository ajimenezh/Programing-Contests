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


class ChangingSounds {
	public:
	int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) ;
};

int dp[55][1010];
int n;
int m;
vector<int> v;

int solve(int i, int l) {
    if (l<0) return -1;
    if (l>m) return -1;
    if (i==n) return l;
    if (dp[i][l]>=-1) return dp[i][l];

    int tmp = -1;
    tmp = max(tmp, solve(i+1, l+v[i]));
    tmp = max(tmp, solve(i+1, l-v[i]));

    dp[i][l] = tmp;
    return tmp;
}

int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	v = changeIntervals;
	n = v.size();
	m = maxLevel;
	for (int i=0; i<n; i++) for (int j=0; j<=m; j++) dp[i][j] = -2;
	return solve(0, beginLevel);
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
		cout << "Testing ChangingSounds (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394110128;
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
		ChangingSounds _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int changeIntervals[] = {5, 3, 7};
				int beginLevel = 5;
				int maxLevel = 10;
				_expected = 10;
				_received = _obj.maxFinal(vector <int>(changeIntervals, changeIntervals+sizeof(changeIntervals)/sizeof(int)), beginLevel, maxLevel); break;
			}
			case 1:
			{
				int changeIntervals[] = {15, 2, 9, 10};
				int beginLevel = 8;
				int maxLevel = 20;
				_expected = -1;
				_received = _obj.maxFinal(vector <int>(changeIntervals, changeIntervals+sizeof(changeIntervals)/sizeof(int)), beginLevel, maxLevel); break;
			}
			case 2:
			{
				int changeIntervals[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
				int beginLevel = 40;
				int maxLevel = 243;
				_expected = 238;
				_received = _obj.maxFinal(vector <int>(changeIntervals, changeIntervals+sizeof(changeIntervals)/sizeof(int)), beginLevel, maxLevel); break;
			}
			/*case 3:
			{
				int changeIntervals[] = ;
				int beginLevel = ;
				int maxLevel = ;
				_expected = ;
				_received = _obj.maxFinal(vector <int>(changeIntervals, changeIntervals+sizeof(changeIntervals)/sizeof(int)), beginLevel, maxLevel); break;
			}*/
			/*case 4:
			{
				int changeIntervals[] = ;
				int beginLevel = ;
				int maxLevel = ;
				_expected = ;
				_received = _obj.maxFinal(vector <int>(changeIntervals, changeIntervals+sizeof(changeIntervals)/sizeof(int)), beginLevel, maxLevel); break;
			}*/
			/*case 5:
			{
				int changeIntervals[] = ;
				int beginLevel = ;
				int maxLevel = ;
				_expected = ;
				_received = _obj.maxFinal(vector <int>(changeIntervals, changeIntervals+sizeof(changeIntervals)/sizeof(int)), beginLevel, maxLevel); break;
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
