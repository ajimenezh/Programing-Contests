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


class TheJediTest {
	public:
	int minimumSupervisors(vector <int> students, int K) ;
};

int TheJediTest::minimumSupervisors(vector <int> students, int K) {
	int ans = 0;
	for (int i=0; i<students.size(); i++) {
        if (students[i]>0) ans += (students[i] - 1)/K + 1;
        int r = (K - students[i]%K)%K;
        if (i<students.size()-1) {
            int tmp = min(students[i+1],r);
            r -= tmp;
            students[i+1] -= tmp;
        }
        if (i<students.size()-2) {
            int tmp = min(students[i+2],r);
            r -= tmp;
            students[i+2] -= tmp;
        }
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
		cout << "Testing TheJediTest (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381764825;
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
		TheJediTest _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int students[] = {3, 6, 3};
				int K = 4;
				_expected = 3;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 1:
			{
				int students[] = {1, 1, 1, 1};
				int K = 4;
				_expected = 2;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 2:
			{
				int students[] = {0, 0, 0, 0};
				int K = 12345;
				_expected = 0;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 3:
			{
				int students[] = {15, 0, 13, 4, 29, 6, 2};
				int K = 7;
				_expected = 10;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 4:
			{
				int students[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
				int K = 114;
				_expected = 102138;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int students[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int students[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int students[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
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
