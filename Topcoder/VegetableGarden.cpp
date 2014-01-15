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


class VegetableGarden {
	public:
	vector <int> getMinDistances(vector <string> garden) ;
};

vector <int> VegetableGarden::getMinDistances(vector <string> garden) {
		
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
		cout << "Testing VegetableGarden (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389009568;
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
		VegetableGarden _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string garden[] = {"I"};
				int __expected[] = {4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 1:
			{
				string garden[] = {"XX", 
				                   "XI"};
				int __expected[] = {8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 2:
			{
				string garden[] = {"III", 
				                   "IXI",
				                   "III"};
				int __expected[] = {4, 6, 8, 10, 12, 14, 16, 18 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 3:
			{
				string garden[] = {"X.I", 
				                   ".I.", 
				                   "I.."};
				int __expected[] = {8, 10, 14 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 4:
			{
				string garden[] = {"IIXIIXIXII"};
				int __expected[] = {4, 6, 12, 14, 20, 26, 28 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			/*case 5:
			{
				string garden[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string garden[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string garden[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMinDistances(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
