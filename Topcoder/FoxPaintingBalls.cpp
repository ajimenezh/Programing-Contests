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


class FoxPaintingBalls {
	public:
	long long theMax(long long R, long long G, long long B, int N) ;
};

long long solve(long long &R, long long &G, long long &B, int N) {
    long long ans = 0;
    if (N%3==0) {
        long long c = min(min(R,G),B);
        N /= 3;
        long long all = N*(N+1) + N*(N-1)/2;
        ans = c / all;
        R -= ans*all;
        G -= ans*all;
        B -= ans*all;
	}
	else if (N%3==1) {
        long long c1 = max(max(R,G),B);
        long long c2 = min(min(R,G),B);
        long long c3 = 0;
        if (R==c1) {
            if (G==c2) c3 = B;
            else c3 = G;
        }
        else if (B==c1) {
            if (G==c2) c3 = R;
            else c3 = G;
        }
        else if (G==c1) {
            if (R==c2) c3 = B;
            else c3 = R;
        }
        N /= 3;
        long long all = N*(N+1) + N*(N-1)/2 + N;
        long long c = c1-c2;
        ans += min(c, c2/all);
        if (ans<c) return ans;
        c1 -= ans*(all+1);
        c2 -= ans*all;
        c3 -= ans*all;
        ans += 3*(c1/(3*all+1));
        long long tmp = (c1/(3*all+1));
        c1 -= tmp*(3*all+1);
        c2 -= tmp*(3*all+1);
        c3 -= tmp*(3*all+1);
        if (c1>all) {
            c1 -= all+1;
            c2 -= all;
            c3 -= all;
            ans++;
        }
        if (c2>all) {
            c2 -= all+1;
            c1 -= all;
            c3 -= all;
            ans++;
        }
        if (c3>all) {
            c2 -= all;
            c1 -= all;
            c3 -= all+1;
            ans++;
        }
        return ans;
	}
	else {
        long long c = min(min(R,G),B);
        N /= 3;
        long long all = N*(N+1) + N*(N-1)/2 + N + N + 1;
        ans = c / all;
        R -= ans*all;
        G -= ans*all;
        B -= ans*all;
	}
	return ans;
}

long long FoxPaintingBalls::theMax(long long R, long long G, long long B, int N) {
    long long ans = 0;
    if (N==1) return R + G + B;
    if (N==2) return min(min(R,G),B);
    ans = solve(R,G,B,N);
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
		cout << "Testing FoxPaintingBalls (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383472601;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FoxPaintingBalls _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long R = 2LL;
				long long G = 2LL;
				long long B = 2LL;
				int N = 3;
				_expected = 1LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 1:
			{
				long long R = 1LL;
				long long G = 2LL;
				long long B = 3LL;
				int N = 3;
				_expected = 0LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 2:
			{
				long long R = 8LL;
				long long G = 6LL;
				long long B = 6LL;
				int N = 4;
				_expected = 2LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 3:
			{
				long long R = 7LL;
				long long G = 6LL;
				long long B = 7LL;
				int N = 4;
				_expected = 2LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 4:
			{
				long long R = 100LL;
				long long G = 100LL;
				long long B = 100LL;
				int N = 4;
				_expected = 30LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 5:
			{
				long long R = 19330428391852493LL;
				long long G = 48815737582834113LL;
				long long B = 11451481019198930LL;
				int N = 3456;
				_expected = 5750952686LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 6:
			{
				long long R = 1LL;
				long long G = 1LL;
				long long B = 1LL;
				int N = 1;
				_expected = 3LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			/*case 7:
			{
				long long R = LL;
				long long G = LL;
				long long B = LL;
				int N = ;
				_expected = LL;
				_received = _obj.theMax(R, G, B, N); break;
			}*/
			/*case 8:
			{
				long long R = LL;
				long long G = LL;
				long long B = LL;
				int N = ;
				_expected = LL;
				_received = _obj.theMax(R, G, B, N); break;
			}*/
			/*case 9:
			{
				long long R = LL;
				long long G = LL;
				long long B = LL;
				int N = ;
				_expected = LL;
				_received = _obj.theMax(R, G, B, N); break;
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
