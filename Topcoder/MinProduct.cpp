
#line 3 "MinProduct.cpp"
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

long long pw[10];
set<pair<int, pair<pair<int,int>, pair<long long, long long> > > > vis;

void rec(vector <int> & amount, int idx, int n, int m, long long a, long long b, long long & res) {

    //cout<<idx<<" "<<n<<" "<<m<<" "<<a<<" "<<b<<endl;

    if (n == 0 && m == 0) {
        res = min(res, a*b);
        return;
    }
    if (idx == amount.size()) return;

    if (a*b > res) return;

    //if (vis.find(make_pair(idx, make_pair(make_pair(n, m), make_pair(a, b)))) != vis.end()) {
    //    return;
    //}

    //vis.insert(make_pair(idx, make_pair(make_pair(n, m), make_pair(a, b))));

    //cout<<vis.size()<<endl;

    long long aa = a;

    for (int i=0; i<=amount[idx] && i<=n; i++) {

        if (i!=0)
            aa += idx*pw[n-i];

        long long bb = b;

        for (int j=0; j+i<=amount[idx] && j<=m; j++) {

                if (j!=0)
                    bb += idx*pw[m-j];

            if (amount[idx] == i+j || (i==n && j==m)) {

                rec(amount, idx+1, n-i, m-j, aa, bb, res);
            }

        }
    }
}

class MinProduct {
	public:
	long long findMin(vector <int> amount, int blank1, int blank2) {

		long long res = 1LL<<61;
		long long a = 0, b = 0;

		pw[0] = 1;
		for (int i=1; i<10; i++) pw[i] = 10*pw[i-1];


		rec(amount, 0, blank1, blank2, a, b, res);

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
		cout << "Testing MinProduct (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507833436;
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
		MinProduct _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int amount[] = {0,1,1,2,1,1,0,0,0,0};
				int blank1 = 2;
				int blank2 = 3;
				_expected = 3042LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 1:
			{
				int amount[] = {1,1,1,1,1,1,1,1,1,1};
				int blank1 = 1;
				int blank2 = 8;
				_expected = 0LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 2:
			{
				int amount[] = {1,3,0,0,0,0,0,0,0,0};
				int blank1 = 2;
				int blank2 = 2;
				_expected = 11LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 3:
			{
				int amount[] = {0,20,20,20,20,20,20,20,20,20};
				int blank1 = 9;
				int blank2 = 9;
				_expected = 12345678987654321LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 4:
			{
				int amount[] = {1,0,0,0,1,0,0,5,3,2};
				int blank1 = 9;
				int blank2 = 3;
				_expected = 36556078253LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 5:
			{
				int amount[] = {0,0,0,0,0,0,0,0,0,18};
				int blank1 = 9;
				int blank2 = 8;
				_expected = 99999998900000001LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			/*case 6:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			/*case 7:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			/*case 8:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = LL;
				_received = _obj.findMin(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
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
