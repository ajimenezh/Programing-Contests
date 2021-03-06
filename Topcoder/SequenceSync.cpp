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


class SequenceSync {
	public:
	int getLength(vector <string> transitions) ;
};

int SequenceSync::getLength(vector <string> transitions) {
		
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
		cout << "Testing SequenceSync (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379786593;
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
		SequenceSync _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string transitions[] = {"1 1 1 1",
				                        "1 1 1 2",
				                        "0 2 2 2"};
				_expected = 2;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
			}
			case 1:
			{
				string transitions[] = {"1 1 1 1",
				                        "2 2 2 2",
				                        "3 3 3 3",
				                        "0 0 0 0"};
				_expected = -1;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
			}
			case 2:
			{
				string transitions[] = {"0 0 0 0"};
				_expected = 0;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
			}
			case 3:
			{
				string transitions[] = {"1 1 1 0",
				                        "2 2 2 1",
				                        "3 3 3 2",
				                        "4 4 4 3",
				                        "5 5 5 5",
				                        "6 6 6 6",
				                        "7 7 7 0",
				                        "0 0 0 8",
				                        "8 8 8 8",
				                        "9 9 9 8"};
				_expected = 15;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
			}
			/*case 4:
			{
				string transitions[] = ;
				_expected = ;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string transitions[] = ;
				_expected = ;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string transitions[] = ;
				_expected = ;
				_received = _obj.getLength(vector <string>(transitions, transitions+sizeof(transitions)/sizeof(string))); break;
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
