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


class WhiteHats {
	public:
	int whiteNumber(vector <int> count) ;
};

int WhiteHats::whiteNumber(vector <int> count) {
	int m = 0;
	for (int i=0; i<count.size(); i++) m = max(count[i], m);
	int k = 0;
	for (int i=0; i<count.size(); i++) if (count[i]==m-1) k++;
	for (int i=0; i<count.size(); i++) {
        if (count[i]!=m && count[i]!=m-1) return -1;
	}
	if (k==m) return m;
	k = 0;
	for (int i=0; i<count.size(); i++) if (count[i]==m) k++;
	if (k==count.size() && m==count.size()-1) return m+1;
	else return -1;
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
		cout << "Testing WhiteHats (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393793224;
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
		WhiteHats _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int count[] = {2,1,1};
				_expected = 2;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 1:
			{
				int count[] = {2,2,2};
				_expected = 3;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 2:
			{
				int count[] = {0,0};
				_expected = 0;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 3:
			{
				int count[] = {1,1,1,2};
				_expected = -1;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 4:
			{
				int count[] = {10,10};
				_expected = -1;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			/*case 5:
			{
				int count[] = ;
				_expected = ;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int count[] = ;
				_expected = ;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int count[] = ;
				_expected = ;
				_received = _obj.whiteNumber(vector <int>(count, count+sizeof(count)/sizeof(int))); break;
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
