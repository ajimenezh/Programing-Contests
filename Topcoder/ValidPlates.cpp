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


class ValidPlates {
	public:
	string getPlate(vector <string> profane, int seqno) ;
};

string ValidPlates::getPlate(vector <string> profane, int seqno) {
		
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
		cout << "Testing ValidPlates (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389096849;
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
		ValidPlates _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string profane[] = {};
				int seqno = 1000;
				_expected = "1000";
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}
			case 1:
			{
				string profane[] = {"10"};
				int seqno = 10;
				_expected = "11";
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}
			case 2:
			{
				string profane[] = {"10"};
				int seqno = 2000000000;
				_expected = "2277659869";
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}
			case 3:
			{
				string profane[] = {"00 01 02 03 04 05 06 07 08 09 11 12 13 14 15 16 17",
				                    "18 19 22 23 24 25 26 27 28 29 33 34 35 36 37 38 39",
				                    "44 45 46 47 48 49 55 56 57 58 59 66 67 68 69 77 78",
				                    "79 88 89 99 99 99 99 99"};
				int seqno = 1023;
				_expected = "";
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}
			case 4:
			{
				string profane[] = {"00 01 02 03 04 05 07 08 09",
				                    "10 11 12 13 14 15 17 18 19",
				                    "20 21 22 24 25 26 27 28 29",
				                    "30 31 32 33 34 36 37 38 39",
				                    "41 43 45 46 48",
				                    "52 53 54 55 56 58 59",
				                    "60 61 63 64 66 67 68 69",
				                    "70 72 73 74 75 76 77 78",
				                    "80 81 82 83 84 86 87 88 89",
				                    "90 91 92 94 95 96 97 98"};
				int seqno = 2000000000;
				_expected = "79999999351623516571657999935799993";
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}
			case 5:
			{
				string profane[] = {"00 01 02 03 04 05 06 07 08 09",
				                    "10 11 12 13 14 16 17 19",
				                    "20 21 22 23 24 25 26 27 28 29",
				                    "30 31 32 33 34 35 36 38 39",
				                    "41 42 43 44 45 46 49",
				                    "50 52 53 54 55 57 58 59",
				                    "60 61 62 63 64 65 66 67 68 69",
				                    "70 72 73 74 75 76 77 78 79",
				                    "80 81 82 83 84 85 86 87 88 89",
				                    "90 91 92 93 94 95 98 99"};
				int seqno = 2000000000;
				_expected = "37151515151515151515151515151515151515151515151...";
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}
			/*case 6:
			{
				string profane[] = ;
				int seqno = ;
				_expected = ;
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}*/
			/*case 7:
			{
				string profane[] = ;
				int seqno = ;
				_expected = ;
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
			}*/
			/*case 8:
			{
				string profane[] = ;
				int seqno = ;
				_expected = ;
				_received = _obj.getPlate(vector <string>(profane, profane+sizeof(profane)/sizeof(string)), seqno); break;
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
