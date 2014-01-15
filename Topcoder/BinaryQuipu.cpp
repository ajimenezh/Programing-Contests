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


class BinaryQuipu {
	public:
	int fewestKnots(vector <string> inventory) ;
};

int BinaryQuipu::fewestKnots(vector <string> inventory) {
		
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
		cout << "Testing BinaryQuipu (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379268020;
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
		BinaryQuipu _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string inventory[] = {"bsb", "bbs", "sbbs", "sbs"};
				_expected = 8;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}
			case 1:
			{
				string inventory[] = {"s", "b"};
				_expected = 3;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}
			case 2:
			{
				string inventory[] = {"bs", "sb"};
				_expected = 5;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}
			case 3:
			{
				string inventory[] = {"bs", "sb", "bb", "ss"};
				_expected = 5;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}
			case 4:
			{
				string inventory[] = {"bssbs", "ssbs", "sbb", "bbs", "sbs", "ssbb"};
				_expected = 10;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}
			case 5:
			{
				string inventory[] = {"bbbsssbbsbbssbbbbs",
				                     "bssssbbbbsbbsbbbbbbsbbsbsssbbbsbbbbbsbbssbsb",
				                     "sbbbbbsbbbsbsssbssssbssbbsssssssbbssss",
				                     "sbbbbbsbsbssbssbsssbsbbsbssbsbbbsbsbs",
				                     "bsbbbbbssbsbbbbsbbs",
				                     "bbsbbsbsssbsbbsbbssbbbsbsssbsbbsbsbssbsbsssbsbsbs"};
				_expected = 181;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}
			/*case 6:
			{
				string inventory[] = ;
				_expected = ;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string inventory[] = ;
				_expected = ;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string inventory[] = ;
				_expected = ;
				_received = _obj.fewestKnots(vector <string>(inventory, inventory+sizeof(inventory)/sizeof(string))); break;
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
