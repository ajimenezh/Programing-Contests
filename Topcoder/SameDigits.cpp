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


class SameDigits {
	public:
	int howMany(int n, int k) ;
};

int mod = 44444444;
long long dp[1010][10][2][2];
int n,k;
int pow10[1010];

int solve(int cur, int last, int f, int done) {
    if (cur<0) return 0;
    if (cur==0) return done;
    if (dp[cur][last][f][done]>=0) return dp[cur][last][f][done];

    int tmp = 0;
    if (f==0) {
        for (int i=1; i<10; i++) {
            tmp = (tmp + solve(cur-k,i,1,1))%mod;
            for (int j=1; j<k; j++) {
                tmp = (tmp + solve(cur-j, i, 1, done))%mod;
            }
        }
    }
    else {
        for (int i=0; i<10; i++) if (i!=last) {
            tmp = (tmp + solve(cur-k,i,1,1))%mod;
            for (int j=1; j<k; j++) {
                tmp = (tmp + solve(cur-j, i, 1, done))%mod;
            }
        }
    }
    //cout<<cur<<" "<<last<<" "<<f<<" "<<tmp<<" "<<done<<endl;
    dp[cur][last][f][done] = tmp;
    return tmp;
}

int SameDigits::howMany(int _n, int _k) {
   n = _n; k = _k;
   for (int i=0; i<=n; i++) for (int j=0; j<10; j++) for (int p=0; p<2; p++) for (int l=0; l<2; l++) dp[i][j][p][l] = -1;
   long long res = 0;
   for (int i=1; i<=n; i++) res = (res + solve(i, 0, 0, 0))%mod;
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
		cout << "Testing SameDigits (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393678301;
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
		SameDigits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int k = 2;
				_expected = 9;
				_received = _obj.howMany(n, k); break;
			}
			case 1:
			{
				int n = 2;
				int k = 1;
				_expected = 90;
				_received = _obj.howMany(n, k); break;
			}
			case 2:
			{
				int n = 3;
				int k = 2;
				_expected = 171;
				_received = _obj.howMany(n, k); break;
			}
			case 3:
			{
				int n = 723;
				int k = 38;
				_expected = 23525252;
				_received = _obj.howMany(n, k); break;
			}
			/*case 4:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.howMany(n, k); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.howMany(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.howMany(n, k); break;
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
