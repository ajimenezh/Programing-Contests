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


class NoRepeatPlaylist {
	public:
	int numPlaylists(int N, int M, int P) ;
};

const int mod = 1000000007;
long long c[110][110];
int p, n, m;

long long fact(int a) {
    long long res = 1;
    for (int i=1; i<=a; i++) res = (res*i)%mod;
    return  res;
}

long long fpow(long long a, int b) {
    if (b==0) return 1LL;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {

    p = P;
    n = N;
    m = M;

    for (int i=0; i<101; i++) {
        c[i][i] = 1;
        c[i][0] = 1;
        for (int j=1; j<i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
    }

    long long res = 0;

    for (int i=n; i>=m; i--) {

        long long tmp = c[n][i];
        tmp = (tmp*c[i][m])%mod;
        tmp = (tmp*fact(m)%mod);
        tmp = (tmp*fpow(i-m,p-m))%mod;

        if (i%2==n%2) res = (res + tmp)%mod;
        else res = ((res - tmp)%mod + mod)%mod;
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
		cout << "Testing NoRepeatPlaylist (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384443186;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		NoRepeatPlaylist _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int M = 0;
				int P = 3;
				_expected = 1;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 10:
			{
				int N = 2;
				int M = 1;
				int P = 3;
				_expected = 1;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 11:
			{
				int N = 2;
				int M = 2;
				int P = 3;
				_expected = 1;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 1:
			{
				int N = 1;
				int M = 1;
				int P = 3;
				_expected = 0;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 2:
			{
				int N = 2;
				int M = 0;
				int P = 3;
				_expected = 6;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 3:
			{
				int N = 4;
				int M = 0;
				int P = 4;
				_expected = 24;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 4:
			{
				int N = 2;
				int M = 1;
				int P = 4;
				_expected = 2;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			case 5:
			{
				int N = 50;
				int M = 5;
				int P = 100;
				_expected = 222288991;
				_received = _obj.numPlaylists(N, M, P); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				int P = ;
				_expected = ;
				_received = _obj.numPlaylists(N, M, P); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				int P = ;
				_expected = ;
				_received = _obj.numPlaylists(N, M, P); break;
			}*/
			/*case 8:
			{
				int N = ;
				int M = ;
				int P = ;
				_expected = ;
				_received = _obj.numPlaylists(N, M, P); break;
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
