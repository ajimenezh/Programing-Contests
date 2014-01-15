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


class MagicalHats {
	public:
	int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) ;
};

int MagicalHats::findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
		
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
		cout << "Testing MagicalHats (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383506034;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MagicalHats _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"H"};
				int coins[] = {1};
				int numGuesses = 1;
				_expected = 1;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 1:
			{
				string board[] = {"HHH",
				                  "H.H",
				                  "HH."};
				int coins[] = {9};
				int numGuesses = 1;
				_expected = 9;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 2:
			{
				string board[] = {"HH",
				                  "HH"};
				int coins[] = {1,2,3,4};
				int numGuesses = 3;
				_expected = 6;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 3:
			{
				string board[] = {"HHH",
				                  "HHH",
				                  "H.H"};
				int coins[] = {13,13,13,13};
				int numGuesses = 2;
				_expected = 13;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 4:
			{
				string board[] = {"HHH",
				                  "HHH",
				                  "H.H"};
				int coins[] = {13,13,13,13};
				int numGuesses = 3;
				_expected = 26;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 5:
			{
				string board[] = {"H.H.",
				                  ".H.H",
				                  "H.H."};
				int coins[] = {17};
				int numGuesses = 6;
				_expected = -1;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 6:
			{
				string board[] = {"HHH",
				                  "H.H",
				                  "HHH",
				                  "H.H",
				                  "HHH"};
				int coins[] = {33,337,1007,2403,5601,6003,9999};
				int numGuesses = 5;
				_expected = 1377;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 7:
			{
				string board[] = {".............",
				                  ".............",
				                  ".............",
				                  ".............",
				                  ".............",
				                  ".............",
				                  ".....H.H.....",
				                  "......H......",
				                  ".....H.H.....",
				                  ".............",
				                  ".............",
				                  ".............",
				                  "............."};
				int coins[] = {22};
				int numGuesses = 3;
				_expected = 22;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			/*case 8:
			{
				string board[] = ;
				int coins[] = ;
				int numGuesses = ;
				_expected = ;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}*/
			/*case 9:
			{
				string board[] = ;
				int coins[] = ;
				int numGuesses = ;
				_expected = ;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				int coins[] = ;
				int numGuesses = ;
				_expected = ;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
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
