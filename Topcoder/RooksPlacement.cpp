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


class RooksPlacement {
	public:
	int countPlacements(int N, int M, int K) ;
};

int dp[2][55][55][105];
const int mod = 1000001;

int solve(int n, int m, int p, int k) {
    if (k==0) return 1;
    if (p<0) return 0;
    if (n<0) return 0;
    if (m==0) return 0;
    if (dp[n][m][p][k]>=0) return dp[n][m][p][k];

    int tmp = 0;
    tmp = tmp + ((long long)n*(n-1)/2*solve(n-2,m-1,p,k-2))%mod;
    tmp = tmp + ((long long)n*solve(n-1,m-1,p+1,k-1))%mod;
    tmp = tmp + ((long long)p*solve(n,m-1,p-1,k-1))%mod;
    tmp = tmp + solve(n,m-1,p,k)%mod;
    tmp %= mod;
    dp[n][m][p][k] = tmp;

    return tmp;
}

int RooksPlacement::countPlacements(int N, int M, int K) {

    dp[M%2][N][0][K] = 1;
    for (int i=M; i>0; i--) {
        int next = 1-(i%2);
        for (int j=0; j<=N; j++) {
            for (int k=0; k<=N; k++) {
                for (int t=0; t<=K; t++) {
                    dp[next][j][k][t] = 0;
                }
            }
        }
        for (int j=0; j<=N; j++) {
            for (int k=0; k<=N; k++) {
                for (int t=0; t<=K; t++) {
                    if (j>1 && t>1) dp[next][j-2][k][t-2] = (dp[next][j-2][k][t-2] + (long long)j*(j-1)/2*dp[i%2][j][k][t])%mod;
                    if (j>0 && t>0 && k<N) dp[next][j-1][k+1][t-1] = (dp[next][j-1][k+1][t-1] + (long long)j*dp[i%2][j][k][t])%mod;
                    if (k>0 && t>0) dp[next][j][k-1][t-1] = (dp[next][j][k-1][t-1] + (long long)k*dp[i%2][j][k][t])%mod;
                    dp[next][j][k][t] = (dp[next][j][k][t] + dp[i%2][j][k][t])%mod;
                }
            }
        }
    }

    int res = 0;
    for (int j=0; j<=N; j++) {
        for (int k=0; k<=N; k++) {
            res = (res + dp[0][j][k][0])%mod;
        }
    }

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
		cout << "Testing RooksPlacement (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393589553;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RooksPlacement _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int M = 5;
				int K = 2;
				_expected = 190;
				_received = _obj.countPlacements(N, M, K); break;
			}
			case 1:
			{
				int N = 2;
				int M = 3;
				int K = 3;
				_expected = 6;
				_received = _obj.countPlacements(N, M, K); break;
			}
			case 2:
			{
				int N = 6;
				int M = 7;
				int K = 20;
				_expected = 0;
				_received = _obj.countPlacements(N, M, K); break;
			}
			case 3:
			{
				int N = 23;
				int M = 37;
				int K = 39;
				_expected = 288688;
				_received = _obj.countPlacements(N, M, K); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.countPlacements(N, M, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.countPlacements(N, M, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.countPlacements(N, M, K); break;
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
