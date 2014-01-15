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


class LikelyWord {
	public:
	int likely(vector <string> dictionary, int k) ;
};

long long cnt[55];
int n;
long long dp[55][2][2];
int k;
long long p[11];
vector <string> s;

long long solve(int t, int i, int f1, int f2) {
    if (t==k) {
        if (f2 && s[i].length()<=t) return 0;
        if (f1 && s[i-1].length()<=t) return 0;
        return 1;
    }
    if (dp[t][f1][f2]>=0) return dp[t][f1][f2];

    long long tot = 0;
    if (f2 && s[i].length()<=t) return solve(t,i,f1,0);
    if (f1 && s[i-1].length()<=t) return solve(t,i,0,f2);
    if (f2) {
        if (f1) {
            if (s[i][t]==s[i-1][t] && f1) tot += solve(t+1,i,1,1);
            if (f1 && f2) {
                tot += solve(t+1,i,1,0);
                tot += solve(t+1,i,0,1);
                for (int c = s[i-1][t]+1; c<s[i][t]; c++) {
                    tot += p[k-t-1];
                }
            }
            else if (f1) {
                tot += solve(t+1,i,1,0);
                for (int c = s[i-1][t]+1; c<='z'; c++) {
                    tot += p[k-t-1];
                }
            }
            else if (f2) {
                tot += solve(t+1,i,0,1);
                for (int c = 'a'; c<s[i][t]; c++) {
                    tot += p[k-t-1];
                }
            }
            else tot += p[k-t];
        }
        else {
            tot += solve(t+1,i,0,1);
            for (int c = 'a'; c<s[i][t]; c++) {
                tot += p[k-t-1];
            }
        }
    }
    else {
        if (f1) {
            tot += solve(t+1,i,1,0);
            for (int c = s[i-1][t]+1; c<='z'; c++) {
                tot += p[k-t-1];
            }
        }
        else {
            tot = p[k-t];
        }
    }

    dp[t][f1][f2] = tot;
    return tot;
}

int LikelyWord::likely(vector <string> dictionary, int _k) {
    k = _k;
	n = dictionary.size();
	p[0] = 1;
	s = dictionary;
	for (int i=1; i<=k; i++) p[i] = p[i-1]*26;
    for (int i=1; i<n; i++) {
        for (int j=0; j<=k; j++) {
            dp[j][0][0] = -1;
            dp[j][1][0] = -1;
            dp[j][0][1] = -1;
            dp[j][1][1] = -1;
        }
        cnt[i] = solve(0, i, 1, 1);
    }
    for (int j=0; j<=k; j++) {
        dp[j][0][0] = -1;
        dp[j][1][0] = -1;
        dp[j][0][1] = -1;
        dp[j][1][1] = -1;
    }
    cnt[0] = solve(0,0,0,1);
    for (int j=0; j<=k; j++) {
        dp[j][0][0] = -1;
        dp[j][1][0] = -1;
        dp[j][0][1] = -1;
        dp[j][1][1] = -1;
    }
    cnt[n] = solve(0,n,1,0);
    //for (int i=0; i<=n; i++) cout<<cnt[i]<<endl;
    long long m = 0;
    for (int i=0; i<=n; i++) m = max(m, cnt[i]);
    int c = 0;
    for (int i=0; i<=n; i++) if (cnt[i]==m) c++;
    if (c>1) return -1;
    for (int i=0; i<=n; i++) if (cnt[i]==m) return i;
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
		cout << "Testing LikelyWord (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388663668;
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
		LikelyWord _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string dictionary[] = {"time","zoology"};
				int k = 1;
				_expected = 0;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
			}
			case 1:
			{
				string dictionary[] = {"az","ma","xz"};
				int k = 1;
				_expected = 1;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
			}
			case 2:
			{
				string dictionary[] = {"az","ma","xz"};
				int k = 2;
				_expected = 2;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
			}
			case 3:
			{
				string dictionary[] = {"a","m","y"};
				int k = 1;
				_expected = -1;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
			}
			/*case 4:
			{
				string dictionary[] = ;
				int k = ;
				_expected = ;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
			}*/
			/*case 5:
			{
				string dictionary[] = ;
				int k = ;
				_expected = ;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string dictionary[] = ;
				int k = ;
				_expected = ;
				_received = _obj.likely(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), k); break;
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
