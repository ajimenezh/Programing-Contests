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


class PickingUp {
	public:
	vector <int> fairPickingUp(vector<long long> score1, vector<long long> score2) ;
};

vector <int> PickingUp::fairPickingUp(vector<long long> score1, vector<long long> score2) {
		
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
		cout << "Testing PickingUp (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396873991;
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
		PickingUp _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long score1[] = {5,9};
				long long score2[] = {8,6};
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}
			case 1:
			{
				long long score1[] = {2,3,4,7};
				long long score2[] = {2,4,5,8};
				int __expected[] = {1, 2, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}
			case 2:
			{
				long long score1[] = {1,5,6,8};
				long long score2[] = {7,5,3,1};
				int __expected[] = {1, 2, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}
			case 3:
			{
				long long score1[] = {300,300,300,300};
				long long score2[] = {600,10,10,10};
				int __expected[] = {2, 1, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}
			case 4:
			{
				long long score1[] = {50,50,50,1};
				long long score2[] = {30,30,30,150};
				int __expected[] = {1, 2, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}
			/*case 5:
			{
				long long score1[] = ;
				long long score2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}*/
			/*case 6:
			{
				long long score1[] = ;
				long long score2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
			}*/
			/*case 7:
			{
				long long score1[] = ;
				long long score2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.fairPickingUp(vector<long long>(score1, score1+sizeof(score1)/sizeof(long long)), vector<long long>(score2, score2+sizeof(score2)/sizeof(long long))); break;
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
