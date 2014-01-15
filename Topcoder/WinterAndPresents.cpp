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


class WinterAndPresents {
	public:
	long long getNumber(vector <int> apple, vector <int> orange) ;
};

long long WinterAndPresents::getNumber(vector <int> apple, vector <int> orange) {
    long long a=0,b=0;
    int m = 10000000;
    for (int i=0; i<apple.size(); i++) {
        a += apple[i];
        b += orange[i];
        m = min(apple[i]+orange[i], m);
    }
    long long res = 0;
    if (a>b) swap(a,b);
    for (int i=1; i<=m; i++) {
        long long k1 = 0, k2 = 0;
        long long t1 = 0, t2 = 0;
        for (int j=0; j<apple.size(); j++) {
            if (apple[j]<=i) {
                k1 += apple[j];
                k2 += -apple[j]+i;
            }
            else {
                k1 += i;
            }
            if (orange[j]<=i) {
                t1 += orange[j];
                t2 += i-orange[j];
            }
            else {
                t1 += i;
            }
        }
        res += min(abs(k1-t2),abs(k2-t1)) + 1;
    }
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
		cout << "Testing WinterAndPresents (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1387731904;
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
		WinterAndPresents _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int apple[] = {1};
				int orange[] = {1};
				_expected = 3LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 1:
			{
				int apple[] = {1, 2, 0, 3};
				int orange[] = {4, 5, 0, 6};
				_expected = 0LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 2:
			{
				int apple[] = {2, 2, 2};
				int orange[] = {2, 2, 2};
				_expected = 16LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 3:
			{
				int apple[] = {7, 4, 5};
				int orange[] = {1, 10, 2};
				_expected = 46LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 4:
			{
				int apple[] = {1000000};
				int orange[] = {1000000};
				_expected = 1000002000000LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 5:
			{
				int apple[] = {7, 4, 5};
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
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
