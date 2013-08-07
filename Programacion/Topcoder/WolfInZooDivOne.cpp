#line 2 "WolfInZooDivOne.cpp"

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

#define mod 1000000007

int n, m;
int l[310];
int r[310];
int top[310];
long long dp[2][310][310];
int k;

class WolfInZooDivOne {
	public:
	int count(int N, vector <string> L, vector <string> R) {
		n = N;
		string s = "";
		k = 0;
		for (int i=0; i<L.size(); i++) s += L[i];
		stringstream s1(s);
		while (s1>>s) l[k++] = atoi(s.c_str()) + 1;
		s = "";
		for (int i=0; i<R.size(); i++) s += R[i];
		stringstream s2(s);
		k = 0;
		while (s2>>s) r[k++] = atoi(s.c_str()) + 1;
		m = k;
		for (int i=0; i<m; i++) {
			for (int j=0; j<m; j++) if (j!=i) {
				if (l[i]>=l[j] && r[i]<=r[j]) {
					for (int t=i+1; t<m; t++) {
						l[t-1] = l[t];
						r[t-1] = r[t];
					}
					i--;
					m--;
				}
			}
		}
		for (int i=1; i<=n; i++) top[i] = -1;
		for (int i=1; i<=n; i++) {
			int left = 10000;
			int best = -1;
			for (int j=0; j<m; j++) {
				if (l[j]<=i && r[j]>=i && l[j]<left) {
					left = l[j];
					best = j;
				}
			}
			top[i] = best;
		}
		
		dp[0][0][0] = 1;
		
		for (int i=1; i<=n; i++) {
			int next = i%2;
			int last = 1-next;
			for (int j=0; j<=i; j++) for (int k=0; k<=i; k++) dp[next][j][k] = 0;
			for (int j=0; j<i; j++) {
				
				dp[next][i][j] += dp[last][j][0];
				while (dp[next][i][j]>=mod) dp[next][i][j] -= mod;
				dp[next][j][0] += dp[last][j][0];
				while (dp[next][j][0]>=mod) dp[next][j][0] -= mod;
				
				for (int k=1; k<j; k++) {
					if (top[i]!=-1 && l[top[i]]<=j) {
						if (l[top[i]]<=k) {
							dp[next][j][k] += dp[last][j][k];
						}
						else {
							dp[next][j][k] += dp[last][j][k];
							dp[next][i][j] += dp[last][j][k];
						}
					}
					else {
						dp[next][j][k] += dp[last][j][k];
						dp[next][i][j] += dp[last][j][k];
					}
					while (dp[next][j][k]>=mod) dp[next][j][k] -= mod;
					while (dp[next][i][j]>=mod) dp[next][i][j] -= mod;
				}
			}
		}
		
		long long ans = dp[n%2][0][0];
		for (int j=0; j<=n; j++) {
			for (int k=0; k<j; k++) {
				ans += dp[n%2][j][k];
				while (ans>=mod) ans -= mod;
			}
		}
		return ans;
		
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
		cout << "Testing WolfInZooDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375812536;
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
		WolfInZooDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				string L[] = {"0"};
				string R[] = {"4"};
				_expected = 16;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 5;
				string L[] = {"0 1"};
				string R[] = {"2 4"};
				_expected = 21;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 10;
				string L[] = {"0 4 2 7"};
				string R[] = {"3 9 5 9"};
				_expected = 225;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 100;
				string L[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
				string R[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
				_expected = 6419882;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			/*case 4:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}*/
			case 5:
			{
				int N = 4;
				string L[] = {"0 1"};
				string R[] = {"2 2"};
				_expected = 14;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			/*case 6:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
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
