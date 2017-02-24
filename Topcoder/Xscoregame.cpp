
#line 3 "Xscoregame.cpp"
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

int dp[1<<15][64];

class Xscoregame {
	public:

    int n;
	vector<int> v;
	int ret;

	int getscore(vector <int> A) {
		v = A;
		n = v.size();
		for (int i=0; i<(1<<n); i++) for (int j=0; j<64; j++) {
            dp[i][j] = -1;
		}
        ret = 0;

		dp[0][0] = 0;
		for (int i=0; i<(1<<n); i++) {
            for (int j=0; j<64; j++) if (dp[i][j] >= 0) {
                ret = max(ret, dp[i][j]);
                for (int k=0; k<n; k++) if ((i & (1<<k))==0) {
                    int x = (dp[i][j]^v[k]) + dp[i][j];
                    dp[i^(1<<k)][x&63] = max(dp[i^(1<<k)][x&63], x);
                }
            }
		}

		return ret;
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
		cout << "Testing Xscoregame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487961915;
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
		Xscoregame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3};
				_expected = 12;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {10,0,0,0};
				_expected = 80;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,0,1,0,1,0,1,0};
				_expected = 170;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
				_expected = 830122;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {18,48,39,16,30,32};
				_expected = 1898;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 6:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
