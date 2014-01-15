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


class TheNumberGameDivOne {
	public:
	string find(long long n) ;
};

string TheNumberGameDivOne::find(long long n) {
	int cnt = 0;
	long long tmp = n;
	if (n==1) return "Brus";
	while (n%2==0) {
        n /= 2;
        cnt++;
	}
	if (n==1) {
        if (cnt%2==0) return "John";
        else return "Brus";
	}
	if (tmp%2==0) return "John";
	return "Brus";
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
		cout << "Testing TheNumberGameDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381261307;
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
		TheNumberGameDivOne _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 6LL;
				_expected = "John";
				_received = _obj.find(n); break;
			}
			case 1:
			{
				long long n = 2LL;
				_expected = "Brus";
				_received = _obj.find(n); break;
			}
			case 2:
			{
				long long n = 747LL;
				_expected = "Brus";
				_received = _obj.find(n); break;
			}
			case 3:
			{
				long long n = 128LL;
				_expected = "Brus";
				_received = _obj.find(n); break;
			}
			/*case 4:
			{
				long long n = LL;
				_expected = ;
				_received = _obj.find(n); break;
			}*/
			/*case 5:
			{
				long long n = LL;
				_expected = ;
				_received = _obj.find(n); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				_expected = ;
				_received = _obj.find(n); break;
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
