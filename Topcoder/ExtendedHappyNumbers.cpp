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


class ExtendedHappyNumbers {
	public:
	long long calcTheSum(int A, int B, int K) ;
};

int dp[3200000];
int vis[3200000];

int fpow(int a, int b) {
    if (b==0) return 1;
    int tmp = fpow(a, b/2);
    if (b%2==0) return tmp*tmp;
    return tmp*tmp*a;
}

int solve(int a, int m) {
    if (vis[a]==2) return a;
    if (dp[a]>0) return dp[a];
    vis[a]++;
    int k = 0;
    int aa = a;
    while (a>0) {
        k += fpow(a%10,m);
        a /= 10;
    }
    dp[aa] = min(aa, solve(k, m));
    vis[aa] = 0;
    return dp[aa];
}

long long ExtendedHappyNumbers::calcTheSum(int A, int B, int K) {
	long long sum = 0;
	for (int i=A; i<=B; i++) {
        sum += solve(i,K);
	}
	return sum;
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
		cout << "Testing ExtendedHappyNumbers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388495102;
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
		ExtendedHappyNumbers _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 5;
				int B = 5;
				int K = 2;
				_expected = 1LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}
			case 1:
			{
				int A = 1;
				int B = 5;
				int K = 2;
				_expected = 14LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}
			case 2:
			{
				int A = 10;
				int B = 99;
				int K = 1;
				_expected = 450LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}
			case 3:
			{
				int A = 535;
				int B = 538;
				int K = 3;
				_expected = 820LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}
			case 4:
			{
				int A = 100000;
				int B = 400000;
				int K = 6;
				_expected = 5169721292LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}
			case 5:
			{
				int A = 1;
				int B = 1000000;
				int K = 5;
				_expected = 4LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}
			/*case 6:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = LL;
				_received = _obj.calcTheSum(A, B, K); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = LL;
				_received = _obj.calcTheSum(A, B, K); break;
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
