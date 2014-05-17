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


class DiceGames {
	public:
	long long countFormations(vector <int> sides) ;
};

long long dp[33][33];
vector<int> a;
int n;

long long solve(int i, int last) {
    if (i==n) return 1;
    if (dp[i][last]>=0) return dp[i][last];

    long long tmp = 0;
    for (int j=last; j<=a[i]; j++) {
        tmp += solve(i+1,j);
    }

    dp[i][last] = tmp;

    return tmp;
}

long long DiceGames::countFormations(vector <int> sides) {
    a = sides;
    sort(a.begin(),a.end());
    n = sides.size();
    for (int i=0; i<=n; i++) for (int j=0; j<=32; j++) dp[i][j] = -1;
    return solve(0,1);
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
		cout << "Testing DiceGames (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392295232;
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
		DiceGames _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sides[] = {4};
				_expected = 4LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}
			case 1:
			{
				int sides[] = {2, 2};
				_expected = 3LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}
			case 2:
			{
				int sides[] = {4, 4};
				_expected = 10LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}
			case 3:
			{
				int sides[] = {3, 4};
				_expected = 9LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}
			case 4:
			{
				int sides[] = {4, 5, 6};
				_expected = 48LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}
			/*case 5:
			{
				int sides[] = ;
				_expected = LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int sides[] = ;
				_expected = LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sides[] = ;
				_expected = LL;
				_received = _obj.countFormations(vector <int>(sides, sides+sizeof(sides)/sizeof(int))); break;
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
