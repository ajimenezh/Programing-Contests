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


class AliceBobShuffle {
	public:
	int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd) ;
};

int AliceBobShuffle::countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd) {
		
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
		cout << "Testing AliceBobShuffle (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383846510;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AliceBobShuffle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int AliceStart[] = {1, 3};
				int BobStart[] = {2, 4};
				int AliceEnd[] = {2, 3};
				int BobEnd[] = {1, 4};
				_expected = 4;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}
			case 1:
			{
				int AliceStart[] = {1, 2, 1};
				int BobStart[] = {1, 2};
				int AliceEnd[] = {1, 2, 1};
				int BobEnd[] = {2, 1};
				_expected = 4;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}
			case 2:
			{
				int AliceStart[] = {1};
				int BobStart[] = {2};
				int AliceEnd[] = {3};
				int BobEnd[] = {4};
				_expected = 0;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}
			case 3:
			{
				int AliceStart[] = {1, 2};
				int BobStart[] = {3};
				int AliceEnd[] = {3};
				int BobEnd[] = {2, 1};
				_expected = 0;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}
			case 4:
			{
				int AliceStart[] = {3, 3, 2, 4, 1, 3, 1, 2, 1, 1, 5, 5, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2};
				int BobStart[] = {4, 1, 4, 3, 4, 4, 4, 3, 2, 1, 6, 2, 2, 3, 2, 2, 1, 3, 2, 3};
				int AliceEnd[] = {4, 1, 4, 3, 4, 4, 4, 1, 3, 1, 2, 2, 2, 3, 2, 1, 2, 1, 2, 2, 2};
				int BobEnd[] = {3, 3, 2, 3, 4, 2, 1, 2, 1, 1, 5, 6, 5, 1, 3, 1, 2, 3, 1, 1, 1, 3};
				_expected = 314159265;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}
			/*case 5:
			{
				int AliceStart[] = ;
				int BobStart[] = ;
				int AliceEnd[] = ;
				int BobEnd[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int AliceStart[] = ;
				int BobStart[] = ;
				int AliceEnd[] = ;
				int BobEnd[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int AliceStart[] = ;
				int BobStart[] = ;
				int AliceEnd[] = ;
				int BobEnd[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(AliceStart, AliceStart+sizeof(AliceStart)/sizeof(int)), vector <int>(BobStart, BobStart+sizeof(BobStart)/sizeof(int)), vector <int>(AliceEnd, AliceEnd+sizeof(AliceEnd)/sizeof(int)), vector <int>(BobEnd, BobEnd+sizeof(BobEnd)/sizeof(int))); break;
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
