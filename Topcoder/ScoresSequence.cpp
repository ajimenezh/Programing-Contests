
#line 3 "ScoresSequence.cpp"
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

int g[110][110];
int cnt[110];

class ScoresSequence {
	public:
	int count(vector <int> s) {

	    sort(s.begin(), s.end());
	    reverse(s.begin(), s.end());

		int n = s.size();
		for (int i=0; i<n; i++) cnt[i] = n-1-s[i];

		for (int i=0; i<n; i++) {

            while (s[i]--) {
                int k = -1;
                for (int j=0; j<n; j++) if (i != j) {

                    if (cnt[j] > 0 && g[i][j] == 0 && (k==-1 || cnt[k] <= cnt[j])) {
                        k = j;
                    }

                }

                if (k != -1) {
                        g[i][k] = 1;
                        cnt[k]--;
                }
            }

		}

		for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            g[i][j] |= (g[i][k] & g[k][j]);
		}

		int res = 0;

		for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (i != j) {
            res += g[i][j];
		}

		res += n;

		return res;

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
		cout << "Testing ScoresSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507968741;
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
		ScoresSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s[] = {2, 0, 1};
				_expected = 6;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 1:
			{
				int s[] = {1, 0, 2};
				_expected = 6;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 2:
			{
				int s[] = {1, 1, 1};
				_expected = 9;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 3:
			{
				int s[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6};
				_expected = 55;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 4:
			{
				int s[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
				_expected = 1422;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			/*case 5:
			{
				int s[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int s[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int s[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
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
