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


class AlphabetPaths {
	public:
	long long count(vector <string> letterMaze) ;
};

long long AlphabetPaths::count(vector <string> letterMaze) {
		
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
		cout << "Testing AlphabetPaths (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1386149994;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlphabetPaths _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string letterMaze[] = {"ABCDEFZHIXKLMNOPQRST",
				                       "...................V"};
				_expected = 2LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 1:
			{
				string letterMaze[] = {".................VT.",
				                       "....................",
				                       "ABCDEFZHIXKLMNOPQRS.",
				                       "..................S.",
				                       ".................VT."};
				_expected = 0LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 2:
			{
				string letterMaze[] = {"TBCDE.PQRSA", 
				                       "FZHIXKLMNOV"};
				_expected = 50LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 3:
			{
				string letterMaze[] = {"ABCDEF.",
				                       "V....Z.",
				                       "T....H.",
				                       "S....I.",
				                       "R....X.",
				                       "KLMNOPQ"};
				_expected = 4LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			/*case 4:
			{
				string letterMaze[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string letterMaze[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string letterMaze[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
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
