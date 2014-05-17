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


class CommonMultiples {
	public:
	int countCommMult(vector <int> a, int lower, int upper) ;
};

long long gcd(long long a, long long b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
    long long g = gcd(a,b);
    return (a/g)*b;
}

int CommonMultiples::countCommMult(vector <int> a, int lower, int upper) {
    long long k = a[0];
    for (int i=1; i<a.size(); i++) {
        if (k>upper) break;
        k = lcm(k, (long long)a[i]);
    }

    return upper/k - (lower-1)/k;
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
		cout << "Testing CommonMultiples (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391087876;
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
		CommonMultiples _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,2,3};
				int lower = 5;
				int upper = 15;
				_expected = 2;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
			}
			case 1:
			{
				int a[] = {1,2,4,8,16,32,64};
				int lower = 128;
				int upper = 128;
				_expected = 1;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
			}
			case 2:
			{
				int a[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49};
				int lower = 1;
				int upper = 2000000000;
				_expected = 0;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
			}
			case 3:
			{
				int a[] = {1,1,1};
				int lower = 1;
				int upper = 2000000000;
				_expected = 2000000000;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
			}
			/*case 4:
			{
				int a[] = ;
				int lower = ;
				int upper = ;
				_expected = ;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
			}*/
			/*case 5:
			{
				int a[] = ;
				int lower = ;
				int upper = ;
				_expected = ;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int lower = ;
				int upper = ;
				_expected = ;
				_received = _obj.countCommMult(vector <int>(a, a+sizeof(a)/sizeof(int)), lower, upper); break;
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
