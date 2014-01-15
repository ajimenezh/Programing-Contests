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


class TeamContest {
	public:
	int worstRank(vector <int> strength) ;
};


int TeamContest::worstRank(vector <int> strength) {
	vector<int> s = strength;
	sort(s.begin(),s.begin()+3);
	int t = s[0] + s[2];
	sort(s.begin()+3,s.begin()+s.size());

	int ans = 1;
	int lo = 3;
	for (int i=s.size()-1; i>=lo; i--) {
        if (s[i]+s[lo]>t) {
            ans++;
            lo += 2;
        }
        else  {
            lo += 3;
            i++;
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
		cout << "Testing TeamContest (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381263488;
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
		TeamContest _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int strength[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
				_expected = 2;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 1:
			{
				int strength[] = {5, 7, 3};
				_expected = 1;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 2:
			{
				int strength[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 3:
			{
				int strength[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5};
				_expected = 3;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 4:
			{
				int strength[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43};
				_expected = 3;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			/*case 5:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
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
