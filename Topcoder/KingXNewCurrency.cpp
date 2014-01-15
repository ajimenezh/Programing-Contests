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


class KingXNewCurrency {
	public:
	int howMany(int A, int B, int X) ;
};


int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int KingXNewCurrency::howMany(int A, int B, int X) {
	int k = 0;
	for (int i=0; i<1000; i++) {
        if (i==0) {
            if (A%X==0 && B%X==0) k++;
        }
        else {
            bool good = 0;
            for (int j=0; j*X<=A; j++) if ((A-j*X)%i==0) {
                good = 1;
                break;
            }
            if (!good) continue;
            good = 0;
            for (int j=0; j*X<=B; j++) if ((B-j*X)%i==0) {
                good = 1;
                break;
            }
            if (good) k++;
        }
	}

	if (k==1000) return -1;
    return k;
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
		cout << "Testing KingXNewCurrency (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384188759;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KingXNewCurrency _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 5;
				int B = 8;
				int X = 5;
				_expected = 5;
				_received = _obj.howMany(A, B, X); break;
			}
			case 1:
			{
				int A = 8;
				int B = 4;
				int X = 2;
				_expected = -1;
				_received = _obj.howMany(A, B, X); break;
			}
			case 2:
			{
				int A = 7;
				int B = 4;
				int X = 13;
				_expected = 1;
				_received = _obj.howMany(A, B, X); break;
			}
			case 3:
			{
				int A = 47;
				int B = 74;
				int X = 44;
				_expected = 2;
				_received = _obj.howMany(A, B, X); break;
			}
			case 4:
			{
				int A = 128;
				int B = 96;
				int X = 3;
				_expected = 65;
				_received = _obj.howMany(A, B, X); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int X = ;
				_expected = ;
				_received = _obj.howMany(A, B, X); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int X = ;
				_expected = ;
				_received = _obj.howMany(A, B, X); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int X = ;
				_expected = ;
				_received = _obj.howMany(A, B, X); break;
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
