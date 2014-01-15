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


class SplittingFoxes2 {
	public:
	vector <int> getPattern(vector <int> amount) ;
};

vector <int> SplittingFoxes2::getPattern(vector <int> amount) {
		
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
		cout << "Testing SplittingFoxes2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380284148;
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
		SplittingFoxes2 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int amount[] = {2,0,1,1,0};
				int __expected[] = {0, 1, 0, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 1:
			{
				int amount[] = {1,0,0,0,0,0};
				int __expected[] = {0, 0, 0, 1, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 2:
			{
				int amount[] = {2,0,0,0,0,0};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 3:
			{
				int amount[] = {10,0,8,0,10,0,8,0};
				int __expected[] = {1, 0, 2, 0, 1, 0, 2, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 4:
			{
				int amount[] = {35198,27644,22185,26896,34136,26896,22185,27644};
				int __expected[] = {0, 59, 90, 76, 22, 76, 90, 59 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 5:
			{
				int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				int __expected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			/*case 6:
			{
				int amount[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int amount[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int amount[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPattern(vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
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
