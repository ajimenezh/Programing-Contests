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


class TestBettingStrategy {
	public:
	double winProbability(int initSum, int goalSum, int rounds, int prob) ;
};

double dp[1100][50][10];
int g;
int n;
int p;

double solve(int m, int k, int t) {
    if (m>=g) return 1.0;
    if (k>=n) return 0.0;
    if (m<(1<<t)) return 0.0;
    if (dp[m][k][t]>=-0.5) return dp[m][k][t];

    int next = m - (1<<t);
    double res = 1.0*p/100.0*solve(m+(1<<t), k+1, 0) + (1.0-1.0*p/100.0)*solve(next, k+1, t+1);

    dp[m][k][t] = res;
    return res;
}

double TestBettingStrategy::winProbability(int initSum, int goalSum, int rounds, int prob) {
    g = goalSum;
    n = rounds;
    p = prob;
    for (int i=0; i<=g; i++) for (int j=0; j<n; j++) for (int k=0; k<10; k++) dp[i][j][k] = -1.0;
    return solve(initSum, 0, 0);
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
		cout << "Testing TestBettingStrategy (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388924339;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TestBettingStrategy _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int initSum = 10;
				int goalSum = 11;
				int rounds = 4;
				int prob = 50;
				_expected = 0.875;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
			}
			case 1:
			{
				int initSum = 10;
				int goalSum = 20;
				int rounds = 20;
				int prob = 50;
				_expected = 0.3441343307495117;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
			}
			case 2:
			{
				int initSum = 10;
				int goalSum = 20;
				int rounds = 10;
				int prob = 90;
				_expected = 0.34867844010000015;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
			}
			case 3:
			{
				int initSum = 24;
				int goalSum = 38;
				int rounds = 24;
				int prob = 60;
				_expected = 0.5940784635646947;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
			}
			/*case 4:
			{
				int initSum = ;
				int goalSum = ;
				int rounds = ;
				int prob = ;
				_expected = ;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
			}*/
			/*case 5:
			{
				int initSum = ;
				int goalSum = ;
				int rounds = ;
				int prob = ;
				_expected = ;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
			}*/
			/*case 6:
			{
				int initSum = ;
				int goalSum = ;
				int rounds = ;
				int prob = ;
				_expected = ;
				_received = _obj.winProbability(initSum, goalSum, rounds, prob); break;
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
