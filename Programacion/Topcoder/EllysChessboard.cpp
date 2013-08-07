#line 2 "EllysChessboard.cpp"

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

vector<string> a;
int x[65];
int y[65];
int m;
int dp[17][17][17][17];

int solve(int left, int right, int down , int up) {
	if (dp[left][right][down][up]!=-1) return dp[left][right][down][up];
	
	int tmp = 1000000;
	bool done = 0;
	for (int i=0; i<m; i++) {
		if (x[i]<left || x[i]>right || y[i]<down || y[i]>up) {
			int left2 = min(left, x[i]);
			int right2 = max(right, x[i]);
			int down2 = min(down, y[i]);
			int up2 = max(up, y[i]);
			
			int cost = 0;
			
			for (int j=0; j<m; j++) {
				if (x[j]<left || x[j]>right || y[j]<down || y[j]>up) {
					if (x[j]>=left2 && x[j]<=right2 && y[j]>=down2 && y[j]<=up2) {
						int tmp = max(abs(x[j]-x[i]),abs(y[j]-y[i]));
						tmp = max(tmp, abs(x[j]-left2));
						tmp = max(tmp, abs(x[j]-right2));
						tmp = max(tmp, abs(y[j]-down2));
						tmp = max(tmp, abs(y[j]-up2));
						cost += tmp;
					}
				}
			}
			done = 1;
			cost += solve(left2,right2,down2,up2);
			tmp = min(cost,tmp);
		}
	}
	
	if (!done) tmp = 0;
	dp[left][right][down][up] = tmp;
		
	return tmp;
}						

class EllysChessboard {
	public:
	int minCost(vector <string> board) {
		int ans = 1000000;
		a = board;
		for (int i=0; i<8; i++) for (int j=0; j<8; j++) if (a[i][j]=='#') {
			x[m] = i+j;
			y[m++] = i-j+8;
		}
		for (int i=0; i<17; i++) for (int j=0; j<17; j++) 
			for (int ii=0; ii<17; ii++) for (int jj=0; jj<17; jj++) 
				dp[i][ii][j][jj] = -1;
		
		for (int i=0; i<m; i++) {
			ans = min(ans, solve(x[i],x[i], y[i],y[i]));
		}
		if (ans==1000000) return 0;
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
		cout << "Testing EllysChessboard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375889972;
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
		EllysChessboard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"........",
				                  "........",
				                  "...#....",
				                  ".#......",
				                  ".......#",
				                  "........",
				                  "........",
				                  "........"};
				_expected = 10;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........"};
				_expected = 0;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".#......",
				                  "........",
				                  "..#..#.#",
				                  "...#..#.",
				                  "........",
				                  "...#...#",
				                  "...#...#",
				                  "........"};
				_expected = 58;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"##..####",
				                  "#####..#",
				                  "..#.#...",
				                  "#..##.##",
				                  ".#.###.#",
				                  "####.###",
				                  "#.#...#.",
				                  "##....#."};
				_expected = 275;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"########",
				                  "########",
				                  "########",
				                  "########",
				                  "########",
				                  "########",
				                  "########",
				                  "########"};
				_expected = 476;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
