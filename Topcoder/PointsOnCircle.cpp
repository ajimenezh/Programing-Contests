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


class PointsOnCircle {
	public:
	long long count(int r) ;
};

long long PointsOnCircle::count(int r) {
	unsigned long long t1 = 0, t3 = 0;
	for (int i=1; (unsigned long long)i*i<=r; i++) if (r%i==0) {
        unsigned long long k = ((unsigned long long)r*r)/i;
        if (i%4==1) {
            t3 += (k%4==3);
            t1 += (k%4>0);
        }
        if (i%4==3) {
            t1 += (k%4==3);
            t3 += (k%4>0);
        }
	}
	cout<<t1<<" "<<t3<<endl;
	return (long long)4*(t1-t3);
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
		cout << "Testing PointsOnCircle (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394045299;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PointsOnCircle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int r = 1;
				_expected = 4LL;
				_received = _obj.count(r); break;
			}
			case 1:
			{
				int r = 2000000000;
				_expected = 76LL;
				_received = _obj.count(r); break;
			}
			case 2:
			{
				int r = 3;
				_expected = 4LL;
				_received = _obj.count(r); break;
			}
			case 3:
			{
				int r = 1053;
				_expected = 12LL;
				_received = _obj.count(r); break;
			}
			/*case 4:
			{
				int r = ;
				_expected = LL;
				_received = _obj.count(r); break;
			}*/
			/*case 5:
			{
				int r = ;
				_expected = LL;
				_received = _obj.count(r); break;
			}*/
			/*case 6:
			{
				int r = ;
				_expected = LL;
				_received = _obj.count(r); break;
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
