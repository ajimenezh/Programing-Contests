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


class EqualSums {
	public:
	int count(vector <string> board) ;
};

int EqualSums::count(vector <string> board) {
		
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
		cout << "Testing EqualSums (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381775123;
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
		EqualSums _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"1-",
				                  "-2"};
				_expected = 4;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"123",
				                  "4--",
				                  "--9"};
				_expected = 1;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"9--",
				                  "-9-",
				                  "--9"};
				_expected = 271;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"11",
				                  "12"};
				_expected = 0;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"-4--",
				                  "-0-2",
				                  "--1-",
				                  "4---"};
				_expected = 10;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"--2",
				                  "02-",
				                  "-10"};
				_expected = 0;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"----------1---------------0-----7-----------------",
				                  "-----4--------------------------------------------",
				                  "--------5-------------5-3---5---------------6-----",
				                  "-------2----------1-------------------------------",
				                  "-----4--------------------------------------------",
				                  "-----3--------------------------------------------",
				                  "-6----------5-------------------------------------",
				                  "-------------------------------7---5----------6---",
				                  "--------6-------------6-4---6---------------7-----",
				                  "-------------4----------------5-------------------",
				                  "3------------------------------------------6------",
				                  "3------------------------------------------6------",
				                  "-------------4----------------5-------------------",
				                  "---------------2-------------------------3--------",
				                  "--2------------------------------------------2----",
				                  "---8---------------1-------------------3----------",
				                  "---------------3----------------------------------",
				                  "----7----------------5---0-----------------------5",
				                  "----------------5-------------------------3-----1-",
				                  "----------1---------------0-----7-----------------",
				                  "-------------5----------------6-------------------",
				                  "-7----------6-------------------------------------",
				                  "---8---------------1-------------------3----------",
				                  "-----------------------3--------------------------",
				                  "----8----------------6---1-----------------------6",
				                  "------------------------------------------4-----2-",
				                  "-----------5---------------5----------------------",
				                  "-----------------------------6--------------------",
				                  "----8----------------6---1-----------------------6",
				                  "----------------5-------------------------3-----1-",
				                  "-------------------------------6---4--2-------5---",
				                  "-6----------5-------------------------------------",
				                  "--------5-------------5-3---5---------------6-----",
				                  "-------------5----------------6-------------------",
				                  "-----3--------------------------------------------",
				                  "---------------2-------------------------3--------",
				                  "---------4---------------------------6------------",
				                  "-------------------------------6---4--2-------5---",
				                  "------2-------------1------------22---------------",
				                  "--------5-------------5-3---5---------------6-----",
				                  "-----------5--3------------5----------------------",
				                  "--2------------------------------------------2----",
				                  "---------5---------------------------7------------",
				                  "-------------4----------------5-------------------",
				                  "-----------------5------------------4---6------2--",
				                  "-------------------------------6---4--2-------5---",
				                  "-----------------------2--------------------------",
				                  "----------------6-------------------------4-----2-", 
				                  "-------------------------------6---4--2-------5---",
				                  "--------5-------------5-3---5---------------6-----"};
				_expected = 45094393;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
