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


class P8XGraphBuilder {
	public:
	int solve(vector <int> scores) ;
};

int dp[55];

int P8XGraphBuilder::solve(vector <int> scores) {
	int n = scores.size();

	for (int i=0; i<=n; i++) {
        if (i!=n) dp[i] = scores[0];
        for (int j=1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j] + (j-1)*scores[0] + scores[j-(i==n)]);
        }
	}

	return dp[n];
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
		cout << "Testing P8XGraphBuilder (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384511376;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		P8XGraphBuilder _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int scores[] = {1, 3, 0};
				_expected = 8;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 1:
			{
				int scores[] = {0, 0, 0, 10};
				_expected = 10;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 2:
			{
				int scores[] = {1, 2, 3, 4, 5, 6};
				_expected = 12;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 3:
			{
				int scores[] = {5, 0, 0};
				_expected = 15;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 4:
			{
				int scores[] = {1, 3, 2, 5, 3, 7, 5};
				_expected = 20;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			/*case 5:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
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
