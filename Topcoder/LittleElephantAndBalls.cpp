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


class LittleElephantAndBalls {
	public:
	int getNumber(string S) ;
};


int LittleElephantAndBalls::getNumber(string S) {
    int n = S.length();

    string s;
    s += S[0];

    int res = 0;
    for (int i=1; i<n; i++) {
        int l[51], r[51];
        set<char> all;
        for (int j=0; j<s.size(); j++) {
            l[j] = all.size();
            all.insert(s[j]);
        }
        l[s.length()] = all.size();
        all.clear();
        for (int j=s.size()-1; j>=0; j--) {
            r[j+1] = all.size();
            all.insert(s[j]);
        }
        r[0] = all.size();

        int p = -1;
        int best = 0;
        for (int j=0; j<s.length()+1; j++) {
            if (l[j]+r[j]>best) {
                best = l[j]+r[j];
                p = j;
            }
        }
        if (p==s.length()) s += S[i];
        else if (p==0) s = S[i] + s;
        else {
            s = s.substr(0,p) + S[i] + s.substr(p,s.length()-p);
        }
        res += best;
    }

    return res;
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
		cout << "Testing LittleElephantAndBalls (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380279611;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LittleElephantAndBalls _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "RGB";
				_expected = 3;
				_received = _obj.getNumber(S); break;
			}
			case 1:
			{
				string S = "RGGRBBB";
				_expected = 21;
				_received = _obj.getNumber(S); break;
			}
			case 2:
			{
				string S = "RRRGBRR";
				_expected = 16;
				_received = _obj.getNumber(S); break;
			}
			case 3:
			{
				string S = "RRRR";
				_expected = 5;
				_received = _obj.getNumber(S); break;
			}
			case 4:
			{
				string S = "GGRRRBRGR";
				_expected = 29;
				_received = _obj.getNumber(S); break;
			}
			case 5:
			{
				string S = "G";
				_expected = 0;
				_received = _obj.getNumber(S); break;
			}
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
			}*/
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
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
