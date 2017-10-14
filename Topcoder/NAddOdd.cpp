
#line 3 "NAddOdd.cpp"
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
#include<unordered_map>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

unordered_map<long long,long long> mem;

long long f(long long n, long long k) {

    if (n <= k) return 0;
    if (mem.find(n) != mem.end()) return mem[n];

    long long minEven = k+1, minOdd = k+2, maxEven, maxOdd;

    if (n%2==0) {
        maxEven = n;
        maxOdd = n-1;
    }
    else {
        maxEven = n-1;
        maxOdd = n;
    }

    long long sum = 0;

    if (minEven<=maxEven) {
        sum += (maxEven - minEven)/2+1;
        sum += f(maxEven/2, k);
    }
    if (minOdd<=maxOdd) {
        sum += ((maxOdd - minOdd)/2 + 1)*2;
        sum += f((maxOdd+k)/2, k);
    }

    mem[n] = sum;

    return sum;
}

class NAddOdd {
	public:
	long long solve(long long L, long long R, int K) {

        if(R<=K) return 0;
        if(L<=K) L = K+1;

		return f(R, K) - f(L-1, K);

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
		cout << "Testing NAddOdd (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508016134;
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
		NAddOdd _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long L = 5LL;
				long long R = 5LL;
				int K = 1;
				_expected = 5LL;
				_received = _obj.solve(L, R, K); break;
			}
			case 1:
			{
				long long L = 1LL;
				long long R = 99999LL;
				int K = 99999;
				_expected = 0LL;
				_received = _obj.solve(L, R, K); break;
			}
			case 2:
			{
				long long L = 16LL;
				long long R = 17LL;
				int K = 3;
				_expected = 9LL;
				_received = _obj.solve(L, R, K); break;
			}
			case 3:
			{
				long long L = 3LL;
				long long R = 7LL;
				int K = 5;
				_expected = 4LL;
				_received = _obj.solve(L, R, K); break;
			}
			case 4:
			{
				long long L = 1645805087361625LL;
				long long R = 9060129311830846LL;
				int K = 74935;
				_expected = 421014795656548226LL;
				_received = _obj.solve(L, R, K); break;
			}
			/*case 5:
			{
				long long L = LL;
				long long R = LL;
				int K = ;
				_expected = LL;
				_received = _obj.solve(L, R, K); break;
			}*/
			/*case 6:
			{
				long long L = LL;
				long long R = LL;
				int K = ;
				_expected = LL;
				_received = _obj.solve(L, R, K); break;
			}*/
			/*case 7:
			{
				long long L = LL;
				long long R = LL;
				int K = ;
				_expected = LL;
				_received = _obj.solve(L, R, K); break;
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
