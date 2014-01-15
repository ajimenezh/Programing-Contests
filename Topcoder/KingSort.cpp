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


class KingSort {
	public:
	vector <string> getSortedList(vector <string> kings) ;
};

vector <string> KingSort::getSortedList(vector <string> kings) {
		
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
		cout << "Testing KingSort (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384453910;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KingSort _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string kings[] = {"Louis IX", "Louis VIII"};
				string __expected[] = {"Louis VIII", "Louis IX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}
			case 1:
			{
				string kings[] = {"Louis IX", "Philippe II"};
				string __expected[] = {"Louis IX", "Philippe II" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}
			case 2:
			{
				string kings[] = {"Richard III", "Richard I", "Richard II"};
				string __expected[] = {"Richard I", "Richard II", "Richard III" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}
			case 3:
			{
				string kings[] = {"John X", "John I", "John L", "John V"};
				string __expected[] = {"John I", "John V", "John X", "John L" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}
			case 4:
			{
				string kings[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
				string __expected[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}
			case 5:
			{
				string kings[] = {"Philippe II", "Philip II"};
				string __expected[] = {"Philip II", "Philippe II" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}
			/*case 6:
			{
				string kings[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string kings[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string kings[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSortedList(vector <string>(kings, kings+sizeof(kings)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
