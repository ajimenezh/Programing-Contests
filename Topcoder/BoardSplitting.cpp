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


class BoardSplitting {
	public:
	int minimumCuts(int desiredLength, int desiredCount, int actualLength) ;
};

int BoardSplitting::minimumCuts(int desiredLength, int desiredCount, int actualLength) {
		
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
		cout << "Testing BoardSplitting (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383846507;
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
		BoardSplitting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int desiredLength = 5;
				int desiredCount = 4;
				int actualLength = 4;
				_expected = 3;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
			}
			case 1:
			{
				int desiredLength = 6;
				int desiredCount = 100;
				int actualLength = 3;
				_expected = 0;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
			}
			case 2:
			{
				int desiredLength = 500;
				int desiredCount = 5;
				int actualLength = 1000;
				_expected = 3;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
			}
			case 3:
			{
				int desiredLength = 314;
				int desiredCount = 159;
				int actualLength = 26;
				_expected = 147;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
			}
			/*case 4:
			{
				int desiredLength = ;
				int desiredCount = ;
				int actualLength = ;
				_expected = ;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
			}*/
			/*case 5:
			{
				int desiredLength = ;
				int desiredCount = ;
				int actualLength = ;
				_expected = ;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
			}*/
			/*case 6:
			{
				int desiredLength = ;
				int desiredCount = ;
				int actualLength = ;
				_expected = ;
				_received = _obj.minimumCuts(desiredLength, desiredCount, actualLength); break;
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
