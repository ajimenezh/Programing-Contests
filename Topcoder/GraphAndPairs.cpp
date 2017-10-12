
#line 3 "GraphAndPairs.cpp"
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

vector<pair<int,int> > e;
int n;

void build(int m, int d) {

    int l = n + 2*m;
    int r = l + (d-2);

    for (int i=l+1; i<=r; i++) e.push_back(make_pair(i-1, i));

    for (int i=0; i<m; i++) e.push_back(make_pair(n+i, l));
    for (int i=0; i<m; i++) e.push_back(make_pair(n+m+i, r));

    n += 2*m + (r-l+1);

}

class GraphAndPairs {
	public:
	vector <int> construct(int d, int k) {

		int p = 500;

		n = 0;

		if (d == 2) {

            while (k > 0) {

                while (p*(2*p-1) > k) p--;

                build(p, d);

                k -= p*(2*p-1);

            }
		}
		else {

            while (k > 0) {

                while (p*p > k) p--;

                build(p, d);

                k -= p*p;

            }
		}

        vector<int> v;
        v.push_back(n);
        for (int i=0; i<e.size(); i++) {
            v.push_back(e[i].first);
             v.push_back(e[i].second);
        }


		return v;
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
		cout << "Testing GraphAndPairs (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507829074;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GraphAndPairs _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d = 2;
				int k = 1;
				int __expected[] = {4, 0, 1, 1, 3, 3, 2, 2, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 1:
			{
				int d = 2;
				int k = 2;
				int __expected[] = {8, 0, 1, 1, 3, 3, 2, 2, 0, 1, 2, 4, 5, 5, 7, 7, 6, 6, 4, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 2:
			{
				int d = 4;
				int k = 4;
				int __expected[] = {8, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 3:
			{
				int d = 5;
				int k = 2;
				int __expected[] = {10, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 9, 0, 5, 1, 6, 2, 7, 3, 8, 4, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			/*case 4:
			{
				int d = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}*/
			/*case 5:
			{
				int d = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}*/
			/*case 6:
			{
				int d = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
