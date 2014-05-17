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


class WeighingScale {
	public:
	vector <int> count(vector <string> measures, int A, int B) ;
};

vector <int> WeighingScale::count(vector <string> measures, int A, int B) {
		
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
		cout << "Testing WeighingScale (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393798670;
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
		WeighingScale _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string measures[] = {"?+????","-?+???","?-????","????+?", "???-?+","????-?"};
				int A = 1;
				int B = 4;
				int __expected[] = {1, 4, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}
			case 1:
			{
				string measures[] = {"?+?????","-?+????","?-?????","????+??", "???-?+?","????-??", "???????"};
				int A = 0;
				int B = 3;
				int __expected[] = {10, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}
			case 2:
			{
				string measures[] = {"?+?????","-?+????","?-?????","????+??", "???-?+?","????-??", "???????"};
				int A = 1;
				int B = 4;
				int __expected[] = {1, 4, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}
			case 3:
			{
				string measures[] = {"??+?", "???+", "-???", "?-??"};
				int A = 0;
				int B = 1;
				int __expected[] = {1, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}
			case 4:
			{
				string measures[] = {"??+??", "???+?", "-???=", "?-???", "??=??"};
				int A = 0;
				int B = 1;
				int __expected[] = {3, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}
			case 5:
			{
				string measures[] = {"?+???++?????++","-??=?=???????=","??????????=???","?=??+?==??????",
				                    "???-???-???-??","-=????????????","-??=???=?-+???","???=+?=???????",
				                    "??????????????","??????+???????","??=???-????-??","????+?????+???",
				                    "-?????????????","-=????????????"};
				int A = 6;
				int B = 2;
				int __expected[] = {1, 10, 36 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}
			/*case 6:
			{
				string measures[] = ;
				int A = ;
				int B = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}*/
			/*case 7:
			{
				string measures[] = ;
				int A = ;
				int B = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
			}*/
			/*case 8:
			{
				string measures[] = ;
				int A = ;
				int B = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(vector <string>(measures, measures+sizeof(measures)/sizeof(string)), A, B); break;
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
