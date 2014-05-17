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


class LostParentheses {
	public:
	int minResult(string e) ;
};

vector<int> a;
vector<int> next;
int dp[55][2];
bool vis[55][2];
int n;

int solve(int i, int m) {
    if (i==n-1) return a[i];
    if (vis[i][m]) return dp[i][m];

    int tmp;
    if (m==0) {
        tmp = 100000000;

    }
}

int LostParentheses::minResult(string e) {
    for (int i=0; i<e.length(); i++) {
        if (e[i]=='+') next.push_back(1);
        if (e[i]=='-') next.push_back(-1);
    }
    for (int i=0; i<e.length(); i++) if (e[i]=='+' || e[i]=='-') e[i]=' ';
    stringstream ss(e);
    string s;
    while (ss>>s) a.push_back(atoi(s.c_str()));

    int res = a[0];
    int sum = 0;
    for (int i=0; i<a.size(); i++) sum += a[i];

    int i = 0;
    while (i<next.size() && next[i]==1) {
        res += a[i+1];
        i++;
    }

    res = res - (sum-res);

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
		cout << "Testing LostParentheses (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392123370;
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
		LostParentheses _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string e = "55-50+40";
				_expected = -35;
				_received = _obj.minResult(e); break;
			}
			case 1:
			{
				string e = "10+20+30+40";
				_expected = 100;
				_received = _obj.minResult(e); break;
			}
			case 2:
			{
				string e = "00009-00009";
				_expected = 0;
				_received = _obj.minResult(e); break;
			}
			case 3:
			{
				string e = "62027+93403-16025+47588-94607+16226-24573";
				_expected = -43589;
				_received = _obj.minResult(e); break;
			}
			/*case 4:
			{
				string e = ;
				_expected = ;
				_received = _obj.minResult(e); break;
			}*/
			/*case 5:
			{
				string e = ;
				_expected = ;
				_received = _obj.minResult(e); break;
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
