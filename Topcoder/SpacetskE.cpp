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


class SpacetskE {
	public:
	int countsets(int L, int H, int K) ;
};

long long c[2100][2100];
const long long mod = 1000000007;
int lines[2100];

int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int SpacetskE::countsets(int L, int H, int K) {
    if (K==1) return (L+1)*(H+1);
    long long ans = 0;
    for (int i=0; i<2100; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j=1; j<i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
    }
	for (int j=1; j<=H; j++) {
        int ty = H/j + 1;
        for (int i=0; i<=L; i++) if (gcd(i,j)==1) {
            if (i==0) {
                lines[ty] += L+1;
            }
            else {
                for (int tx=1;;tx++) {
                    int lo = i*(tx-1);
                    int hi = min(i*tx, L+1);

                    if (lo>=hi) break;
                    lines[min(tx,ty)] += 2*(hi-lo);
                }
            }
        }
	}
	for (int t=1; t<2100; t++) ans = (ans + lines[t]*c[t][K])%mod;
	ans %= mod;
	return (int)ans;
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
		cout << "Testing SpacetskE (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383837844;
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
		SpacetskE _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 1;
				int H = 1;
				int K = 2;
				_expected = 4;
				_received = _obj.countsets(L, H, K); break;
			}
			case 1:
			{
				int L = 1;
				int H = 1;
				int K = 1;
				_expected = 4;
				_received = _obj.countsets(L, H, K); break;
			}
			case 2:
			{
				int L = 2;
				int H = 2;
				int K = 1;
				_expected = 9;
				_received = _obj.countsets(L, H, K); break;
			}
			case 3:
			{
				int L = 2;
				int H = 2;
				int K = 2;
				_expected = 23;
				_received = _obj.countsets(L, H, K); break;
			}
			case 4:
			{
				int L = 5;
				int H = 5;
				int K = 3;
				_expected = 202;
				_received = _obj.countsets(L, H, K); break;
			}
			case 5:
			{
				int L = 70;
				int H = 52;
				int K = 18;
				_expected = 296314116;
				_received = _obj.countsets(L, H, K); break;
			}/*
			case 6:
			{
				int L = 200;
				int H = 200;
				int K = 150;
				_expected = 0;
				_received = _obj.countsets(L, H, K); break;
			}
			/*case 7:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
			}*/
			/*case 8:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
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
