#line 2 "LISNumber.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

const long long mod = 1000000007LL;

class LISNumber {
	public:
	int n;
	vector<int> v;
	long long dp[40][1300];
	long long c[1500][40];
	int count(vector <int> cardsnum, int K) {
		v = cardsnum;
		n = v.size();
		int tot = 0;
		
		c[0][0] = 1;
		for (int i=1; i<1500; i++) {
			c[i][0] = 1;
			if (i<40) c[i][i] = 1;
			for (int j=1; j<min(i,40); j++) {
				c[i][j] =( c[i-1][j-1] + c[i-1][j])%mod;
			}
		}
		
		for (int i=0; i<=n; i++) for (int j=0; j<=K; j++) dp[i][j] = 0;
		dp[0][0] = 1;
		
		for (int i=0; i<n; i++) {
			for (int k=0; k<=K; k++) {
				if (dp[i][k]==0) continue;
				
				for (int j=0; j<=v[i]; j++) {
					
					if ((v[i]-j)+k>K) continue;
					if (j>k) continue;
					
					int pos = tot - k + 1 + j;
					
					long long comb = c[k][j]%mod;
					comb = (comb*c[pos+(v[i]-j)-1][v[i]-j])%mod;
					
					dp[i+1][k+(v[i]-j)] = (dp[i+1][k+(v[i]-j)] + (comb*dp[i][k])%mod)%mod;
				}
			}
			tot += v[i];
		}
		
		return dp[n][K];
	}
};

// BEGIN CUT HERE
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
		cout << "Testing LISNumber (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375381591;
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
		LISNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cardsnum[] = {1, 1, 1};
				int K = 2;
				_expected = 4;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}
			case 1:
			{
				int cardsnum[] = {2};
				int K = 1;
				_expected = 0;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}
			case 2:
			{
				int cardsnum[] = {36, 36, 36, 36, 36};
				int K = 36;
				_expected = 1;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}
			case 3:
			{
				int cardsnum[] = {3, 2, 11, 5, 7};
				int K = 20;
				_expected = 474640725;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}
			case 4:
			{
				int cardsnum[] = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26};
				int K = 58;
				_expected = 12133719;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}
			case 5:
			{
				int cardsnum[] = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
				                  36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
				                  7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9};
				int K = 116;
				_expected = 516440918;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}
			/*case 6:
			{
				int cardsnum[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int cardsnum[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
			}*/
			/*case 8:
			{
				int cardsnum[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <int>(cardsnum, cardsnum+sizeof(cardsnum)/sizeof(int)), K); break;
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

// END CUT HERE
