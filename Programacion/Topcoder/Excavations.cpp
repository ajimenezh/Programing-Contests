#line 2 "Excavations.cpp"

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

vector<int> d[55];
map<int,int> to;
int n;
int p[55];
vector<int> v;
long long dp[55][55][55][2];
int is[55];
int m;

class Excavations {
	public:

	
	long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
		for (int i=0; i<found.size(); i++) is[found[i]] = 1;
		
		v = depth;
		sort(v.begin(),v.end());
		for (int i=0; i<v.size(); i++) {
			if (i==0) to[v[i]] = m++;
			else if (v[i]!=v[i-1]) to[v[i]] = m++;
		}
		for (int i=0; i<depth.size(); i++) depth[i] = to[depth[i]];
		
		for (int i=0; i<kind.size(); i++) d[kind[i]].push_back(depth[i]);
		
		dp[K][0][m][0] = 1;
		
		for (int i=0; i<55; i++) if (d[i].size()>0) {
			
			sort(d[i].begin(),d[i].end());
			
			for (int k=0; k<=K; k++) for (int ii=0; ii<=m; ii++) for (int jj=0; jj<=m; jj++) 
				dp[k][ii][jj][1] = 0;
			
			if (is[i]) {
				for (int j=0; j<d[i].size(); j++) {
					for (int k=1; k<=K; k++) for (int h=0; h<=m; h++) for (int nh = h+1; nh<=m; nh++) {
						dp[k-1][h][nh][1] += dp[k][h][nh][1];
					}
					for (int k=1; k<=K; k++) for (int h=0; h<=m; h++) for (int nh = max(h,d[i][j])+1; nh<=m; nh++) {
						dp[k-1][max(h,d[i][j])][nh][1] += dp[k][h][nh][0];
					}
				}
			}
			else {

				for (int j=0; j<d[i].size(); j++) {
					for (int k=1; k<=K; k++) for (int h=0; h<=m; h++) for (int nh = h+1; nh<=m; nh++) {
						dp[k-1][h][nh][1] += dp[k][h][nh][1];
					}
					for (int k=1; k<=K; k++) for (int h=0; h<d[i][j]; h++) for (int nh = h+1; nh<=m; nh++) {
						dp[k-1][h][min(nh,d[i][j])][1] += dp[k][h][nh][0];
					}
				}
				
				for (int k=0; k<=K; k++) for (int h=0; h<=m; h++) for (int nh=h+1; nh<=m; nh++) {
					dp[k][h][nh][1] += dp[k][h][nh][0];
				}
			}
			
			for (int k=0; k<=K; k++) for (int ii=0; ii<=m; ii++) for (int jj=0; jj<=m; jj++) {
				dp[k][ii][jj][0] = dp[k][ii][jj][1];
			}
		}
		
		long long ans = 0;
		for (int h=0; h<=m; h++) for (int nh=h+1; nh<=m; nh++) ans += dp[0][h][nh][0];
		
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
		cout << "Testing Excavations (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375466368;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Excavations _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int kind[] = {1, 1, 2, 2};
				int depth[] = {10, 15, 10, 20};
				int found[] = {1};
				int K = 2;
				_expected = 3LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 1:
			{
				int kind[] = {1, 1, 2, 2};
				int depth[] = {10, 15, 10, 20};
				int found[] = {1, 2};
				int K = 2;
				_expected = 4LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 2:
			{
				int kind[] = {1, 2, 3, 4};
				int depth[] = {10, 10, 10, 10};
				int found[] = {1, 2};
				int K = 3;
				_expected = 0LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 3:
			{
				int kind[] = {1, 2, 2, 3, 1, 3, 2, 1, 2};
				int depth[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114};
				int found[] = {1, 2, 3};
				int K = 7;
				_expected = 35LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 4:
			{
				int kind[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
				int depth[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};
				int found[] = {50};
				int K = 18;
				_expected = 9075135300LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int kind[] = ;
				int depth[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int kind[] = ;
				int depth[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int kind[] = ;
				int depth[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
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
