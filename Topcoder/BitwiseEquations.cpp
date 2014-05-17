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


class BitwiseEquations {
	public:
	long long kthPlusOrSolution(int x, int k) ;
};

vector<int> v;

long long BitwiseEquations::kthPlusOrSolution(int x, int k) {
    while (k) {
        v.push_back(k%2);
        k >>= 1;
    }
    long long t = 0;
    int i = 0;
    long long h = 1;
    while (x && i<v.size()) {
        if (x%2==0) t += v[i++]*h;
        x /= 2;
        h *= 2LL;
    }
    for (;i<v.size(); i++) {
        t += v[i]*h;
        h *= 2LL;
    }
    return t;
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
		cout << "Testing BitwiseEquations (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396870617;
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
		BitwiseEquations _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 5;
				int k = 1;
				_expected = 2LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 1:
			{
				int x = 5;
				int k = 5;
				_expected = 18LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 2:
			{
				int x = 10;
				int k = 3;
				_expected = 5LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 3:
			{
				int x = 2000000;
				int k = 1000000000;
				_expected = 2000000000LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			/*case 4:
			{
				int x = ;
				int k = ;
				_expected = LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}*/
			/*case 5:
			{
				int x = ;
				int k = ;
				_expected = LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}*/
			/*case 6:
			{
				int x = ;
				int k = ;
				_expected = LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
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
