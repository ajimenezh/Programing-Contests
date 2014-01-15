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


class DrivingAround {
	public:
	int numberOfWays(vector <string> adj, int start, int finish, int time) ;
};

int DrivingAround::numberOfWays(vector <string> adj, int start, int finish, int time) {
		
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
		cout << "Testing DrivingAround (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389189800;
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
		DrivingAround _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string adj[] = {".12",
				                "2.1",
				                "12."};
				int start = 0;
				int finish = 2;
				int time = 5;
				_expected = 8;
				_received = _obj.numberOfWays(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), start, finish, time); break;
			}
			case 1:
			{
				string adj[] = {"....52....",
				                "..5.......",
				                "..........",
				                ".......1..",
				                "......42.2",
				                "5...4.....",
				                ".5...4...1",
				                "......5...",
				                ".3244.....",
				                ".........."};
				int start = 2;
				int finish = 2;
				int time = 10;
				_expected = 0;
				_received = _obj.numberOfWays(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), start, finish, time); break;
			}
			case 2:
			{
				string adj[] = {"...14....1",
				                "......13..",
				                ".2...4....",
				                "....52.5..",
				                "1.3..4....",
				                ".3....35.5",
				                "4......1.1",
				                "..4.4.1.54",
				                "....4.11.5",
				                "31144.2.4."};
				int start = 7;
				int finish = 2;
				int time = 100;
				_expected = 316984;
				_received = _obj.numberOfWays(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), start, finish, time); break;
			}
			/*case 3:
			{
				string adj[] = ;
				int start = ;
				int finish = ;
				int time = ;
				_expected = ;
				_received = _obj.numberOfWays(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), start, finish, time); break;
			}*/
			/*case 4:
			{
				string adj[] = ;
				int start = ;
				int finish = ;
				int time = ;
				_expected = ;
				_received = _obj.numberOfWays(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), start, finish, time); break;
			}*/
			/*case 5:
			{
				string adj[] = ;
				int start = ;
				int finish = ;
				int time = ;
				_expected = ;
				_received = _obj.numberOfWays(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), start, finish, time); break;
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
