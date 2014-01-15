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


class RangeGame {
	public:
	vector <int> bestDoors(vector <string> possible, vector <string> hints) ;
};

vector <int> RangeGame::bestDoors(vector <string> possible, vector <string> hints) {
		
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
		cout << "Testing RangeGame (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379264545;
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
		RangeGame _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string possible[] = {"1-100","100-200","200-300"};
				string hints[] = {"50-75","250-1000"};
				int __expected[] = { 100,  200,  100 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}
			case 1:
			{
				string possible[] = {"100-900 1111","200-800 2222","300-700 3333","4444"};
				string hints[] = {"2000-4000","500"};
				int __expected[] = { 300,  100,  4444 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}
			case 2:
			{
				string possible[] = {"346591240","858005279","1321831520","1453846384","1972718383","530431653-1848872872"};
				string hints[] = {"1400000000-2000000000","400000000-600000000"};
				int __expected[] = { 858005279,  346591240,  346591240 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}
			/*case 3:
			{
				string possible[] = ;
				string hints[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string possible[] = ;
				string hints[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string possible[] = ;
				string hints[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
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
