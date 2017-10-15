
#line 3 "AverageVarianceSubtree.cpp"
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

class AverageVarianceSubtree {
	public:
	double average(vector <int> p, vector <int> weight) {
		
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
		cout << "Testing AverageVarianceSubtree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508078909;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AverageVarianceSubtree _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1};
				int weight[] = {10,20,30};
				_expected = 19.444444444444443;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1,1};
				int weight[] = {10,20,7,6};
				_expected = 23.0145202020202;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0};
				int weight[] = {1,1000000000};
				_expected = 8.3333333166666672E16;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,0,1,0,2,3,3,6};
				int weight[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
				_expected = 4.432586365551198E14;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {};
				int weight[] = {712};
				_expected = 0.0;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 5:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
