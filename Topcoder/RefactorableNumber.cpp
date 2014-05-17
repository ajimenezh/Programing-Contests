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


class RefactorableNumber {
	public:
	int count(int low, int high) ;
};

bool isprime[2000010];
int next[2000010];
int cnt[2000010];

int RefactorableNumber::count(int low, int high) {
    for (int i=2; i<=2000000; i++) isprime[i] = 1;
    for (int i=2; i*i<=2000000; i++) if (isprime[i]) {
        for (int j=i*i; j<=2000000; j+=i) {
            isprime[j] = 0;
            next[j] = i;
        }
    }

    cnt[1] = 1;
    for (int i=2; i<=2000000; i++) {
        if (isprime[i]) cnt[i] = 2;
        else {
            int tot = 1;
            int k = i;
            while (k>1 && !isprime[k]) {
                int p = next[k];
                int c = 1;
                while (k%p==0) {
                    k /= p;
                    c++;
                }
                tot *= c;
            }
            if (k!=1) tot *= 2;
            cnt[i] = tot;
        }
    }
    for (int i=1; i<=2000000; i++) {
        if (i%cnt[i]==0) cnt[i] = 1;
        else cnt[i] = 0;
    }
    for (int i=1; i<=2000000; i++) cnt[i] = cnt[i-1] + cnt[i];

    return cnt[high] - cnt[low-1];
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
		cout << "Testing RefactorableNumber (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390829547;
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
		RefactorableNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int low = 1;
				int high = 10;
				_expected = 4;
				_received = _obj.count(low, high); break;
			}
			case 1:
			{
				int low = 10;
				int high = 100;
				_expected = 12;
				_received = _obj.count(low, high); break;
			}
			case 2:
			{
				int low = 25;
				int high = 35;
				_expected = 0;
				_received = _obj.count(low, high); break;
			}
			case 3:
			{
				int low = 123;
				int high = 4567;
				_expected = 315;
				_received = _obj.count(low, high); break;
			}
			/*case 4:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
			}*/
			/*case 5:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
			}*/
			/*case 6:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
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
