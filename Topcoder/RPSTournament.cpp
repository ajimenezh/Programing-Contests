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


class RPSTournament {
	public:
	int greatestSeed(int rounds, int C) ;
};

bool used[1<<16];
int lst[1<<16];
int n;
int last[1<<16];

bool check(int m) {
    for (int i=0; i<(1<<n); i++) used[i] = 0;
    int p = 0;
    lst[p++] = m;
    used[m] = 1;
    for (int i=0; i<n; i++, p <<= 1) {
        int pos = 0, opponent = 0;
        for (int j=0; j<p; j++) {
            opponent = max(opponent, last[lst[j]]);
            while (opponent<(1<<n) && used[opponent]) opponent++;
            if (opponent>=(1<<n)) return false;
            lst[p+pos++] = opponent;
            used[opponent] = 1;
        }
        sort(lst, lst+pos+p);
    }
    return true;
}


int RPSTournament::greatestSeed(int rounds, int C) {
    n = rounds;
    int m = 0;
    for (int i=0; i<(1<<n); i++) {
        int k = i+1;
        k = (int)sqrt(C*k);
        last[i] = max(i-k, 0);
    }
    int lo = 0;
    int hi = (1<<n)-1;
    while (lo<hi) {
        int mi = (lo+hi+1)/2;
        if (check(mi)) {
            lo = mi;
        }
        else hi = mi-1;
    }
    return lo+1;
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
		cout << "Testing RPSTournament (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388924851;
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
		RPSTournament _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int rounds = 2;
				int C = 0;
				_expected = 1;
				_received = _obj.greatestSeed(rounds, C); break;
			}
			case 1:
			{
				int rounds = 3;
				int C = 1;
				_expected = 6;
				_received = _obj.greatestSeed(rounds, C); break;
			}
			case 2:
			{
				int rounds = 4;
				int C = 1;
				_expected = 9;
				_received = _obj.greatestSeed(rounds, C); break;
			}
			case 3:
			{
				int rounds = 7;
				int C = 3;
				_expected = 50;
				_received = _obj.greatestSeed(rounds, C); break;
			}
			case 4:
			{
				int rounds = 15;
				int C = 180;
				_expected = 9755;
				_received = _obj.greatestSeed(rounds, C); break;
			}
			/*case 5:
			{
				int rounds = ;
				int C = ;
				_expected = ;
				_received = _obj.greatestSeed(rounds, C); break;
			}*/
			/*case 6:
			{
				int rounds = ;
				int C = ;
				_expected = ;
				_received = _obj.greatestSeed(rounds, C); break;
			}*/
			/*case 7:
			{
				int rounds = ;
				int C = ;
				_expected = ;
				_received = _obj.greatestSeed(rounds, C); break;
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
