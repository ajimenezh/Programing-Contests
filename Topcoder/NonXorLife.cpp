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


class NonXorLife {
	public:
	int countAliveCells(vector <string> field, int K) ;
};

int NonXorLife::countAliveCells(vector <string> field, int K) {
		
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
		cout << "Testing NonXorLife (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384084546;
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
		NonXorLife _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {"oo"
				                 ,"o."};
				int K = 3;
				_expected = 36;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
			}
			case 1:
			{
				string field[] = {".."
				                 ,".."};
				int K = 23;
				_expected = 0;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
			}
			case 2:
			{
				string field[] = {"o"};
				int K = 1000;
				_expected = 2002001;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
			}
			case 3:
			{
				string field[] = {"o.oo.ooo"
				                 ,"o.o.o.oo"
				                 ,"ooo.oooo"
				                 ,"o.o..o.o"
				                 ,"o.o..o.o"
				                 ,"o..oooo."
				                 ,"..o.o.oo"
				                 ,"oo.ooo.o"};
				int K = 1234;
				_expected = 3082590;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
			}
			/*case 4:
			{
				string field[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
			}*/
			/*case 5:
			{
				string field[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
			}*/
			/*case 6:
			{
				string field[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countAliveCells(vector <string>(field, field+sizeof(field)/sizeof(string)), K); break;
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
