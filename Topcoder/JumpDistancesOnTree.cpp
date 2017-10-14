
#line 3 "JumpDistancesOnTree.cpp"
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

class JumpDistancesOnTree {
	public:
	string isPossible(vector <int> p, vector <int> S) {
		
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
		cout << "Testing JumpDistancesOnTree (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507988321;
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
		JumpDistancesOnTree _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,1,0,4,4};
				int S[] = {2,4};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1,1,0,4,4};
				int S[] = {1,2,3,4,5};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0,1,1,0,4,4};
				int S[] = {3,4};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,1,2,3,4,0,6,7,8,9};
				int S[] = {2,4,6,8,10};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {0};
				int S[] = {1};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			/*case 5:
			{
				int p[] = ;
				int S[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int S[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int S[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
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
