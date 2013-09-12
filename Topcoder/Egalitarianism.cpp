#line 2 "Egalitarianism.cpp"

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

int n;
vector<int> e[51];
bool vis[51];
int dist[51];
int q[100];
int in,fn;

class Egalitarianism {
	public:
	
	void dfs(int p) {
		vis[p] = 1;
		for (int i=0; i<e[p].size(); i++) if (!vis[e[p][i]]) {
			dfs(e[p][i]);
		}
	}
	
	int bfs(int p) {
		for (int i=0; i<n; i++) dist[i] = -1;
		dist[p] = 0;
		in = fn = 0;
		q[fn++] = p;
		int m = 0; 
		while (in<fn) { 
			p = q[in++];
			m = max(m,dist[p]);
			for (int i=0; i<e[p].size(); i++) {
				if (dist[e[p][i]]==-1) {
					dist[e[p][i]] = 1 + dist[p];
					q[fn++] = e[p][i];
				}
			}
		}
		return m;
	}
	
	int maxDifference(vector <string> isFriend, int d) {
		n = isFriend.size();
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (isFriend[i][j]=='Y') {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		dfs(0);
		for (int i=0; i<n; i++) if (!vis[i]) return -1;
		int ans = 0;
		for (int i=0; i<n; i++) {
			ans = max(ans, bfs(i));
		}
		return d*ans;
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
		cout << "Testing Egalitarianism (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375465658;
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
		Egalitarianism _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string isFriend[] = {"NYN",
				                     "YNY",
				                     "NYN"};
				int d = 10;
				_expected = 20;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 1:
			{
				string isFriend[] = {"NN",
				                     "NN"};
				int d = 1;
				_expected = -1;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 2:
			{
				string isFriend[] = {"NNYNNN",
				                     "NNYNNN",
				                     "YYNYNN",
				                     "NNYNYY",
				                     "NNNYNN",
				                     "NNNYNN"};
				int d = 1000;
				_expected = 3000;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 3:
			{
				string isFriend[] = {"NNYN",
				                     "NNNY",
				                     "YNNN",
				                     "NYNN"};
				int d = 584;
				_expected = -1;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 4:
			{
				string isFriend[] = {"NYNYYYN",
				                     "YNNYYYN",
				                     "NNNNYNN",
				                     "YYNNYYN",
				                     "YYYYNNN",
				                     "YYNYNNY",
				                     "NNNNNYN"};
				int d = 5;
				_expected = 20;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 5:
			{
				string isFriend[] = {"NYYNNNNYYYYNNNN",
				                     "YNNNYNNNNNNYYNN",
				                     "YNNYNYNNNNYNNNN",
				                     "NNYNNYNNNNNNNNN",
				                     "NYNNNNYNNYNNNNN",
				                     "NNYYNNYNNYNNNYN",
				                     "NNNNYYNNYNNNNNN",
				                     "YNNNNNNNNNYNNNN",
				                     "YNNNNNYNNNNNYNN",
				                     "YNNNYYNNNNNNNNY",
				                     "YNYNNNNYNNNNNNN",
				                     "NYNNNNNNNNNNNNY",
				                     "NYNNNNNNYNNNNYN",
				                     "NNNNNYNNNNNNYNN",
				                     "NNNNNNNNNYNYNNN"};
				int d = 747;
				_expected = 2988;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 6:
			{
				string isFriend[] = {"NY",
				                     "YN"};
				int d = 0;
				_expected = 0;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			/*case 7:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}*/
			/*case 8:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}*/
			/*case 9:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
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
