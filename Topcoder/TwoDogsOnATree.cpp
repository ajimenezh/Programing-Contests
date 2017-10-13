
#line 3 "TwoDogsOnATree.cpp"
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

int _xor[1010];
vector<int> e[1010];
vector<int> w[1010];
bool exist[1025];

void dfs(int p) {
    for (int i=0; i<e[p].size(); i++) {
        _xor[e[p][i]] = _xor[p]^w[p][i];
        dfs(e[p][i]);
    }

}

class TwoDogsOnATree {
	public:
	int maximalXorSum(vector <int> parent, vector <int> _w) {

		for (int i=0; i<parent.size(); i++) {
            e[parent[i]].push_back(i+1);
            w[parent[i]].push_back(_w[i]);
		}

		dfs(0);

		int n = parent.size()+1;

		for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) exist[_xor[i]^_xor[j]] = true;
		}

		int res = 0;

		for (int i=0; i<1024; i++) {
            for (int j=0; j<1024; j++) if (exist[i] && exist[j]) {
                res = max(res, i^j);
            }
		}

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
		cout << "Testing TwoDogsOnATree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507904183;
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
		TwoDogsOnATree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0, 0, 0, 0};
				int w[] = {1, 2, 4, 8};
				_expected = 15;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
				int w[] = {3, 2, 6, 5, 8, 1, 3, 4, 3};
				_expected = 15;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0, 2, 2, 4, 4, 5, 6};
				int w[] = {13, 16, 12, 11, 3, 1, 4, 2};
				_expected = 31;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 0, 2, 0, 1, 2, 2, 4, 6, 1, 5};
				int w[] = {628, 589, 815, 864, 459, 507, 733, 239, 904, 592, 818};
				_expected = 1017;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {};
				int w[] = {};
				_expected = 0;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int w[] = ;
				_expected = ;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int w[] = ;
				_expected = ;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int w[] = ;
				_expected = ;
				_received = _obj.maximalXorSum(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
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
