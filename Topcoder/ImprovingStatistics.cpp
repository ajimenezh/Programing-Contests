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


class ImprovingStatistics {
	public:
	int howManyGames(int played, int won) ;
};

int ImprovingStatistics::howManyGames(int played, int won) {
    int p = played;
    int w = won;

    if (p==w) return -1;
    if ((int)((long long)(100LL*w)/p)==99LL) return -1;
    long long x = (long long)((100LL*w)/p);
    int g = 100LL*w - (long long)p*(x+1);
    if (g%(x+1-100LL)!=0) g = (g/(x+1-100LL)) + 1LL;
    else g = (g/(x+1-100LL));
    return (int)g;
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
		cout << "Testing ImprovingStatistics (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388835744;
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
		ImprovingStatistics _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int played = 10;
				int won = 8;
				_expected = 1;
				_received = _obj.howManyGames(played, won); break;
			}
			case 1:
			{
				int played = 100;
				int won = 80;
				_expected = 6;
				_received = _obj.howManyGames(played, won); break;
			}
			case 2:
			{
				int played = 47;
				int won = 47;
				_expected = -1;
				_received = _obj.howManyGames(played, won); break;
			}
			case 3:
			{
				int played = 99000;
				int won = 0;
				_expected = 1000;
				_received = _obj.howManyGames(played, won); break;
			}
			case 4:
			{
				int played = 1000000000;
				int won = 470000000;
				_expected = 19230770;
				_received = _obj.howManyGames(played, won); break;
			}
			/*case 5:
			{
				int played = ;
				int won = ;
				_expected = ;
				_received = _obj.howManyGames(played, won); break;
			}*/
			/*case 6:
			{
				int played = ;
				int won = ;
				_expected = ;
				_received = _obj.howManyGames(played, won); break;
			}*/
			/*case 7:
			{
				int played = ;
				int won = ;
				_expected = ;
				_received = _obj.howManyGames(played, won); break;
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
