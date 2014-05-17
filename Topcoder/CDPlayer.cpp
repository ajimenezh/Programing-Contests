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


class CDPlayer {
	public:
	int isRandom(vector <string> songlist, int n) ;
};

string s;
int cnt[26];

int CDPlayer::isRandom(vector <string> songlist, int n) {
	for (int i=0; i<songlist.size(); i++) {
        s += songlist[i];
	}

	for (int i=0; i<min(n, (int)s.length()); i++) {
        int j = i;
        bool bad = 0;
        while (j<s.length()) {
            int k = j;
            for (int p=0; p<n; p++) cnt[p] = 0;
            while (k-j<n && k<s.length()) {
                cnt[s[k]-'A']++;
                if (cnt[s[k]-'A']>1) bad = 1;
                k++;
            }
            if (bad) break;
            j+=n;
        }
        for (int p=0; p<n; p++) cnt[p] = 0;
        for (int j=0; j<i; j++) {
            cnt[s[j]-'A']++;
            if (cnt[s[j]-'A']>1) bad = 1;
        }
        if (!bad) return i;
	}
	return -1;
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
		cout << "Testing CDPlayer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389876471;
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
		CDPlayer _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string songlist[] = {"BBAC"};
				int n = 3;
				_expected = 1;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			case 1:
			{
				string songlist[] = {"BACAB",
				                     "BCA"};
				int n = 3;
				_expected = 2;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			case 2:
			{
				string songlist[] = {"AAACBACBACBACBACBACBACB"};
				int n = 3;
				_expected = -1;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			case 3:
			{
				string songlist[] = {"ABCDEABDECBAECDEDACB"};
				int n = 5;
				_expected = 0;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			case 4:
			{
				string songlist[] = {"ABCABCABCABCABCABCABC",
				                     "ABCABCABCABCABCABCABC"};
				int n = 22;
				_expected = -1;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			case 5:
			{
				string songlist[] = {"AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA",
				                     "AAAAAAAAAAAAAAAA"};
				int n = 1;
				_expected = 0;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			case 6:
			{
				string songlist[] = {"ADEF"};
				int n = 12;
				_expected = 0;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}
			/*case 7:
			{
				string songlist[] = ;
				int n = ;
				_expected = ;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}*/
			/*case 8:
			{
				string songlist[] = ;
				int n = ;
				_expected = ;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
			}*/
			/*case 9:
			{
				string songlist[] = ;
				int n = ;
				_expected = ;
				_received = _obj.isRandom(vector <string>(songlist, songlist+sizeof(songlist)/sizeof(string)), n); break;
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
