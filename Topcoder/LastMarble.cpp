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


class LastMarble {
	public:
	double winningChance(int red, int blue, int removed) ;
};

double LastMarble::winningChance(int red, int blue, int removed) {
		
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
		cout << "Testing LastMarble (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392296415;
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
		LastMarble _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int red = 1;
				int blue = 1;
				int removed = 0;
				_expected = 0.5;
				_received = _obj.winningChance(red, blue, removed); break;
			}
			case 1:
			{
				int red = 1;
				int blue = 2;
				int removed = 0;
				_expected = 0.3333333333333333;
				_received = _obj.winningChance(red, blue, removed); break;
			}
			case 2:
			{
				int red = 2;
				int blue = 1;
				int removed = 0;
				_expected = 0.6666666666666666;
				_received = _obj.winningChance(red, blue, removed); break;
			}
			case 3:
			{
				int red = 2;
				int blue = 2;
				int removed = 1;
				_expected = 0.5;
				_received = _obj.winningChance(red, blue, removed); break;
			}
			/*case 4:
			{
				int red = ;
				int blue = ;
				int removed = ;
				_expected = ;
				_received = _obj.winningChance(red, blue, removed); break;
			}*/
			/*case 5:
			{
				int red = ;
				int blue = ;
				int removed = ;
				_expected = ;
				_received = _obj.winningChance(red, blue, removed); break;
			}*/
			/*case 6:
			{
				int red = ;
				int blue = ;
				int removed = ;
				_expected = ;
				_received = _obj.winningChance(red, blue, removed); break;
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
