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


class ArcadeManao {
	public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) ;
};

int q[3000];
bool vis[51][51];

int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn) {
	int k = 0;
	int n = level.size();
    int m = level[0].length();
	for (;;k++) {
        int in = 0, fn = 0;
        q[fn++] = (n-1)*m;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) vis[i][j] = 0;
        vis[n-1][0] = 1;
        while (in<fn) {
            int p = q[in++];
            int x = p/m;
            int y = p%m;

            if (y<m-1 && !vis[x][y+1] && level[x][y+1]!='.') {
                vis[x][y+1] = 1;
                q[fn++] = x*m + y+1;
            }
            if (y>0 && !vis[x][y-1] && level[x][y-1]!='.') {
                vis[x][y-1] = 1;
                q[fn++] = x*m + y-1;
            }
            for (int i=1; i<=k; i++) {
                int xx = x + i;
                if (xx>=0 && xx<n && level[xx][y]!='.') {
                    if (!vis[xx][y]) {
                        vis[xx][y] = 1;
                        q[fn++] = xx*m + y;
                    }
                }
                xx = x - i;
                if (xx>=0 && xx<n && level[xx][y]!='.') {
                    if (!vis[xx][y]) {
                        vis[xx][y] = 1;
                        q[fn++] = xx*m + y;
                    }
                }
            }
        }
        if (vis[coinRow-1][coinColumn-1]) break;
	}
	return k;
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
		cout << "Testing ArcadeManao (256.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381081520;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ArcadeManao _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string level[] = {"XXXX....",
				                  "...X.XXX",
				                  "XXX..X..",
				                  "......X.",
				                  "XXXXXXXX"};
				int coinRow = 2;
				int coinColumn = 4;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 1:
			{
				string level[] = {"XXXX",
				                  "...X",
				                  "XXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 1;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 2:
			{
				string level[] = {"..X..",
				                  ".X.X.",
				                  "X...X",
				                  ".X.X.",
				                  "..X..",
				                  "XXXXX"};
				int coinRow = 1;
				int coinColumn = 3;
				_expected = 4;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 3:
			{
				string level[] = {"X"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 0;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 4:
			{
				string level[] = {"XXXXXXXXXX",
				                  "...X......",
				                  "XXX.......",
				                  "X.....XXXX",
				                  "..XXXXX..X",
				                  ".........X",
				                  ".........X",
				                  "XXXXXXXXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			/*case 5:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 6:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 7:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
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
