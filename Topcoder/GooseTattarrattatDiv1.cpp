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


class GooseTattarrattatDiv1 {
	public:
	int getmin(string S) ;
};

int cnt[26];
int par[26];
bool vis[26];

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

int GooseTattarrattatDiv1::getmin(string S) {
    for (int i=0; i<26; i++) par[i] = i;
    for (int i=0; i<S.length()/2; i++) if (S[i]!=S[S.length()-i-1]) {
        get(S[i]-'a');
        get(S[S.length()-i-1]-'a');
        par[par[S[i]-'a']] = par[S[S.length()-i-1]-'a'];
    }
    for (int i=0; i<26; i++) get(i);
    int sol = 0;
    for (int i=0; i<S.length(); i++) cnt[S[i]-'a']++;
    for (int i=0; i<26; i++) if (par[i]!=i && !vis[i]) {
        vector<int> v;
        for (int j=0; j<26; j++) if (par[i]==par[j]) {
            vis[j] = 1;
            v.push_back(cnt[j]);
        }
        sort(v.begin(),v.end());
        for (int j=0; j<v.size()-1; j++) sol += v[j];
    }
    return sol;
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
		cout << "Testing GooseTattarrattatDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381065597;
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
		GooseTattarrattatDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "geese";
				_expected = 2;
				_received = _obj.getmin(S); break;
			}
			case 1:
			{
				string S = "tattarrattat";
				_expected = 0;
				_received = _obj.getmin(S); break;
			}
			case 2:
			{
				string S = "xyyzzzxxx";
				_expected = 2;
				_received = _obj.getmin(S); break;
			}
			case 3:
			{
				string S = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
				_expected = 11;
				_received = _obj.getmin(S); break;
			}
			case 4:
			{
				string S = "abaabb";
				_expected = 3;
				_received = _obj.getmin(S); break;
			}
			case 5:
			{
				string S = "smsozy";
				_expected = 3;
				_received = _obj.getmin(S); break;
			}
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getmin(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getmin(S); break;
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
