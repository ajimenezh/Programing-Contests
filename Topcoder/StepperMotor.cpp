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


class StepperMotor {
	public:
	int rotateToNearest(int n, int current, vector <int> target) ;
};

int StepperMotor::rotateToNearest(int n, int current, vector <int> target) {
		long long m = n;
		long long cur = current;
		cur = (cur%m + m)%m;
		vector<long long> v;
		for (int i=0;i<target.size(); i++) v.push_back(target[i]);
		for (int i=0; i<v.size(); i++) v[i] = (v[i]%m + m)%m;

		long long best = 1000000000000LL;
		for (int i=0; i<v.size(); i++) {
            long long x = cur;
            long long y = v[i];
            long long tmp;
            if (x>=y) {
                tmp = (y - x + m)%m;
                if (abs(tmp)<abs(best)) {
                    best = tmp;
                }
                else if (tmp==-best) {
                    best = tmp;
                }
                tmp = -x + y;
                if (abs(tmp)<abs(best)) {
                    best = tmp;
                }
            }
            else {
                tmp = y - x;
                if (tmp<abs(best)) {
                    best = tmp;
                }
                else if (tmp==-best) {
                    best = tmp;
                }
                tmp = -(x - y + m)%m;
                if (abs(tmp)<abs(best)) {
                    best = tmp;
                }
            }
		}

        return (int) best;
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
		cout << "Testing StepperMotor (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379778926;
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
		StepperMotor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 10;
				int current = 2147483647;
				int target[] = {-2147483648};
				_expected = 5;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int current = 314159;
				int target[] = {10, 8, 6, 4, 2};
				_expected = 1;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 1;
				int current = -2147483648;
				int target[] = {-2147483648, -2147483648, 2147483647, 2147483647};
				_expected = 0;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 23;
				int current = 10;
				int target[] = {64077, -567273, 105845, -279980, 35557,
				               -286190, -652879, -431665, -634870, -454044};
				_expected = -11;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 1000000000;
				int current = 1403466951;
				int target[] = {1233321992, 11423750, 1356595134, 1130863021, 1183514764,
				               1943494859, 1714480374, 1529875954, 1738756510, 1190153525};
				_expected = -46871817;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int current = ;
				int target[] = ;
				_expected = ;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int current = ;
				int target[] = ;
				_expected = ;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int current = ;
				int target[] = ;
				_expected = ;
				_received = _obj.rotateToNearest(n, current, vector <int>(target, target+sizeof(target)/sizeof(int))); break;
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
