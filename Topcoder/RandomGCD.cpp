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


class RandomGCD {
	public:
	int countTuples(int N, int K, int low, int high) ;
};

int mod = 1000000007;

int f(int a, int b) {
    if (b==0) return 1;
    long long tmp = f(a, b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return (int)tmp;
    tmp = (tmp*a)%mod;
    return (int)tmp;
}

int solve(int N, int K, int low, int high) {
    if (high<K) return 0;
    low = ((low-1)/K+1);
    high = (high/K);

    int res = f(high-low+1, N);

    if (low>=high) {
        if (low==1) return 1;
        return 0;
    }

    for (int i=low; i<=high; i++) {
        int x = i;
        for (int j=2; j<=x/j; j++) if (x%j==0) {
            res = (res - solve(N, j, low, high))%mod;
            res = (res + mod)%mod;
            if (x/j!=j) {
                res = (res - solve(N, x/j, low, high))%mod;
                res = (res + mod)%mod;
            }
        }
        if (x!=1) {
            res = (res - solve(N, x, low, high))%mod;
            res = (res + mod)%mod;
        }
    }

    return res;
}

int RandomGCD::countTuples(int N, int K, int low, int high) {
    if (high<K) return 0;
    low = ((low-1)/K+1);
    high = (high/K);

    int res = f(high-low+1, N);

    if (low>=high) {
        if (low==1) return 1;
        return 0;
    }

    for (int i=low; i<=high; i++) {
        int x = i;
        for (int j=2; j<=x/j; j++) if (x%j==0) {
            res = (res - solve(N, j, low, high))%mod;
            res = (res + mod)%mod;
            if (x/j!=j) {
                res = (res - solve(N, x/j, low, high))%mod;
                res = (res + mod)%mod;
            }
        }
        if (x!=1) {
            res = (res - solve(N, x, low, high))%mod;
            res = (res + mod)%mod;
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
		cout << "Testing RandomGCD (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395414859;
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
		RandomGCD _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 2;
				int low = 2;
				int high = 4;
				_expected = 3;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 1:
			{
				int N = 2;
				int K = 100;
				int low = 2;
				int high = 4;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 2:
			{
				int N = 1;
				int K = 5;
				int low = 5;
				int high = 5;
				_expected = 1;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 3:
			{
				int N = 73824;
				int K = 17347;
				int low = 9293482;
				int high = 9313482;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 4:
			{
				int N = 222;
				int K = 222;
				int low = 222;
				int high = 22222;
				_expected = 339886855;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
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
