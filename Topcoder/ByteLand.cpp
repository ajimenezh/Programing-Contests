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


class ByteLand {
	public:
	int buildCastles(vector <int> road, vector <int> distance, vector <int> castle, int k) ;
};

int ByteLand::buildCastles(vector <int> road, vector <int> distance, vector <int> castle, int k) {
		
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
		cout << "Testing ByteLand (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391002282;
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
		ByteLand _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int road[] = {1,2,3,4,0};
				int distance[] = {1,1,1,1,1};
				int castle[] = {};
				int k = 1;
				_expected = 2;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}
			case 1:
			{
				int road[] = {1,2,0};
				int distance[] = {1,2,3};
				int castle[] = {2};
				int k = 1;
				_expected = 1;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}
			case 2:
			{
				int road[] = {0,1};
				int distance[] = {1,1};
				int castle[] = {1};
				int k = 1;
				_expected = 0;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}
			case 3:
			{
				int road[] = {0,2,0,0,2,2,8,3,8,7};
				int distance[] = {10,9,1,8,1,3,7,2,8,1};
				int castle[] = {3,4,6};
				int k = 3;
				_expected = 3;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}
			case 4:
			{
				int road[] = {1, 0};
				int distance[] = {5, 10};
				int castle[] = {};
				int k = 1;
				_expected = 5;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}
			/*case 5:
			{
				int road[] = ;
				int distance[] = ;
				int castle[] = ;
				int k = ;
				_expected = ;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int road[] = ;
				int distance[] = ;
				int castle[] = ;
				int k = ;
				_expected = ;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int road[] = ;
				int distance[] = ;
				int castle[] = ;
				int k = ;
				_expected = ;
				_received = _obj.buildCastles(vector <int>(road, road+sizeof(road)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int)), vector <int>(castle, castle+sizeof(castle)/sizeof(int)), k); break;
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
