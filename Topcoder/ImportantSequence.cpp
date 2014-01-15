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


class ImportantSequence {
	public:
	int getCount(vector <int> B, string operators) ;
};

int ImportantSequence::getCount(vector <int> B, string operators) {
		
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
		cout << "Testing ImportantSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384085362;
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
		ImportantSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int B[] = {3, -1, 7};
				string operators = "+-+";
				_expected = 2;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 1:
			{
				int B[] = {1};
				string operators = "-";
				_expected = -1;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 2:
			{
				int B[] = {1};
				string operators = "+";
				_expected = 0;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 3:
			{
				int B[] = {10};
				string operators = "+";
				_expected = 9;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 4:
			{
				int B[] = {540, 2012, 540, 2012, 540, 2012, 540};
				string operators = "-+-+-+-";
				_expected = 1471;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			/*case 5:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}*/
			/*case 6:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}*/
			/*case 7:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
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
