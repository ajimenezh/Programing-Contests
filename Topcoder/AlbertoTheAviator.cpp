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


class AlbertoTheAviator {
	public:
	int MaximumFlights(int F, vector <int> duration, vector <int> refuel) ;
};

vector<pair<int,int> > v;
int dp[52][50010];

int AlbertoTheAviator::MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
    int n = duration.size();
    for (int i=0; i<n; i++) v.push_back(make_pair(-refuel[i], duration[i]));
    sort(v.begin(),v.end());
    for (int i=0; i<n; i++) {

        for (int j=0; j<=F; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j>=v[i].second) {
                dp[i+1][j-v[i].second-v[i].first] = max(dp[i+1][j-v[i].second-v[i].first], dp[i][j]+1);
            }
        }
    }
    int res = 0;
    for (int i=0; i<=F; i++) res = max(res, dp[n][i]);
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
		cout << "Testing AlbertoTheAviator (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393506978;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlbertoTheAviator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int F = 10;
				int duration[] = {10};
				int refuel[] = {0};
				_expected = 1;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 1:
			{
				int F = 10;
				int duration[] = {8, 4};
				int refuel[] = {0, 2};
				_expected = 2;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 2:
			{
				int F = 12;
				int duration[] = {4, 8, 2, 1};
				int refuel[] = {2, 0, 0, 0};
				_expected = 3;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 3:
			{
				int F = 9;
				int duration[] = {4, 6};
				int refuel[] = {0, 1};
				_expected = 2;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 4:
			{
				int F = 100;
				int duration[] = {101};
				int refuel[] = {100};
				_expected = 0;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 5:
			{
				int F = 1947;
				int duration[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
				int refuel[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
				_expected = 3;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			/*case 6:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
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
