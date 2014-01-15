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


class SPartition {
	public:
	long long getCount(string s) ;
};

long long SPartition::getCount(string s) {
	vector<string> vs;
	int n = s.size();
	int p = 0;
	for (int i=1; i<n; i++) {
        if (s.substr(p,i-p)==s.substr(i,i-p) && i!=p) {
            vs.push_back(s.substr(p,i-p));
            p = i+(i-p);
        }
	}
	for (int i=0; i<vs.size(); i++) cout<<vs[i]<<endl;

	return 0;
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
		cout << "Testing SPartition (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384455521;
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
		SPartition _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "oxox";
				_expected = 2LL;
				_received = _obj.getCount(s); break;
			}
			case 1:
			{
				string s = "oooxxx";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 2:
			{
				string s = "xoxxox";
				_expected = 4LL;
				_received = _obj.getCount(s); break;
			}
			case 3:
			{
				string s = "xo";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 4:
			{
				string s = "ooooxoox";
				_expected = 8LL;
				_received = _obj.getCount(s); break;
			}
			case 5:
			{
				string s = "ooxxoxox";
				_expected = 8LL;
				_received = _obj.getCount(s); break;
			}
			/*case 6:
			{
				string s = ;
				_expected = LL;
				_received = _obj.getCount(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = LL;
				_received = _obj.getCount(s); break;
			}*/
			/*case 8:
			{
				string s = ;
				_expected = LL;
				_received = _obj.getCount(s); break;
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
