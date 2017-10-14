
#line 3 "ClassicTowers.cpp"
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

class ClassicTowers {
	public:
	string findTowers(long long k, vector <int> count) {
		
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
		cout << "Testing ClassicTowers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507991995;
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
		ClassicTowers _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long k = 4LL;
				int count[] = {1,1,2};
				_expected = "CCAB";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 1:
			{
				long long k = 0LL;
				int count[] = {0, 0, 50};
				_expected = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 2:
			{
				long long k = 0LL;
				int count[] = {10,20,20};
				_expected = "";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 3:
			{
				long long k = 123456123456123LL;
				int count[] = {10,10,30};
				_expected = "CCACCCACCABACCABBACCCBBCCBCCCBACCCCABBACCCCCACBCCC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 4:
			{
				long long k = 314159265358979LL;
				int count[] = {15,16,17};
				_expected = "";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			/*case 5:
			{
				long long k = LL;
				int count[] = ;
				_expected = ;
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				long long k = LL;
				int count[] = ;
				_expected = ;
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				long long k = LL;
				int count[] = ;
				_expected = ;
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
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
