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


class ProblemsToSolve {
	public:
	int minNumber(vector <int> pleasantness, int variety) ;
};

bool vis[50][50][52][52];
int n;
vector<int> v;
int m;
int ans;

void dfs(int i, int k, int t1, int t2) {
    if (t1!=0 && t2!=0) {
        if (v[t1-1]-v[t2-1]>=m) {
            ans = min(ans, k);
            return;
        }
    }
    if (i>=n) return;
    if (k>=ans) return;
    if (vis[i][k][t1][t2]) return;

    if (!t1) {
        if (!t2) {
            dfs(i+1, k+1, i+1, 0);
            dfs(i+2, k+1, i+1, 0);
        }
        else {
            if (v[i]>v[t2-1]) {
                dfs(i+1, k+1, i+1, t2);
                dfs(i+2, k+1, i+1, t2);
            }
            else {
                dfs(i+1, k+1, t2, i+1);
                dfs(i+2, k+1, t2, i+1);
            }
        }
    }
    else {
        if (!t2) {
            if (v[i]>v[t1-1]) {
                dfs(i+1, k+1, i+1, t1);
                dfs(i+2, k+1, i+1, t1);
            }
            else {
                dfs(i+1, k+1, t1, i+1);
                dfs(i+2, k+1, t1, i+1);
            }
        }
        else {
            if (v[i]>v[t1-1]) {
                dfs(i+1, k+1, i+1, t2);
                dfs(i+2, k+1, i+1, t2);
            }
            else if (v[i]<v[t2-1]) {
                dfs(i+1, k+1, t1, i+1);
                dfs(i+2, k+1, t1, i+1);
            }
            else {
                dfs(i+1, k+1, t1, t2);
                dfs(i+2, k+1, t1, t2);
            }
        }
    }
    vis[i][k][t1][t2] = 1;
    return;
}

int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
	v = pleasantness;
	n = v.size();
	m = variety;
	ans = n;
	dfs(0,0,0,0);
	return ans;
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
		cout << "Testing ProblemsToSolve (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389008599;
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
		ProblemsToSolve _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int pleasantness[] = {1, 2, 3};
				int variety = 2;
				_expected = 2;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}
			case 1:
			{
				int pleasantness[] = {1, 2, 3, 4, 5};
				int variety = 4;
				_expected = 3;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}
			case 2:
			{
				int pleasantness[] = {10, 1, 12, 101};
				int variety = 100;
				_expected = 3;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}
			case 3:
			{
				int pleasantness[] = {10, 1};
				int variety = 9;
				_expected = 2;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}
			case 4:
			{
				int pleasantness[] = {6, 2, 6, 2, 6, 3, 3, 3, 7};
				int variety = 4;
				_expected = 2;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}
			case 5:
			{
				int pleasantness[] = {12,13,6,1,5,12,11,5,13,3,1,14,11,9,1};
				int variety = 13;
				_expected = 7;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}
			/*case 6:
			{
				int pleasantness[] = ;
				int variety = ;
				_expected = ;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
			}*/
			/*case 7:
			{
				int pleasantness[] = ;
				int variety = ;
				_expected = ;
				_received = _obj.minNumber(vector <int>(pleasantness, pleasantness+sizeof(pleasantness)/sizeof(int)), variety); break;
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
