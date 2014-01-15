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


class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) ;
};

bool prime(int n) {
    for (int i=2; i*i<=n; i++) if (n%i==0) return 0;
    return 1;
}

int solve(int n, int k, int f) {
    if (f==1) {
        int t = n - k;
        t = max(t,2);
        while (t<n) {
            if (prime(t)) return 1 + solve(t,k,0);
            t++;
        }
        return 0;
    }
    else {
        int t = n - 1;
        t = max(t,2);
        while (t>=n-k) {
            if (!prime(t)) return 1 + solve(t,k,1);
            t--;
        }
        return 0;
    }
}

int PrimeCompositeGame::theOutcome(int N, int K) {

    int ans = solve(N,K,1);

    if (ans%2==0) return -ans;
    else return ans;

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
		cout << "Testing PrimeCompositeGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384782152;
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
		PrimeCompositeGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 2;
				_expected = 1;
				_received = _obj.theOutcome(N, K); break;
			}
			case 1:
			{
				int N = 58;
				int K = 1;
				_expected = 0;
				_received = _obj.theOutcome(N, K); break;
			}
			case 2:
			{
				int N = 30;
				int K = 3;
				_expected = -2;
				_received = _obj.theOutcome(N, K); break;
			}
			case 3:
			{
				int N = 6;
				int K = 3;
				_expected = 1;
				_received = _obj.theOutcome(N, K); break;
			}
			case 4:
			{
				int N = 526;
				int K = 58;
				_expected = 19;
				_received = _obj.theOutcome(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.theOutcome(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.theOutcome(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.theOutcome(N, K); break;
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
