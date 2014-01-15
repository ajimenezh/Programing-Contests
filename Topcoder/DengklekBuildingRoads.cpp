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


class DengklekBuildingRoads {
	public:
	int numWays(int N, int M, int K) ;
};

const int mod = 1000000007;
int dp[2][31][31][1<<9];
int n,m,k;

int DengklekBuildingRoads::numWays(int N, int M, int K) {
    n = N;
    m = M;
    k = K;

    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            for (int t=0; t<(1<<(k+1)); t++) {
                dp[0][i][j][t] = 0;
            }
        }
    }

    dp[0][1][0][0] = 1;

    for (int i=0; i<n; i++) {
        int next = 1 - i%2;

        for (int j=i+1; j<=n; j++)
            for (int t=0; t<=m; t++)
                for (int mask=0; mask<(1<<(k+1)); mask++)
                    dp[next][j][t][mask] = 0;

        for (int j=i+1; j<=n; j++) {
            for (int t=0; t<=m; t++) {
                for (int mask=0; mask<(1<<(k+1)); mask++) if (dp[i%2][j][t][mask]) {

                    if ((mask&1)==0) dp[next][i+2][t][mask>>1] = (dp[next][i+2][t][mask>>1] + dp[i%2][j][t][mask])%mod;

                    for (int jj=j; jj<min(n,i+k+1); jj++) {
                        for (int tt=1; tt<=(m-t); tt++) {
                            int mask2 = mask;

                            if (tt%2==1) mask2 ^= 1;
                            if (tt%2==1) mask2 ^= (1<<(jj-i));

                            dp[i%2][jj+1][t+tt][mask2] = (dp[i%2][jj+1][t+tt][mask2] + dp[i%2][j][t][mask])%mod;
                        }
                    }

                    //cout<<i<<" "<<j<<" "<<t<<" "<<mask<<" "<<dp[i%2][j][t][mask]<<endl;

                }
            }
        }
    }

    int ans = 0;

    for (int i=0; i<n; i++) ans = (ans + dp[n%2][i][m][0])%mod;

    return dp[n%2][n+1][m][0];
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
		cout << "Testing DengklekBuildingRoads (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384434336;
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
		DengklekBuildingRoads _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 4;
				int K = 1;
				_expected = 3;
				_received = _obj.numWays(N, M, K); break;
			}
			case 1:
			{
				int N = 4;
				int M = 3;
				int K = 3;
				_expected = 4;
				_received = _obj.numWays(N, M, K); break;
			}
			case 2:
			{
				int N = 2;
				int M = 1;
				int K = 1;
				_expected = 0;
				_received = _obj.numWays(N, M, K); break;
			}
			case 3:
			{
				int N = 5;
				int M = 0;
				int K = 3;
				_expected = 1;
				_received = _obj.numWays(N, M, K); break;
			}
			case 4:
			{
				int N = 10;
				int M = 20;
				int K = 5;
				_expected = 26964424;
				_received = _obj.numWays(N, M, K); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.numWays(N, M, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.numWays(N, M, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.numWays(N, M, K); break;
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
