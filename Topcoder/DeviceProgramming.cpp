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


class DeviceProgramming {
	public:
	long long minBytes(vector <int> offset, vector <int> size, int maxPacketSize, int overhead) ;
};

long long DeviceProgramming::minBytes(vector <int> offset, vector <int> size, int maxPacketSize, int overhead) {
		
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
		cout << "Testing DeviceProgramming (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394133827;
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
		DeviceProgramming _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int offset[] = {0, 42, 60};
				int size[] = {40, 15, 2};
				int maxPacketSize = 26;
				int overhead = 6;
				_expected = 78LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}
			case 1:
			{
				int offset[] = {0, 42, 60};
				int size[] = {40, 15, 13};
				int maxPacketSize = 26;
				int overhead = 6;
				_expected = 92LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}
			case 2:
			{
				int offset[] = {0, 2, 13};
				int size[] = {1, 7, 2};
				int maxPacketSize = 10;
				int overhead = 5;
				_expected = 26LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}
			case 3:
			{
				int offset[] = {10264, 111, 357, 100066, 714};
				int size[] = {117, 134, 235, 2395, 23};
				int maxPacketSize = 100;
				int overhead = 10;
				_expected = 3254LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}
			case 4:
			{
				int offset[] = {1, 100000000, 450000000};
				int size[] = {99999999, 315000000, 500000000};
				int maxPacketSize = 1000;
				int overhead = 30;
				_expected = 943298999LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}
			case 5:
			{
				int offset[] = {0, 1000000000};
				int size[] = {1000000000, 1000000000};
				int maxPacketSize = 1000;
				int overhead = 999;
				_expected = 2000000000000LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}
			/*case 6:
			{
				int offset[] = ;
				int size[] = ;
				int maxPacketSize = ;
				int overhead = ;
				_expected = LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}*/
			/*case 7:
			{
				int offset[] = ;
				int size[] = ;
				int maxPacketSize = ;
				int overhead = ;
				_expected = LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
			}*/
			/*case 8:
			{
				int offset[] = ;
				int size[] = ;
				int maxPacketSize = ;
				int overhead = ;
				_expected = LL;
				_received = _obj.minBytes(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxPacketSize, overhead); break;
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
