#line 2 "TreeUnion.cpp"

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

vector<int> e[310][2];
int path[10][2];
int n;
int dist[310];
int in, fn;
int q[310];

void bfs(int p, int id) {
	for (int i=0; i<n; i++) dist[i] = -1;
	dist[p] = 0;
	in = fn = 0;
	q[fn++] = p;
	
	while (in<fn) {
		p = q[in++];
		
		if (dist[p]<10) path[dist[p]][id]++;
		
		for (int i=0; i<e[p][id].size(); i++) {
			int u = e[p][id][i];
			if (dist[u]==-1) {
				dist[u] = 1 + dist[p];
				q[fn++] = u;
			}
		}
	}
}

class TreeUnion {
	public:
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		string s = "";
		for (int i=0; i<tree1.size(); i++) s += tree1[i];
		stringstream ss(s);
		int k = 1;
		while (ss>>s) {
			int a = atoi(s.c_str());
			e[k][0].push_back(a);
			e[a][0].push_back(k);
			k++;
		}
		s = "";
		for (int i=0; i<tree2.size(); i++) s += tree2[i];
		stringstream ss2(s);
		k = 1;
		while (ss2>>s) {
			int a = atoi(s.c_str());
			e[k][1].push_back(a);
			e[a][1].push_back(k);
			k++;
		}
		n = k;
		
		for (int i=0; i<n; i++) {
			bfs(i,0);
			bfs(i,1);
		}
		
		if (K==3) return 0;
		K -= 2;
		double ans = 0;
		for (int i=0; i<10; i++) path[i][0] /= 2;
		for (int i=0; i<10; i++) path[i][1] /= 2;
		for (int i=1; i<K; i++) {
			ans += 2.0*(double)path[i][0]*path[K-i][1]/n/(n-1);
		}
		double res = ans;
		return res;
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
		cout << "Testing TreeUnion (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375798173;
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
		TreeUnion _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tree1[] = {"0"};
				string tree2[] = {"0"};
				int K = 4;
				_expected = 1.0;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 1:
			{
				string tree1[] = {"0 1"};
				string tree2[] = {"0 1"};
				int K = 4;
				_expected = 1.3333333333333333;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 2:
			{
				string tree1[] = {"0 1"};
				string tree2[] = {"0 1"};
				int K = 6;
				_expected = 0.3333333333333333;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 3:
			{
				string tree1[] = {"0 ", "1 1 1"};
				string tree2[] = {"0 1 0 ", "1"};
				int K = 5;
				_expected = 4.0;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 4:
			{
				string tree1[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"};
				string tree2[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"};
				int K = 7;
				_expected = 13.314285714285713;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			/*case 5:
			{
				string tree1[] = ;
				string tree2[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}*/
			/*case 6:
			{
				string tree1[] = ;
				string tree2[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}*/
			/*case 7:
			{
				string tree1[] = ;
				string tree2[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
