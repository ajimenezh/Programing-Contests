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


class WinterAndSnowmen {
	public:
	int getNumber(int N, int M) ;
};

const long long mod = 1000000007;
long long dp[2][2100][2100];

int WinterAndSnowmen::getNumber(int N, int M) {
    int k = max(N,M);
    dp[0][0][0] = 1;
    int res = 0;
    int cnt = 0;
    for (int ii=1; ii<=11; ii++) {
        cout<<ii<<endl;
        for (int i=(1<<(ii-1)); i<(1<<ii); i++) {
            if (i>max(N,M)) break;
            int x = i%2;
            int y = 1-x;
            for (int j=0; j<(1<<ii); j++) {
                for (int k=0; k<(1<<ii); k++) {
                    dp[x][j][k] = 0;
                    if (i<=N && i<=M) {
                        dp[x][j][k] = (dp[y][j^i][k] + dp[x][j][k])%mod;
                        dp[x][j][k] = (dp[y][j][k^i] + dp[x][j][k])%mod;
                        dp[x][j][k] = (dp[y][j][k] + dp[x][j][k])%mod;
                    }
                    else if (i<=N) {
                        dp[x][j][k] = (dp[y][j^i][k] + dp[x][j][k])%mod;
                        dp[x][j][k] = (dp[y][j][k] + dp[x][j][k])%mod;
                    }
                    else {
                        dp[x][j][k] = (dp[y][j][k^i] + dp[x][j][k])%mod;
                        dp[x][j][k] = (dp[y][j][k] + dp[x][j][k])%mod;
                    }
                    if (i==max(N,M) && j<k) res = (res + dp[x][j][k])%mod;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;

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
		cout << "Testing WinterAndSnowmen (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1387733884;
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
		WinterAndSnowmen _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				_expected = 4;
				_received = _obj.getNumber(N, M); break;
			}
			case 1:
			{
				int N = 1;
				int M = 1;
				_expected = 1;
				_received = _obj.getNumber(N, M); break;
			}
			case 2:
			{
				int N = 3;
				int M = 5;
				_expected = 74;
				_received = _obj.getNumber(N, M); break;
			}
			case 3:
			{
				int N = 7;
				int M = 4;
				_expected = 216;
				_received = _obj.getNumber(N, M); break;
			}
			case 4:
			{
				int N = 47;
				int M = 74;
				_expected = 962557390;
				_received = _obj.getNumber(N, M); break;
			}
			case 5:
			{
				int N = 2000;
				int M = 2000;
				_expected = 1;
				_received = _obj.getNumber(N, M); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(N, M); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(N, M); break;
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
