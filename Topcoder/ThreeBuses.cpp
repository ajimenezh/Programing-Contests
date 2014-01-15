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


class ThreeBuses {
	public:
	double getProbability(vector <int> wait, vector <int> travel, int timeLeft) ;
};

double dp[3][600010];
int t;
vector<int> w;
vector<int> tr;

double solve(int i, int j) {
    if (i==3) {
        if (j<=t) return 1.0;
        else return 0.0;
    }
    if (j>t) return 0.0;
    if (dp[i][j]>=-0.5) return dp[i][j];

    double res = 0.0;
    for (int k=0; k<=w[i]; k++) {
        res += 1.0/(w[i]+1.0)*solve(i+1, min(t+1, j+tr[i]+k));
    }

    dp[i][j] = res;
    return res;
}

double ThreeBuses::getProbability(vector <int> wait, vector <int> travel, int timeLeft) {
	t = timeLeft;
	w = wait;
	tr = travel;

	for (int i=0; i<3; i++) {
        for (int j=0; j<=t+5; j++) dp[i][j] = -1;
	}

	return solve(0,0);
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
		cout << "Testing ThreeBuses (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388409510;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ThreeBuses _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int wait[] = {0, 0, 0};
				int travel[] = {10, 15, 10};
				int timeLeft = 47;
				_expected = 1.0;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
			}
			case 1:
			{
				int wait[] = {0, 0, 0};
				int travel[] = {10, 15, 10};
				int timeLeft = 35;
				_expected = 1.0;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
			}
			case 2:
			{
				int wait[] = {1, 100, 1};
				int travel[] = {10, 10, 10};
				int timeLeft = 52;
				_expected = 0.21;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
			}
			case 3:
			{
				int wait[] = {100, 100, 70};
				int travel[] = {1, 1, 1};
				int timeLeft = 47;
				_expected = 0.020281904761904737;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
			}
			/*case 4:
			{
				int wait[] = ;
				int travel[] = ;
				int timeLeft = ;
				_expected = ;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
			}*/
			/*case 5:
			{
				int wait[] = ;
				int travel[] = ;
				int timeLeft = ;
				_expected = ;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
			}*/
			/*case 6:
			{
				int wait[] = ;
				int travel[] = ;
				int timeLeft = ;
				_expected = ;
				_received = _obj.getProbability(vector <int>(wait, wait+sizeof(wait)/sizeof(int)), vector <int>(travel, travel+sizeof(travel)/sizeof(int)), timeLeft); break;
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
