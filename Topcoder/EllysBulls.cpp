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


class EllysBulls {
	public:
	string getNumber(vector <string> guesses, vector <int> bulls) ;
};

string EllysBulls::getNumber(vector <string> guesses, vector <int> bulls) {
		
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
		cout << "Testing EllysBulls (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381418065;
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
		EllysBulls _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guesses[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
				int bulls[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
				_expected = "1337";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 1:
			{
				string guesses[] = {"0000", "1111", "2222"};
				int bulls[] = {2, 2, 2};
				_expected = "Liar";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 2:
			{
				string guesses[] = {"666666", "666677", "777777", "999999"};
				int bulls[] = {2, 3, 1, 0};
				_expected = "Ambiguity";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 3:
			{
				string guesses[] = {"000", "987", "654", "321", "100", "010"};
				int bulls[] = {2, 1, 0, 0, 1, 1};
				_expected = "007";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 4:
			{
				string guesses[] = {"28", "92", "70", "30", "67", "63", "06", "65",
				                    "11", "06", "88", "48", "09", "65", "48", "08"};
				int bulls[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = "54";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 5:
			{
				string guesses[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
				                    "4166623", "1166638", "2767693", "8650248", "2486509",
				                    "6138934", "4018642", "6236742", "2961643", "8407361",
				                    "2097376", "6575410", "6071777", "3569948", "2606380"};
				int bulls[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
				_expected = "4266642";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			/*case 6:
			{
				string guesses[] = ;
				int bulls[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string guesses[] = ;
				int bulls[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string guesses[] = ;
				int bulls[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
