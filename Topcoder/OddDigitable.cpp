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


class OddDigitable {
	public:
	string findMultiple(int N, int M) ;
};

string OddDigitable::findMultiple(int N, int M) {
		
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
		cout << "Testing OddDigitable (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380138637;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OddDigitable _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				int M = 7;
				_expected = "7";
				_received = _obj.findMultiple(N, M); break;
			}
			case 1:
			{
				int N = 22;
				int M = 12;
				_expected = "-1";
				_received = _obj.findMultiple(N, M); break;
			}
			case 2:
			{
				int N = 29;
				int M = 0;
				_expected = "319";
				_received = _obj.findMultiple(N, M); break;
			}
			case 3:
			{
				int N = 5934;
				int M = 2735;
				_expected = "791957";
				_received = _obj.findMultiple(N, M); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.findMultiple(N, M); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.findMultiple(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.findMultiple(N, M); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
