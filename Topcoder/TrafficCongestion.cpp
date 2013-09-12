#line 2 "TrafficCongestion.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

const long long mod = 1000000007LL;

class TrafficCongestion {
	public:
	long long v;
	long long sum;
	long long p;
	int theMinCars(int treeHeight) {
		int n = treeHeight;
		if (n==0) return 1;
		if (n==1) return 1;
		sum = 1;
		p = 1;
		for (int i=2; i<=n; i++) {
			v = 2LL*sum + 1;
			v %= mod;
			sum += p;
			sum %= mod;
			p = v;
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
		cout << "Testing TrafficCongestion (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375380700;
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
		TrafficCongestion _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int treeHeight = 1;
				_expected = 1;
				_received = _obj.theMinCars(treeHeight); break;
			}
			case 1:
			{
				int treeHeight = 2;
				_expected = 3;
				_received = _obj.theMinCars(treeHeight); break;
			}
			case 2:
			{
				int treeHeight = 3;
				_expected = 5;
				_received = _obj.theMinCars(treeHeight); break;
			}
			case 3:
			{
				int treeHeight = 585858;
				_expected = 548973404;
				_received = _obj.theMinCars(treeHeight); break;
			}
			/*case 4:
			{
				int treeHeight = ;
				_expected = ;
				_received = _obj.theMinCars(treeHeight); break;
			}*/
			/*case 5:
			{
				int treeHeight = ;
				_expected = ;
				_received = _obj.theMinCars(treeHeight); break;
			}*/
			/*case 6:
			{
				int treeHeight = ;
				_expected = ;
				_received = _obj.theMinCars(treeHeight); break;
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
