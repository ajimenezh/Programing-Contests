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


class BikeLock {
	public:
	int minTurns(string current, string desired) ;
};

int dp[55][10][10];
int n;
vector<int> v, w;

int solve(int i, int p1, int p2) {
    if (i==n+1) {
        return (p2!=w[n-1]);
    }
    if (i==n) {
        if (p2==w[n-2]) return solve(i+1,-1,p1);
        else {
            if (w[n-2]>p2) {
                int tmp =  1 + min(solve(i+1, -1, ((p1 + (w[n-2]-p2))%10)%10), solve(i+1, -1, (p1 - (p2+(10-w[n-2])+10)%10 + 10)%10));
                tmp = min(tmp, 1 + solve(i+1,-1,p1));
            }
            else {
                int tmp =  1 + min(solve(i+1, -1, ((p1 - (p2-w[n-2]))%10 + 10)%10), solve(i+1, -1, (p1 + (w[n-2]+(10-p2)+10)%10 + 10)%10));
                tmp = min(tmp, 1 + solve(i+1,-1,p1));
                return tmp;
            }
        }
    }
    if (dp[i][p1][p2]>=0) return dp[i][p1][p2];

    int tmp = 10000;

    if (p2==w[i-2]) tmp = solve(i+1,v[i],p1);
    else {
        if (w[i-2]>p2) {
            tmp =  1 + min(solve(i+1, v[i], ((p1 + (w[i-2]-p2))%10)%10), solve(i+1, v[i], (p1 - (p2+(10-w[i-2])+10)%10 + 10)%10));
            tmp =  min(tmp, 1 + min(solve(i+1, ((v[i] + (w[i-2]-p2))%10)%10, ((p1 + (w[i-2]-p2))%10)%10), solve(i+1, (v[i] - (p2+(10-w[i-2])+10)%10 + 10)%10, (p1 - (p2+(10-w[i-2])+10)%10 + 10)%10)));
            tmp =  min(tmp, 1 + min(solve(i+1, ((v[i] + (w[i-2]-p2))%10)%10, p1), solve(i+1, (v[i] - (p2+(10-w[i-2])+10)%10 + 10)%10,p1)));
            tmp = min(tmp, 1 + solve(i+1,v[i],p1));
        }
        else {
            tmp =  1 + min(solve(i+1, v[i], ((p1 - (p2-w[i-2]))%10 + 10)%10), solve(i+1, v[i], (p1 + (w[i-2]+(10-p2)+10)%10 + 10)%10));
            tmp =  min(tmp, 1 + min(solve(i+1, ((v[i]- (p2-w[i-2]))%10 + 10)%10, ((p1 - (p2-w[i-2]))%10 + 10)%10), solve(i+1,  (v[i] + (w[i-2]+(10-p2)+10)%10 + 10)%10, (p1 + (w[i-2]+(10-p2)+10)%10 + 10)%10)));
            tmp =  min(tmp, 1 + min(solve(i+1, ((v[i]- (p2-w[i-2]))%10 + 10)%10, p1), solve(i+1,  (v[i] + (w[i-2]+(10-p2)+10)%10 + 10)%10, p1)));
            tmp = min(tmp, 1 + solve(i+1,v[i],p1));
        }
    }
    dp[i][p1][p2] = tmp;

    return tmp;
}

int BikeLock::minTurns(string current, string desired) {
    n = current.length();
    for (int i=0; i<n; i++) v.push_back(current[i]-'0');
    for (int i=0; i<n; i++) w.push_back(desired[i]-'0');

    for (int k=0; k<10; k++) for (int j=0; j<10; j++) for (int i=0; i<n+3; i++) dp[i][j][k] = -1;

    return solve(2,v[1],v[0]);

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
		cout << "Testing BikeLock (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379880600;
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
		BikeLock _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string current = "555";
				string desired = "464";
				_expected = 2;
				_received = _obj.minTurns(current, desired); break;
			}
			case 1:
			{
				string current = "1234";
				string desired = "3456";
				_expected = 2;
				_received = _obj.minTurns(current, desired); break;
			}
			case 2:
			{
				string current = "06012005";
				string desired = "06012005";
				_expected = 0;
				_received = _obj.minTurns(current, desired); break;
			}
			case 3:
			{
				string current = "123456789";
				string desired = "567412490";
				_expected = 5;
				_received = _obj.minTurns(current, desired); break;
			}
			case 4:
			{
				string current = "23887547676234543215443276347856987698648735634265";
				string desired = "14327805497625497814327632146531429785698765309822";
				_expected = 34;
				_received = _obj.minTurns(current, desired); break;
			}
			/*case 5:
			{
				string current = ;
				string desired = ;
				_expected = ;
				_received = _obj.minTurns(current, desired); break;
			}*/
			/*case 6:
			{
				string current = ;
				string desired = ;
				_expected = ;
				_received = _obj.minTurns(current, desired); break;
			}*/
			/*case 7:
			{
				string current = ;
				string desired = ;
				_expected = ;
				_received = _obj.minTurns(current, desired); break;
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
