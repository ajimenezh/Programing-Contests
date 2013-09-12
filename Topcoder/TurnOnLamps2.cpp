#line 2 "TurnOnLamps2.cpp"

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
vector<int> e[55];
vector<bool> sp[55];
vector<bool> st[55];

int best[55];
bool up[55][55];
bool can[55][55];

void dfs1(int u, int v) {
	
	for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
		dfs1(e[u][i],u);
		up[e[u][i]][u] = (sp[u][i]&&!st[u][i]);
		can[e[u][i]][u] = (sp[u][i]&&!st[u][i]) || !sp[u][i];
	}
}

void dfs(int u, int v) {
	
	for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
		dfs(e[u][i],u);
	}
	
	best[u] = 10000000;
	int sum = 0;
	int all = 0;
	for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
		sum += best[e[u][i]];
		all += up[e[u][i]][u];
	}
	best[u] = sum + all/2;
	
	if (all%2==0) return;
	else {
		if (v==-1) best[u]++;
		else if (!can[u][v]) {
			best[u]++;
		}
		else up[u][v] = 1;
	}
	return;
}
	
	

class TurnOnLamps2 {
	public:
	int minimize(vector <int> roads, string initState, string isImportant) {
		int n = roads.size()+1;
		for (int i=0; i<n-1; i++) {
			int p = roads[i];
			e[i+1].push_back(p);
			e[p].push_back(i+1);
			if (isImportant[i]=='1') {
				sp[i+1].push_back(1);
				sp[p].push_back(1);
			}
			else {
				sp[i+1].push_back(0);
				sp[p].push_back(0);
			}
			if (initState[i]=='1') {
				st[i+1].push_back(1);
				st[p].push_back(1);
			}
			else {
				st[i+1].push_back(0);
				st[p].push_back(0);
			}
		}
		
		dfs1(0,-1);
		dfs(0,-1);
		
		return best[0];
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
		cout << "Testing TurnOnLamps2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375642202;
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
		TurnOnLamps2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int roads[] = {0, 0, 1, 1};
				string initState = "0001";
				string isImportant = "0111";
				_expected = 1;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 1:
			{
				int roads[] = {0, 0, 1, 1};
				string initState = "0000";
				string isImportant = "0111";
				_expected = 2;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 2:
			{
				int roads[] = {0, 0, 1, 1, 4, 4};
				string initState = "100100";
				string isImportant = "011101";
				_expected = 2;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 3:
			{
				int roads[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28};
				string initState = "00101000111111001100111010101";
				string isImportant = "11001011100101100111000110010";
				_expected = 5;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 4:
			{
				int roads[] = {0, 0, 1, 1, 2, 4, 4, 7, 5};
				string initState = "000000010";
				string isImportant = "011111111";
				_expected = 3;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 5:
			{
				int roads[] = {0, 1, 1, 0, 2, 1, 5, 3, 3, 2, 9, 2, 3, 3, 5, 9, 9, 4, 1, 2, 2, 6, 5, 5, 8, 24, 21, 3, 4, 4, 28, 12, 7, 20, 14, 21, 12, 4, 5, 1, 16, 27, 12, 7, 22, 0, 28, 15, 3};
				string initState = "1100000000000000000010000000011010000100000000100";
				string isImportant = "1111111010111101010011111010001111111111110110111";
				_expected = 12;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			/*case 6:
			{
				int roads[] = ;
				string initState = ;
				string isImportant = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}*/
			/*case 7:
			{
				int roads[] = ;
				string initState = ;
				string isImportant = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}*/
			/*case 8:
			{
				int roads[] = ;
				string initState = ;
				string isImportant = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
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
