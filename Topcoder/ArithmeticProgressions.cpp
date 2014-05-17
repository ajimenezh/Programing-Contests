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


class ArithmeticProgressions {
	public:
	vector <string> maxAptitude(vector <string> numbers) ;
};

vector <string> ArithmeticProgressions::maxAptitude(vector <string> numbers) {
		
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
		cout << "Testing ArithmeticProgressions (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394047184;
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
		ArithmeticProgressions _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers[] = {"1", "3", "5", "8"};
				string __expected[] = {"3", "4" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 1:
			{
				string numbers[] = {"1", "3", "5", "7", "9", "11", "13", "15", "17", "19"};
				string __expected[] = {"1", "1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 2:
			{
				string numbers[] = {"1", "999999999999999999"};
				string __expected[] = {"0", "1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 3:
			{
				string numbers[] = {"1", "7", "13", "3511", "1053", "10", "5"};
				string __expected[] = {"3", "391" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			/*case 4:
			{
				string numbers[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string numbers[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string numbers[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.maxAptitude(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
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
