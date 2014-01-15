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


class Multifactorial {
	public:
	string calcMultiFact(int n, int k) ;
};

string Multifactorial::calcMultiFact(int n, int k) {
	long long res = 1;
	for (int i=n; i>=1; i-=k) {
        if (res>1000000000000000000LL/i) {
            return "overflow";
        }
        res *= i;
	}
	stringstream ss;
	ss<<res;
	return ss.str();
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
		cout << "Testing Multifactorial (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388521200;
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
		Multifactorial _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 14;
				int k = 3;
				_expected = "12320";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 1:
			{
				int n = 5;
				int k = 4;
				_expected = "5";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 2:
			{
				int n = 1000;
				int k = 2;
				_expected = "overflow";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 3:
			{
				int n = 2000000000;
				int k = 1900000000;
				_expected = "200000000000000000";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 4:
			{
				int n = 1000;
				int k = 256;
				_expected = "84232704000";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 5:
			{
				int n = 2000000000;
				int k = 1;
				_expected = "overflow";
				_received = _obj.calcMultiFact(n, k); break;
			}
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.calcMultiFact(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.calcMultiFact(n, k); break;
			}*/
			/*case 8:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.calcMultiFact(n, k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
