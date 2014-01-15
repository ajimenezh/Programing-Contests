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


class LittleElephantAndPermutationDiv1 {
	public:
	int getNumber(int N, int K) ;
};

long long dp[51][51][2510];
const long long mod = 1000000007;
long long fact[51];
int K;
int n;

long long solve(int a, int b, int k) {
    if (a==n) return b==0;
    if (dp[a][b][k]>=0) return dp[a][b][k];

    long long tmp = 0;

    tmp = solve(a+1,b+1,k);

    if (a+1+k<K) tmp = (tmp + (solve(a+1,b,k+a+1)*(2*b+1))%mod)%mod;

    if (2*(a+1)+k<K && b!=0) tmp = (tmp + (solve(a+1,b-1,k+2*(a+1))*(b*b))%mod)%mod;

    dp[a][b][k] = tmp;

    return tmp;
}

int LittleElephantAndPermutationDiv1::getNumber(int N, int _K) {
    K = _K;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=N; j++) {
            for (int k=0; k<=K; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    n = N;
    long long ans = 1;
    for (int i=1; i<=n; i++) ans = (ans*i)%mod;
    ans = (ans + mod -solve(0,0,0))%mod;

    for (int i=1; i<=n; i++) ans = (ans*i)%mod;

    return (int)(ans%mod);
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
		cout << "Testing LittleElephantAndPermutationDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380281167;
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
		LittleElephantAndPermutationDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int K = 1;
				_expected = 1;
				_received = _obj.getNumber(N, K); break;
			}
			case 1:
			{
				int N = 2;
				int K = 1;
				_expected = 4;
				_received = _obj.getNumber(N, K); break;
			}
			case 2:
			{
				int N = 3;
				int K = 8;
				_expected = 18;
				_received = _obj.getNumber(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 74;
				_expected = 484682624;
				_received = _obj.getNumber(N, K); break;
			}
			case 4:
			{
				int N = 50;
				int K = 1000;
				_expected = 539792695;
				_received = _obj.getNumber(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(N, K); break;
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
