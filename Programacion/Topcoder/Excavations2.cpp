#line 2 "Excavations2.cpp"

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

long long dp1[55][55][2];
long long dp2[55][55];
int v[55];
bool is[55];
int n;

class Excavations2 {
	public:
	long long count(vector <int> kind, vector <int> found, int K) {
		n = kind.size(); 
		for (int i=0; i<found.size(); i++) is[found[i]] = 1;
		for (int i=0; i<n; i++) if (is[kind[i]]) v[kind[i]]++;
		
		int m = 0;
		dp2[0][K] = 1;
		for (int i=0; i<55; i++) if (v[i]>0) {
			
			for (int j=0; j<=v[i]; j++) for (int k=0; k<=K; k++) for (int t=0; t<2; t++) 
				dp1[j][k][t] = 0;
				
			dp1[0][K][0] = 1;
			
			for (int ii=1; ii<=v[i]; ii++) for (int k=0; k<=K; k++) {
				if (k>0) dp1[ii][k-1][1] += dp1[ii-1][k][0] + dp1[ii-1][k][1] + dp1[ii-1][k-1][1];
				dp1[ii][k][0] = dp1[ii-1][k][0];
			} 
			
			for (int kk=0; kk<=K; kk++) for (int k=0; k<=K; k++) {
				if (k>=(K-kk)) {
					dp2[m+1][k-(K-kk)] += dp1[v[i]][kk][1]*dp2[m][k];
				}
			}
			m++;
		}
		
		return dp2[m][0];
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
		cout << "Testing Excavations2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375540623;
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
		Excavations2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int kind[] = {1, 2, 2, 1};
				int found[] = {1};
				int K = 2;
				_expected = 1LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 1:
			{
				int kind[] = {1, 2, 2, 1};
				int found[] = {1, 2};
				int K = 2;
				_expected = 4LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 2:
			{
				int kind[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2};
				int found[] = {4, 2};
				int K = 3;
				_expected = 6LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 3:
			{
				int kind[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
				int found[] = {50};
				int K = 21;
				_expected = 5567902560LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			/*case 4:
			{
				int kind[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}*/
			/*case 5:
			{
				int kind[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int kind[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
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
