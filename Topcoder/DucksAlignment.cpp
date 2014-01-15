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


class DucksAlignment {
	public:
	int minimumTime(vector <string> grid) ;
};

int cnt[55], cnt2[55];
int n,m;

int calc(int x, int a, int b) {
    int k=a;
    int tot = 0;
    for (int i=0; i<x; i++) cnt2[i] = cnt[i];
    for (int i=0; i<x; i++) {
        while (cnt2[i]>0) {
            tot += abs(i-k);
            k++;
            cnt2[i]--;
        }
    }

    return tot;
}

int DucksAlignment::minimumTime(vector <string> grid) {
	int n = grid.size();
	int m = grid[0].length();
	int res = 10000000;
	int all = 0;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (grid[i][j]=='o') all++;
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cnt[j] = 0;
        int ans = 0;
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) if (grid[j][k]=='o') {
                cnt[k]++;
                ans += abs(j-i);
            }
        }
        for (int j=0; j<m-all+1; j++) {
            int tmp = ans + calc(m,j,j+all);
            res = min(res, tmp);
        }
	}

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) cnt[j] = 0;
        int ans = 0;
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) if (grid[j][k]=='o') {
                cnt[j]++;
                ans += abs(k-i);
            }
        }
        for (int j=0; j<n-all+1; j++) {
            int tmp = ans + calc(n,j,j+all);
            res = min(res, tmp);
        }
	}

	return res;
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
		cout << "Testing DucksAlignment (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384780932;
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
		DucksAlignment _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {".o",
				                 "o."};
				_expected = 1;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {".o...",
				                 "..o..",
				                 "....o"};
				_expected = 3;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"o..........",
				                 "..o........",
				                 ".......o...",
				                 "...........",
				                 "...........",
				                 "...........",
				                 "........o..",
				                 "..........."};
				_expected = 16;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {".........",
				                 "....o....",
				                 "........."};
				_expected = 0;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"...o..........................",
				                 "............................o.",
				                 ".o............................",
				                 "............o.................",
				                 ".................o............",
				                 "......................o.......",
				                 "......o.......................",
				                 "....o.........................",
				                 "...............o..............",
				                 ".......................o......",
				                 "...........................o..",
				                 ".......o......................"};
				_expected = 99;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 5:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
