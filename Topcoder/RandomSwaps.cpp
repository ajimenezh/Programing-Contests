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


class RandomSwaps {
	public:
	double getProbability(int arrayLength, int swapCount, int a, int b) ;
};

double RandomSwaps::getProbability(int arrayLength, int swapCount, int a, int b) {
	int n = arrayLength;
	if (n==1) return 1.0;
	double pe = 1.0;
	double pd = 0.0;
	int m = n*(n-1)/2;
	int k = (n-1)*(n-2)/2;
	for (int i=0; i<swapCount; i++) {
        double tmp = pe;
        pe = (double)k*tmp/m + 1.0/m*pd;
        pd = 1.0 - pe;
	}
	if (a==b) return pe;
	else return pd/(double)(n-1);;
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
		cout << "Testing RandomSwaps (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388836412;
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
		RandomSwaps _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int arrayLength = 5;
				int swapCount = 1;
				int a = 0;
				int b = 0;
				_expected = 0.6;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
			}
			case 1:
			{
				int arrayLength = 5;
				int swapCount = 1;
				int a = 0;
				int b = 3;
				_expected = 0.1;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
			}
			case 2:
			{
				int arrayLength = 5;
				int swapCount = 2;
				int a = 0;
				int b = 0;
				_expected = 0.4;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
			}
			case 3:
			{
				int arrayLength = 100;
				int swapCount = 500;
				int a = 3;
				int b = 3;
				_expected = 0.010036635745123007;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
			}
			/*case 4:
			{
				int arrayLength = ;
				int swapCount = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
			}*/
			/*case 5:
			{
				int arrayLength = ;
				int swapCount = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
			}*/
			/*case 6:
			{
				int arrayLength = ;
				int swapCount = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.getProbability(arrayLength, swapCount, a, b); break;
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

//END CUT HERE
