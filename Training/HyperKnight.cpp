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


class HyperKnight {
	public:
	long long countCells(int a, int b, int numRows, int numColumns, int k) ;
};

long long HyperKnight::countCells(int _a, int _b, int numRows, int numColumns, int k) {
    long long ans = 0;
    long long n = numRows;
    long long m = numColumns;
    long long a = _a;
    long long b = _b;

    if (k==8) {
        ans = (m-2*max(a,b))*(n-2*max(a,b));
    }
    else if (k==6) {
        ans = 2*(max(b,a)-min(b,a))*(m - 2*max(a,b)) + 2*(max(b,a)-min(b,a))*(n - 2*max(a,b));
    }
    else if (k==4) {
        ans = 2*(min(b,a))*(m - 2*max(a,b)) + 2*(min(b,a))*(n - 2*max(a,b));
        ans += 4*(max(b,a)-min(b,a))*(max(b,a)-min(b,a));
    }
    else if (k==3) {
        ans = 8*(min(b,a))*(max(b,a)-min(b,a));
    }
    else if (k==2) {
        ans = 4*(min(b,a))*(min(b,a));
    }

    return ans;
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
		cout << "Testing HyperKnight (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383237674;
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
		HyperKnight _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 2;
				int b = 1;
				int numRows = 8;
				int numColumns = 8;
				int k = 4;
				_expected = 20LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 1:
			{
				int a = 3;
				int b = 2;
				int numRows = 8;
				int numColumns = 8;
				int k = 2;
				_expected = 16LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 2:
			{
				int a = 1;
				int b = 3;
				int numRows = 7;
				int numColumns = 11;
				int k = 0;
				_expected = 0LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 3:
			{
				int a = 3;
				int b = 2;
				int numRows = 10;
				int numColumns = 20;
				int k = 8;
				_expected = 56LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 4:
			{
				int a = 1;
				int b = 4;
				int numRows = 100;
				int numColumns = 10;
				int k = 6;
				_expected = 564LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 5:
			{
				int a = 2;
				int b = 3;
				int numRows = 1000000000;
				int numColumns = 1000000000;
				int k = 8;
				_expected = 999999988000000036LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int numRows = ;
				int numColumns = ;
				int k = ;
				_expected = LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int numRows = ;
				int numColumns = ;
				int k = ;
				_expected = LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int numRows = ;
				int numColumns = ;
				int k = ;
				_expected = LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
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
