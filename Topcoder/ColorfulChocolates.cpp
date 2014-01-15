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


class ColorfulChocolates {
	public:
	int maximumSpread(string chocolates, int maxSwaps) ;
};

int cnt[30];

int ColorfulChocolates::maximumSpread(string chocolates, int maxSwaps) {
	int ans = 0;
	string s = chocolates;
	int m = maxSwaps;
	for (int i=0; i<n; i++) cnt[s[i]-'A']++;
	for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            for (int k=0; k<26; k++) if (cnt[k]>=j-i+1) {
                string str = s;
                for (int t=1; t<n; t++) {
                    if (t+j<n) {
                        if (i-t<0 )
                    }
                }
            }
        }
	}
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
		cout << "Testing ColorfulChocolates (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383490854;
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
		ColorfulChocolates _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chocolates = "ABCDCBC";
				int maxSwaps = 1;
				_expected = 2;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 1:
			{
				string chocolates = "ABCDCBC";
				int maxSwaps = 2;
				_expected = 3;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 2:
			{
				string chocolates = "ABBABABBA";
				int maxSwaps = 3;
				_expected = 4;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 3:
			{
				string chocolates = "ABBABABBA";
				int maxSwaps = 4;
				_expected = 5;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 4:
			{
				string chocolates = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
				int maxSwaps = 77;
				_expected = 5;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			/*case 5:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}*/
			/*case 6:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}*/
			/*case 7:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
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
