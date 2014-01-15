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


class NewArenaPassword {
	public:
	int minChange(string oldPassword, int K) ;
};

bool vis[51];
string s;
int n;
int cnt[26];
int K;

void dfs(int i) {
    vis[i] = 1;
    cnt[s[i]-'a']++;
    int t = n-1-(K-i-1);
    if (t<K && t!=i) {
        dfs(t);
    }
    else {
        vis[t] = 1;
        cnt[s[t]-'a']++;
    }
    return;
}

int NewArenaPassword::minChange(string oldPassword, int _K) {
	n = oldPassword.length();
	s = oldPassword;
	K = _K;
	int ans = 0;
	for (int i=0; i<K; i++) if (!vis[i]) {
        for (int j=0; j<26; j++) cnt[j] = 0;
        dfs(i);
        int m = 0;
        int sum = 0;
        for (int j=0; j<26; j++) {
            sum += cnt[j];
            m = max(m,cnt[j]);
        }
        ans += sum-m;
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
		cout << "Testing NewArenaPassword (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381417238;
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
		NewArenaPassword _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string oldPassword = "topcoderopen";
				int K = 5;
				_expected = 3;
				_received = _obj.minChange(oldPassword, K); break;
			}
			case 1:
			{
				string oldPassword = "puyopuyo";
				int K = 4;
				_expected = 0;
				_received = _obj.minChange(oldPassword, K); break;
			}
			case 2:
			{
				string oldPassword = "loool";
				int K = 3;
				_expected = 1;
				_received = _obj.minChange(oldPassword, K); break;
			}
			case 3:
			{
				string oldPassword = "arena";
				int K = 5;
				_expected = 0;
				_received = _obj.minChange(oldPassword, K); break;
			}
			case 4:
			{
				string oldPassword = "amavckdkz";
				int K = 7;
				_expected = 5;
				_received = _obj.minChange(oldPassword, K); break;
			}
			/*case 5:
			{
				string oldPassword = ;
				int K = ;
				_expected = ;
				_received = _obj.minChange(oldPassword, K); break;
			}*/
			/*case 6:
			{
				string oldPassword = ;
				int K = ;
				_expected = ;
				_received = _obj.minChange(oldPassword, K); break;
			}*/
			/*case 7:
			{
				string oldPassword = ;
				int K = ;
				_expected = ;
				_received = _obj.minChange(oldPassword, K); break;
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
