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


class SumOfSelectedCells {
	public:
	string hypothesis(vector <string> table) ;
};

int dp[1<<20];
int a[20][20];
int b[20][20];
int n;
int m;
bool bad;

int solve(int mask) {
    if (bad) return 0;
    if (mask==0) return 0;
    if (dp[mask]>=0) return dp[mask];

    int k = m - __builtin_popcount(mask);
    if (k>=n) return 0;
    int t = -1;

    for (int i=0; i<m; i++) if ((1<<i)&mask) {
        int tmp = a[k][i] + solve(mask-(1<<i));
        if (bad) return 0;
        if (t==-1) t = tmp;
        else {
            if (t!=tmp) {
                bad = 1;
                return 0;
            }
        }
    }

    dp[mask] = t;
    return t;

}

string SumOfSelectedCells::hypothesis(vector <string> table) {
    n = table.size();
    for (int i=0; i<n; i++) {
        m = 0;
        string s = table[i];
        stringstream ss(s);
        while (ss>>s) a[i][m++] = atoi(s.c_str());
    }
    for (int i=0; i<(1<<m); i++) dp[i] = -1;
    solve((1<<m)-1);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) b[j][i] = a[i][j];
    for (int i=0; i<m; i++) for (int j=0; j<n; j++) a[i][j] = b[i][j];
    swap(n,m);
    for (int i=0; i<(1<<m); i++) dp[i] = -1;
    solve((1<<m)-1);
    if (bad) return "INCORRECT";
    else return "CORRECT";
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
		cout << "Testing SumOfSelectedCells (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393760832;
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
		SumOfSelectedCells _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"16", "18"};
				_expected = "INCORRECT";
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"11 12 13 14",
				                  "21 22 23 24",
				                  "31 32 33 34",
				                  "41 42 43 44"};
				_expected = "CORRECT";
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"3 7",
				                  "3 7",
				                  "3 7"};
				_expected = "CORRECT";
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"1 2 3",
				                  "4 5 6",
				                  "9 8 7"};
				_expected = "INCORRECT";
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 4:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.hypothesis(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
