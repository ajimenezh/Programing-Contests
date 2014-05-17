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


class BrokenButtons {
	public:
	int minPresses(int page, vector <int> broken) ;
};

set<int> v;
bool check(int k) {
    if (k==0) {
        if (v.find(0)!=v.end()) return false;
        return true;
    }
    while (k>0) {
        if (v.find(k%10)!=v.end()) return false;
        k /= 10;
    }
    return true;
}

int len(int k) {
    if (k==0) return 1;
    int l = 0;
    while (k>0) {
        l++;
        k /= 10;
    }
    return l;
}

int BrokenButtons::minPresses(int page, vector <int> broken) {
    int res = abs(page-100);
    for (int i=0; i<broken.size(); i++) v.insert(broken[i]);
    for (int i=0; i<=1000000; i++) if(check(i)) res = min(res, abs(page-i) + len(i));
    return res;
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
		cout << "Testing BrokenButtons (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393679326;
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
		BrokenButtons _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int page = 5457;
				int broken[] = { 6, 7, 8 };
				_expected = 6;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}
			case 1:
			{
				int page = 100;
				int broken[] = { 1, 0, 5 };
				_expected = 0;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}
			case 2:
			{
				int page = 14124;
				int broken[] = { };
				_expected = 5;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}
			case 3:
			{
				int page = 1;
				int broken[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				_expected = 2;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}
			case 4:
			{
				int page = 80000;
				int broken[] = { 8, 9 };
				_expected = 2228;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}
			/*case 5:
			{
				int page = ;
				int broken[] = ;
				_expected = ;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int page = ;
				int broken[] = ;
				_expected = ;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int page = ;
				int broken[] = ;
				_expected = ;
				_received = _obj.minPresses(page, vector <int>(broken, broken+sizeof(broken)/sizeof(int))); break;
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
