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


class RailwayTickets {
	public:
	int minRejects(vector <string> travel, int seats) ;
};

int RailwayTickets::minRejects(vector <string> travel, int seats) {
		
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
		cout << "Testing RailwayTickets (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392124822;
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
		RailwayTickets _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string travel[] = {"1-3 3-5",
				                   "2-4 4-6",
				                   "1-2 2-3 3-4 4-5"};
				int seats = 2;
				_expected = 2;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
			}
			case 1:
			{
				string travel[] = {"1-10000","2-10000","1-9999","2-9999","5000-5001"};
				int seats = 3;
				_expected = 2;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
			}
			case 2:
			{
				string travel[] = {"1-2 2-5 2-8 234-236 56-878 6-34",
				                   "234-776 3242-8000 999-1000 3-14",
				                   "121-122 435-3455 123-987 77-999"};
				int seats = 1000;
				_expected = 0;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
			}
			case 3:
			{
				string travel[] = {"1-2 2-3 3-4 4-5 5-6 6-7 1-3 2-7 1-2 1-4"};
				int seats = 1;
				_expected = 4;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
			}
			/*case 4:
			{
				string travel[] = ;
				int seats = ;
				_expected = ;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
			}*/
			/*case 5:
			{
				string travel[] = ;
				int seats = ;
				_expected = ;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
			}*/
			/*case 6:
			{
				string travel[] = ;
				int seats = ;
				_expected = ;
				_received = _obj.minRejects(vector <string>(travel, travel+sizeof(travel)/sizeof(string)), seats); break;
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
