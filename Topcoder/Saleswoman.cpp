
#line 3 "Saleswoman.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

vector<int> pos, neg;
vector<int> p, delta;
vector<int> sum[2];
int n;
int dp[310][310][2];

int solve(int i, int j, int last) {

    if (i == pos.size()-1) {
        return abs(p[pos[i]] - p.back());
    }

    if (dp[i][j][last] != -1) return dp[i][j][last];

    int tmp = 1000000000;

    if (last == 0) {

        if (sum[0][i+1] <= -sum[1][j]) {
            tmp = min(tmp, solve(i+1, j, 0) + abs(p[pos[i+1]] - p[pos[i]]));
        }
        if (j+1<neg.size())
            tmp = min(tmp, solve(i, j+1, 1) + abs(p[neg[j+1]] - p[pos[i]]));

    }
    else {
        if (sum[0][i+1] <= -sum[1][j]) {
            tmp = min(tmp, solve(i+1, j, 0) + abs(p[pos[i+1]] - p[neg[j]]));
        }
        if (j+1<neg.size())
            tmp = min(tmp, solve(i, j+1, 1) + abs(p[neg[j+1]] - p[neg[j]]));
    }

    //cout<<i<<" "<<j<<" "<<last<<" "<<tmp<<endl;

    dp[i][j][last] = tmp;

    return tmp;
}

class Saleswoman {
	public:
	int minMoves(vector <int> _p, vector <int> _delta) {

		p = _p;
		delta = _delta;
		for (int i=0; i<delta.size(); i++){
            if (delta[i] < 0) pos.push_back(i);
            else neg.push_back(i);
		}

		sum[0].push_back(0);
		sum[1].push_back(0);

		for (int i=0; i<pos.size(); i++) sum[0].push_back(sum[0].back() - delta[pos[i]]);
		for (int i=0; i<neg.size(); i++) sum[1].push_back(sum[1].back() - delta[neg[i]]);

		pos.insert(pos.begin(), 0);
		neg.insert(neg.begin(), 0);

		n = p.size();

		//cout<<" "<<pos.size()<<" "<<neg.size()<<endl;

		for (int i=0; i<=n+1; i++) for (int j=0; j<=n+1; j++) for (int k=0; k<2; k++) dp[i][j][k] = -1;

		return solve(0, 0, delta[0]>0) + abs(p[0]);
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
		cout << "Testing Saleswoman (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508013476;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Saleswoman _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int pos[] = {3,14,15,92,101};
				int delta[] = {-3,2,3,-3,1};
				_expected = 143;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}
			case 1:
			{
				int pos[] = {1,2,4,8,16,32,64,128};
				int delta[] = {-1,-1,-1,-1,1,1,1,1};
				_expected = 382;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}
			case 2:
			{
				int pos[] = {100000};
				int delta[] = {0};
				_expected = 100000;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}
			case 3:
			{
				int pos[] = {100,200,300,400};
				int delta[] = {10,-3,-5,2};
				_expected = 400;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}
			case 4:
			{
				int pos[] = {1,2,3,5,8,13,21,34,55,89};
				int delta[] = {-1,1,-1,1,-1,1,-1,1,-1,1};
				_expected = 199;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}
			case 5:
			{
				int pos[] = {1,2,3,6,10,15,21,28,36,45,55};
				int delta[] = {-3,-5,10,-2,-6,-7,3,-2,8,5,-1};
				_expected = 129;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}
			/*case 6:
			{
				int pos[] = ;
				int delta[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int pos[] = ;
				int delta[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int pos[] = ;
				int delta[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <int>(pos, pos+sizeof(pos)/sizeof(int)), vector <int>(delta, delta+sizeof(delta)/sizeof(int))); break;
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
