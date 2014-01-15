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


class CheckerExpansion {
	public:
	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) ;
};

vector <string> CheckerExpansion::resultAfter(long long t, long long x0, long long y0, int w, int h) {
		
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
		cout << "Testing CheckerExpansion (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383502941;
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
		CheckerExpansion _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long t = 1LL;
				long long x0 = 0LL;
				long long y0 = 0LL;
				int w = 4;
				int h = 4;
				string __expected[] = {"....", "....", "....", "A..." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 1:
			{
				long long t = 5LL;
				long long x0 = 4LL;
				long long y0 = 1LL;
				int w = 3;
				int h = 4;
				string __expected[] = {"A..", "...", "B..", ".B." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 2:
			{
				long long t = 1024LL;
				long long x0 = 1525LL;
				long long y0 = 512LL;
				int w = 20;
				int h = 2;
				string __expected[] = {"B...B...B...........", ".B.A.B.A.B.........." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 3:
			{
				long long t = 53LL;
				long long x0 = 85LL;
				long long y0 = 6LL;
				int w = 5;
				int h = 14;
				string __expected[] = {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			/*case 4:
			{
				long long t = LL;
				long long x0 = LL;
				long long y0 = LL;
				int w = ;
				int h = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}*/
			/*case 5:
			{
				long long t = LL;
				long long x0 = LL;
				long long y0 = LL;
				int w = ;
				int h = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}*/
			/*case 6:
			{
				long long t = LL;
				long long x0 = LL;
				long long y0 = LL;
				int w = ;
				int h = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
