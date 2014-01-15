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


class BricksN {
	public:
	int countStructures(int w, int h, int k) ;
};

int w,h,k;
const int mod = 1000000007;
int ways[55];
int dp[55][55][55][2];
int add(int x, int y) {
    int z = x+y;
    if (z>mod) z -= mod;
    return z;
}

int mul(int x, int y) {
    long long z = (long long)x*y;
    z %= mod;
    return (int)z;
}

int solve1(int x) {
    if (x==0) return 1;
    if (x<0) return 0;
    if (ways[x]>=0) return ways[x];

    int tmp = 0;
    for (int i=1; i<=k; i++) {
        tmp = add(tmp, solve1(x-i));
    }

    ways[x] = tmp;
    return tmp;
}

int solve(int hh, int ww, int x, bool flag=1) { //state at height h, solving with width w and alredy occupying x
    if (hh==h) return 1;
    if (x>ww) return 0;
    if (x==ww) return 1;
    if (dp[hh][ww][x][flag]>=0) return dp[hh][ww][x][flag];

    int tmp = 0;

    for (int i=1; i<=ww; i++) {
        if (x+i>ww) break;
        if (x+i==ww) {
            tmp = add(tmp, mul(ways[i], solve(hh+1,i,0) ) );
        }
        else {
            for (int j=1; j<=ww; j++) {
                if (x+i+j>ww) break;
                else if (x+i+j==ww) tmp = add(tmp, mul( mul(ways[i], solve(hh+1,i,0) ), 1 ) );
                else tmp = add(tmp, mul( mul(ways[i], solve(hh+1,i,0) ), solve(hh,ww,x+i+j) ) );
            }
        }
    }

    if (x==0) {
        for (int j=1; j<=ww; j++) {
            if (j!=ww) tmp = add(tmp, solve(hh, ww, j));
            else tmp = add(tmp, 1);
        }
    }

    dp[hh][ww][x][flag] = tmp;

    return tmp;
}

int BricksN::countStructures(int _w, int _h, int _k) {
    w = _w;
    h = _h;
    k = _k;

    for (int i=0; i<=w; i++) ways[i] = -1;
    for (int i=w; i>=1; i--) ways[i] = solve1(i);

    for (int i=0; i<=h; i++) {
        for (int j=0; j<=w; j++) {
            for (int t=0; t<=w; t++) {
                dp[i][j][t][0] = -1;
                dp[i][j][t][1] = -1;
            }
        }
    }

    int ans = solve(0,w,0);

    return ans;

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
		cout << "Testing BricksN (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1386147349;
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
		BricksN _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w = 3;
				int h = 1;
				int k = 3;
				_expected = 13;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 1:
			{
				int w = 3;
				int h = 2;
				int k = 3;
				_expected = 83;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 2:
			{
				int w = 1;
				int h = 5;
				int k = 1;
				_expected = 6;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 3:
			{
				int w = 10;
				int h = 10;
				int k = 3;
				_expected = 288535435;
				_received = _obj.countStructures(w, h, k); break;
			}
			/*case 4:
			{
				int w = ;
				int h = ;
				int k = ;
				_expected = ;
				_received = _obj.countStructures(w, h, k); break;
			}*/
			/*case 5:
			{
				int w = ;
				int h = ;
				int k = ;
				_expected = ;
				_received = _obj.countStructures(w, h, k); break;
			}*/
			/*case 6:
			{
				int w = ;
				int h = ;
				int k = ;
				_expected = ;
				_received = _obj.countStructures(w, h, k); break;
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
