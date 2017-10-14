
#line 3 "OwaskiAndTree.cpp"
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

vector<int> e[1010];
int x[1010];
int n;
int d[1010];

int dfs(int p) {

    int m = 0;

    for (int i=0; i<e[p].size(); i++) {

        m += dfs(e[p][i]);

        d[p] += d[e[p][i]];

    }

    d[p] += x[p];
    d[p] = max(d[p], 0);

    return max(d[p], m);
}

class OwaskiAndTree {
	public:
	int maximalScore(vector <int> parent, vector <int> pleasure) {

		n = parent.size()+1;
		for (int i=0; i<parent.size(); i++) {
            e[parent[i]].push_back(i+1);
		}
		for (int i=0; i<n; i++) {
            x[i] = pleasure[i];
		}

		int res = dfs(0);

		return max(res, 0);
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
		cout << "Testing OwaskiAndTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507910892;
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
		OwaskiAndTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
				int pleasure[] = {1, 1, -1, -1, -1, -1, 1, 1, 1, 1};
				_expected = 4;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {0, 0, 1, 2};
				int pleasure[] = {2, 3, 4, -1, -1};
				_expected = 9;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0, 1, 1, 2, 2, 5, 5};
				int pleasure[] = {1, 2, -3, -7, 3, 2, 7, -1, 3};
				_expected = 17;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 1, 1, 1, 0, 3, 1, 3, 4, 4, 3, 6, 8, 0, 12, 12, 11, 7, 7};
				int pleasure[] = {-154011, 249645, 387572, 292156, -798388, 560085, -261135, -812756, 191481, -165204, 81513, -448791, 608073, 354614, -455750, 325999, 227225, -696501, 904692, -297238};
				_expected = 3672275;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {};
				int pleasure[] = {-1};
				_expected = 0;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int pleasure[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int pleasure[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int pleasure[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
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