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


class BoxesArrangement {
	public:
	int maxUntouched(string boxes) ;
};

int dp[50][51][51][3][3];
int cnt[3];
int n;
string s;

int solve(int i, int c1, int c2, int k1, int k2) {
    int c3 = i - c1 - c2;
    if (c1>cnt[0] || c2>cnt[1] || c3>cnt[2]) return 10000;
    if (i==n) return 0;
    if (dp[i][c1][c2][k1][k2]>=0) return dp[i][c1][c2][k1][k2];

    int tmp = 10000;
    if (k1==k2) {
        for (int j=0; j<3; j++) if (j!=k1) {
            int tot = 0;
            if (j!=s[i]-'A') tot++;
            tmp = min(tmp, tot + solve(i+1, c1+(j==0), c2+(j==1), k2, j));
        }
    }
    else {
        for (int j=0; j<3; j++) {
            int tot = 0;
            if (j!=s[i]-'A') tot++;
            tmp = min(tmp, tot + solve(i+1, c1+(j==0), c2+(j==1), k2, j));
        }
    }

    dp[i][c1][c2][k1][k2] = tmp;

    return tmp;
}

int BoxesArrangement::maxUntouched(string boxes) {
	s = boxes;
	n = boxes.length();
	for (int i=0; i<n; i++) cnt[s[i]-'A']++;
	if (n<3) {
        return n;
	}
	for (int i=0; i<n; i++) for (int j=0; j<=n; j++) for (int k=0; k<=n; k++) {
        for (int p=0; p<3; p++) {
            for (int q=0; q<3; q++) dp[i][j][k][p][q] = -1;
        }
	}
	int res = 10000;
	for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
        int tot = 0;
        if (i!=s[0]-'A') tot++;
        if (j!=s[1]-'A') tot++;
        res = min(res, solve(2,(i==0)+(j==0), (i==1)+(j==1),i,j)+tot);
	}
	if (res>n) return -1;
	return n-res;
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
		cout << "Testing BoxesArrangement (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393528409;
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
		BoxesArrangement _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string boxes = "AAABBBCCC";
				_expected = 6;
				_received = _obj.maxUntouched(boxes); break;
			}
			case 1:
			{
				string boxes = "AAAAAAAACBB";
				_expected = 7;
				_received = _obj.maxUntouched(boxes); break;
			}
			case 2:
			{
				string boxes = "CCCCCB";
				_expected = -1;
				_received = _obj.maxUntouched(boxes); break;
			}
			case 3:
			{
				string boxes = "BAACAABAACAAA";
				_expected = 5;
				_received = _obj.maxUntouched(boxes); break;
			}
			case 4:
			{
				string boxes = "CBBABA";
				_expected = 6;
				_received = _obj.maxUntouched(boxes); break;
			}
			/*case 5:
			{
				string boxes = ;
				_expected = ;
				_received = _obj.maxUntouched(boxes); break;
			}*/
			/*case 6:
			{
				string boxes = ;
				_expected = ;
				_received = _obj.maxUntouched(boxes); break;
			}*/
			/*case 7:
			{
				string boxes = ;
				_expected = ;
				_received = _obj.maxUntouched(boxes); break;
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
