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


class DengklekMakingChains {
	public:
	int maxBeauty(vector <string> chains) ;
};

bool vis[51];

int DengklekMakingChains::maxBeauty(vector <string> chains) {
	int ans = 0;
    int n = chains.size();
    int mid = 0;

    for (int i=0; i<n; i++) if (chains[i][1]!='.') mid = max(mid, chains[i][1]-'0');

    for (int i=0; i<n; i++) {
        if (chains[i][0]!='.' && chains[i][1]!='.' && chains[i][2]!='.') {
            vis[i] = 1;
            ans += chains[i][0]-'0' + chains[i][1]-'0' + chains[i][2]-'0';
        }
    }

    int best = 0;
    for (int i=0; i<n; i++) if (!vis[i]) {
        int tmp = 0;
        int j = 0;
        while (j<3 && chains[i][j]!='.') {
            tmp += chains[i][j]-'0';
            j++;
        }
        for (int k=0; k<n; k++) if (!vis[k] && i!=k) {
            int tmp2 = 0;
            int j = 2;
            while (j>=0 && chains[k][j]!='.') {
                tmp2 += chains[k][j]-'0';
                j--;
            }
            best = max(best, tmp + tmp2);
        }
        best = max(best, tmp);
        int tmp2 = 0;
        j = 2;
        while (j>=0 && chains[i][j]!='.') {
            tmp2 += chains[i][j]-'0';
            j--;
        }
        best = max(best, tmp2);
    }

    return max(ans + best, mid);

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
		cout << "Testing DengklekMakingChains (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384433576;
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
		DengklekMakingChains _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chains[] = {".15", "7..", "402", "..3"};
				_expected = 19;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 1:
			{
				string chains[] = {"..1", "7..", "567", "24.", "8..", "234"};
				_expected = 36;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 2:
			{
				string chains[] = {"...", "..."};
				_expected = 0;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 3:
			{
				string chains[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
				_expected = 28;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 4:
			{
				string chains[] = {"..1", "3..", "2..", ".7."};
				_expected = 7;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 5:
			{
				string chains[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
				_expected = 58;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 6:
			{
				string chains[] = {"3.6"};
				_expected = 6;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			/*case 7:
			{
				string chains[] = ;
				_expected = ;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string chains[] = ;
				_expected = ;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
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
