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


class RedIsGood {
	public:
	double getProfit(int R, int B) ;
};

double dp[2][5005];

double tot[10010];

double RedIsGood::getProfit(int R, int B) {

    double res = 0.0;

    dp[R%2][B] = 1.0;

	for (int i=R; i>=0; i--) {
        for (int j=B; j>=0; j--) {
            if (i==R && j==B) continue;

            dp[i%2][j] = (1.0*(i+1)/(i+j+1))*dp[1-i%2][j] + (1.0*(j+1)/(i+j+1))*dp[i%2][j+1];

            tot[R-i+B-j] += dp[i%2][j]*((R-i)-(B-j));
        }
	}

	for (int i=0; i<=B+R; i++) res = max(res, tot[i]);

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
		cout << "Testing RedIsGood (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396441453;
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
		RedIsGood _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 0;
				int B = 7;
				_expected = 0.0;
				_received = _obj.getProfit(R, B); break;
			}
			case 1:
			{
				int R = 4;
				int B = 0;
				_expected = 4.0;
				_received = _obj.getProfit(R, B); break;
			}
			case 2:
			{
				int R = 5;
				int B = 1;
				_expected = 4.166666666666667;
				_received = _obj.getProfit(R, B); break;
			}
			case 3:
			{
				int R = 2;
				int B = 2;
				_expected = 0.6666666666666666;
				_received = _obj.getProfit(R, B); break;
			}
			case 4:
			{
				int R = 12;
				int B = 4;
				_expected = 8.324175824175823;
				_received = _obj.getProfit(R, B); break;
			}
			case 5:
			{
				int R = 11;
				int B = 12;
				_expected = 1.075642825339958;
				_received = _obj.getProfit(R, B); break;
			}
			/*case 6:
			{
				int R = ;
				int B = ;
				_expected = ;
				_received = _obj.getProfit(R, B); break;
			}*/
			/*case 7:
			{
				int R = ;
				int B = ;
				_expected = ;
				_received = _obj.getProfit(R, B); break;
			}*/
			/*case 8:
			{
				int R = ;
				int B = ;
				_expected = ;
				_received = _obj.getProfit(R, B); break;
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
