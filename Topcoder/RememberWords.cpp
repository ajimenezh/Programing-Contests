
#line 3 "RememberWords.cpp"
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

class RememberWords {
	public:
	string isPossible(int d1, int d2, int w1, int w2) {
		
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
		cout << "Testing RememberWords (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507828647;
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
		RememberWords _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d1 = 2;
				int d2 = 3;
				int w1 = 7;
				int w2 = 18;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 1:
			{
				int d1 = 1;
				int d2 = 1;
				int w1 = 3;
				int w2 = 5;
				_expected = "Impossible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 2:
			{
				int d1 = 3;
				int d2 = 5;
				int w1 = 300;
				int w2 = 500;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 3:
			{
				int d1 = 100;
				int d2 = 1;
				int w1 = 0;
				int w2 = 2;
				_expected = "Impossible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 4:
			{
				int d1 = 1000000000;
				int d2 = 1000000000;
				int w1 = 1000000000;
				int w2 = 1000000000;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			/*case 5:
			{
				int d1 = ;
				int d2 = ;
				int w1 = ;
				int w2 = ;
				_expected = ;
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}*/
			/*case 6:
			{
				int d1 = ;
				int d2 = ;
				int w1 = ;
				int w2 = ;
				_expected = ;
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}*/
			/*case 7:
			{
				int d1 = ;
				int d2 = ;
				int w1 = ;
				int w2 = ;
				_expected = ;
				_received = _obj.isPossible(d1, d2, w1, w2); break;
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

// END CUT HERE
