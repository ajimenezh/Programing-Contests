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


class RandomColoring {
	public:
	double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) ;
};

double RandomColoring::getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
		
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
		cout << "Testing RandomColoring (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384085388;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RandomColoring _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int maxR = 5;
				int maxG = 1;
				int maxB = 1;
				int startR = 2;
				int startG = 0;
				int startB = 0;
				int d1 = 0;
				int d2 = 1;
				_expected = 0.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 1:
			{
				int N = 3;
				int maxR = 5;
				int maxG = 1;
				int maxB = 1;
				int startR = 2;
				int startG = 0;
				int startB = 0;
				int d1 = 0;
				int d2 = 1;
				_expected = 0.22222222222222227;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 2:
			{
				int N = 7;
				int maxR = 4;
				int maxG = 2;
				int maxB = 2;
				int startR = 0;
				int startG = 0;
				int startB = 0;
				int d1 = 3;
				int d2 = 3;
				_expected = 1.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 3:
			{
				int N = 10;
				int maxR = 7;
				int maxG = 8;
				int maxB = 9;
				int startR = 1;
				int startG = 2;
				int startB = 3;
				int d1 = 0;
				int d2 = 10;
				_expected = 0.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 4:
			{
				int N = 10;
				int maxR = 7;
				int maxG = 8;
				int maxB = 9;
				int startR = 1;
				int startG = 2;
				int startB = 3;
				int d1 = 4;
				int d2 = 10;
				_expected = 0.37826245943967396;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 5:
			{
				int N = 3;
				int maxR = 3;
				int maxG = 2;
				int maxB = 2;
				int startR = 1;
				int startG = 0;
				int startB = 0;
				int d1 = 1;
				int d2 = 2;
				_expected = 0.09090909090909148;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			/*case 6:
			{
				int N = ;
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			/*case 7:
			{
				int N = ;
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			/*case 8:
			{
				int N = ;
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
