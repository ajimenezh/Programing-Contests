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


class Suminator {
	public:
	int findMissing(vector <int> program, int wantedResult) ;
};

int Suminator::findMissing(vector <int> program, int wantedResult) {
		
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
		cout << "Testing Suminator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383470537;
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
		Suminator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int program[] = {7,-1,0};
				int wantedResult = 10;
				_expected = 3;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 1:
			{
				int program[] = {100, 200, 300, 0, 100, -1};
				int wantedResult = 600;
				_expected = 0;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 2:
			{
				int program[] = {-1, 7, 3, 0, 1, 2, 0, 0};
				int wantedResult = 13;
				_expected = 0;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 3:
			{
				int program[] = {-1, 8, 4, 0, 1, 2, 0, 0};
				int wantedResult = 16;
				_expected = -1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 4:
			{
				int program[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
				int wantedResult = 1000000000;
				_expected = -1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 5:
			{
				int program[] = {7, -1, 3, 0};
				int wantedResult = 3;
				_expected = -1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			/*case 6:
			{
				int program[] = ;
				int wantedResult = ;
				_expected = ;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}*/
			/*case 7:
			{
				int program[] = ;
				int wantedResult = ;
				_expected = ;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}*/
			/*case 8:
			{
				int program[] = ;
				int wantedResult = ;
				_expected = ;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
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
