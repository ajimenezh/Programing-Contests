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


class YankeeSwap {
	public:
	string sequenceOfSwaps(vector <string> preferences) ;
};

int dp[1<<20];
int pref[20][20];
int n;
int pre[1<<20];
int cur[21];

int solve(int mask) {
    if (mask==(1<<n)-1) return 0;
    if (dp[mask]>=0) return dp[mask];

    int tmp = 1000000;
    int k = n - 1 - __builtin_popcount(mask);

    int last = 0;
    if (((1<<k)&mask)==0) {
        int ans = 0;
        int t = -1;
        for (int j=0; j<n; j++) if (pref[k][j]==k) {
            ans = solve(mask | (1<<pref[k][j])) + j;
            t = j;
            last = t;
            break;
        }
        if (ans<tmp) {
            pre[mask] = t;
            tmp = ans;
        }
    }

    for (int i=0; i<n; i++) if (((1<<pref[k][i])&mask)==0) {
        int ans = i + solve(mask | (1<<pref[k][i]));
        if (ans<tmp) {
            pre[mask] = i;
            tmp = ans;
        }
    }

    dp[mask] = tmp;
    return tmp;
}

string YankeeSwap::sequenceOfSwaps(vector <string> preferences) {
    n = preferences.size();
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) pref[i][j] = preferences[i][j]-'A';
	}
	for (int i=0; i<(1<<n); i++) dp[i] = -1;
	for (int i=0; i<(1<<n); i++) pre[i] = -1;
	int res = solve(0); cout<<res<<endl;
	int mask = 0;
	vector<int> v;
	int i = n-1;
	while (mask!=(1<<n)-1) {
        int k = pre[mask];
        v.push_back(pref[i][k]);
        mask += (1<<pref[i][k]);
        i--;
	}
	for (int i=0; i<n; i++) cur[i] = n-1-i;
	string s;
	for (int i=0; i<n; i++) {
        if (cur[i]==v[i]) s += '-';
        else {
            for (int j=i+1; j<n; j++) if (v[j]==cur[i]) {
                s += char('a' + n-j-1);
                v[j] = v[i];
                break;
            }
        }
	}
	reverse(s.begin(), s.end());
	return s;
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
		cout << "Testing YankeeSwap (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394025560;
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
		YankeeSwap _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string preferences[] = {"BAC",
				                        "ACB",
				                        "BCA"};
				_expected = "-aa";
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 1:
			{
				string preferences[] = {"ABC",
				                        "BCA",
				                        "CAB"};
				_expected = "---";
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 2:
			{
				string preferences[] = {"AECDBF",
				                        "BAEDCF",
				                        "DEBACF",
				                        "BEDCAF",
				                        "CEABDF",
				                        "CBDEAF"};
				_expected = "-aac-a";
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			case 3:
			{
				string preferences[] = {"FDBHMAIELGKNJC",
				                        "KGMDJBAFLECNHI",
				                        "FKLJCADBEHNGIM",
				                        "JMHNICABFKEGDL",
				                        "IKFCDNJBLEGAMH",
				                        "FDNLJGCKHMBIEA",
				                        "MBKJAHDNIGECLF",
				                        "KNADLFGBJIMHCE",
				                        "AIFMGEBDHKJNCL",
				                        "MCDALIJGNKBFHE",
				                        "AJHMDLEIFKNCGB",
				                        "IJLKBCMDGNHFEA",
				                        "EAKFLJBDGMHCIN",
				                        "JEMANBDFGICHKL"};
				_expected = "--acacbdcahcja";
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}
			/*case 4:
			{
				string preferences[] = ;
				_expected = ;
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string preferences[] = ;
				_expected = ;
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string preferences[] = ;
				_expected = ;
				_received = _obj.sequenceOfSwaps(vector <string>(preferences, preferences+sizeof(preferences)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
