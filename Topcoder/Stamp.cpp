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


class Stamp {
	public:
	int getMinimumCost(string desiredColor, int stampCost, int pushCost) ;
};

string s;
int c,w;
int l;


int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	int ans = 1000000000;
	s = desiredColor;
	c = stampCost;
	w = pushCost;
	for (l=1; l<=desiredColor.length(); l++) {
        s = desiredColor;
        int last = 0;
        int tmp = 0;
        for (int j=0; j<desiredColor.length(); j++) {
            int p = -1;
            char col = '*';
            for (int k=last; k<=j; k++) {
                set<char> all;
                for (int t=k; t<k+l; t++) if (s[t]!='*') all.insert(s[t]);
                if (all.size()<2) {
                    p = max(p, k);
                    if (all.size()>0) col = *all.begin();
                }
            }
            if (p==-1) {
                tmp = 1000000000;
                continue;
            }
            for (int k=p; k<p+l; k++) s[k] = col;
            last = p+1;
            tmp += w;
            j = p+l-1;
        }
        ans = min(ans, tmp + c*l);
	}
	return ans;
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
		cout << "Testing Stamp (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383259219;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Stamp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string desiredColor = "RRGGBB";
				int stampCost = 1;
				int pushCost = 1;
				_expected = 5;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 1:
			{
				string desiredColor = "R**GB*";
				int stampCost = 1;
				int pushCost = 1;
				_expected = 5;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 2:
			{
				string desiredColor = "BRRB";
				int stampCost = 2;
				int pushCost = 7;
				_expected = 30;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 3:
			{
				string desiredColor = "R*RR*GG";
				int stampCost = 10;
				int pushCost = 58;
				_expected = 204;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 4:
			{
				string desiredColor = "*B**B**B*BB*G*BBB**B**B*";
				int stampCost = 5;
				int pushCost = 2;
				_expected = 33;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 5:
			{
				string desiredColor = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
				int stampCost = 7;
				int pushCost = 1;
				_expected = 30;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			/*case 6:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}*/
			/*case 7:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}*/
			/*case 8:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
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
