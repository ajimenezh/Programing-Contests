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


class ToyTrain {
	public:
	int getMinCost(vector <string> field) ;
};

int ToyTrain::getMinCost(vector <string> field) {
		
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
		cout << "Testing ToyTrain (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383249005;
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
		ToyTrain _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {"BA",
				                  "SS",
				                  "AB"};
				_expected = 0;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 1:
			{
				string field[] = {"."};
				_expected = -1;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 2:
			{
				string field[] = {"ABBA",
				                  "BAAB"};
				_expected = 0;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 3:
			{
				string field[] = {"AA",
				                  "AA"};
				_expected = -1;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 4:
			{
				string field[] = {"..AB",
				                  "B..A",
				                  "....",
				                  "A.B."};
				_expected = -1;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 5:
			{
				string field[] = {"A1B8A2B",
				                  "16A.B22",
				                  "BAB.9.A",
				                  "ABA.7.B",
				                  "B12345A"};
				_expected = 31;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 6:
			{
				string field[] = {"..A.B",
				                  ".1.2.",
				                  "A.B..",
				                  ".3.4.",
				                  "B...A"};
				_expected = 0;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 7:
			{
				string field[] = {"ASBSBSA",
				                  "S.S.S.S",
				                  "BSASASB"};
				_expected = -1;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			/*case 8:
			{
				string field[] = ;
				_expected = ;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string field[] = ;
				_expected = ;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string field[] = ;
				_expected = ;
				_received = _obj.getMinCost(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
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
