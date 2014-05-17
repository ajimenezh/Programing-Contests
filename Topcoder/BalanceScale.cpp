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


class BalanceScale {
	public:
	int takeWeights(vector <int> weight) ;
};

int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b, a%b);
}

set<int> d[55];
int dp[55][1<<8];
int n;

int solve(int i, int t, int m) {
    if (m==0) return 0;
    if (i==n) return 10000;
    if (i==t) return solve(i+1, t, m);
    if (dp[i][m]>=0) return dp[i][m];

    int tmp = solve(i+1, t, m);
    int k = 0;
    rep(it, d[t]) {
        if (d[i].find(*it)==d[i].end() && ((1<<k)&m)) m -= (1<<k);
        k++;
    }
    tmp = min(tmp, 1+solve(i+1, t, m));

    dp[i][m] = tmp;
    return tmp;
}

int BalanceScale::takeWeights(vector <int> weight) {
    n = weight.size();
	for (int i=0; i<n; i++) if (weight[i]==1) return 1;
	for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int g = gcd(weight[i], weight[j]);
            if (g==1) return 2;
            bool good = 1;
            for (int k=0; k<n; k++) if (weight[k]%g!=0) {
                good = 0;
                break;
            }
            if (good) return 2;
        }
	}

	int g = weight[0];
	for (int i=1; i<n; i++) g = gcd(g, weight[i]);
	for (int i=0; i<n; i++) {
        int k = weight[i] / g;
        weight[i] /= g;
        for (int j=2; j*j<=k; j++) if (k%j==0) {
            d[i].insert(j);
            while (k>0 && k%j==0) k /= j;
        }
        if (k!=1) d[i].insert(k);
	}
	int tot = 100000;
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) for (int k=0; k<(1<<d[i].size()); k++) dp[j][k] = -1;
        tot = min(tot, 1 + solve(0,i,(1<<d[i].size())-1));
	}
	return tot;
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
		cout << "Testing BalanceScale (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393683664;
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
		BalanceScale _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weight[] = { 5, 4, 1, 8 };
				_expected = 1;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int weight[] = { 2, 3, 8, 9 };
				_expected = 2;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int weight[] = { 60, 105, 490, 42 };
				_expected = 4;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int weight[] = { 15, 25, 9 };
				_expected = 2;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 4:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.takeWeights(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
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
