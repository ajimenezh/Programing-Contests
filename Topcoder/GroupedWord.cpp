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


class GroupedWord {
	public:
	string restore(vector <string> parts) ;
};

void f(multiset<string> &all, string s) {
    rep(it, all) {
        string w = (*it);
        if (w[0]==s[s.length()-1]) {
            all.erase(w);
            w = s + w;
            f(all, w);
            return;
        }
        if (w[w.length()-1]==s[0]) {
            all.erase(w);
            w = w + s;
            f(all, w);
            return;
        }
    }
    set<char> cnt;
    for (int i=0; i<s.length(); i++) cnt.insert(s[i]);
    if (cnt.size()==1) {
        rep(it, all) {
            string w = *it;
            for (int j=0; j<w.size(); j++) {
                if (w[j]==s[0]) {
                    all.erase(w);
                    w = w.substr(0,j+1) + s + w.substr(j+1, w.length()-(j+1));
                    all.insert(w);
                    return;
                }
            }
        }
    }
    all.insert(s);
}

bool check(string s) {
    for (int i=0; i<s.length(); i++) {
        int j = i-1;
        while (j>=0 && s[j]==s[i]) j--;
        while (j>=0) if (s[j--]==s[i]) return false;
    }
    return true;
}

string GroupedWord::restore(vector <string> parts) {
    multiset<string> all;
    for (int i=0; i<parts.size(); i++) {
        string s = parts[i];
        f(all, s);

        //cout<<i<<endl;
        //rep(it, all) cout<<*it<<endl;
    }
    if (all.size()>1) {
        rep(it, all) {
            if (!check(*it)) return "IMPOSSIBLE";
        }
        set<char> found;
        rep(it, all) {
            string s = *it;
            for (int i=0; i<s.length(); i++) {
                if (found.find(s[i])!=found.end()) return "IMPOSSIBLE";
            }
            for (int i=0; i<s.length(); i++) {
                found.insert(s[i]);
            }
        }
        return "MANY";
    }
    else {
        if (check(*all.begin())) return *all.begin();
        else return "IMPOSSIBLE";
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
		cout << "Testing GroupedWord (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396961648;
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
		GroupedWord _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string parts[] = {"aaa", "a", "aa"};
				_expected = "aaaaaa";
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}
			case 1:
			{
				string parts[] = {"ab", "bba"};
				_expected = "IMPOSSIBLE";
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}
			case 2:
			{
				string parts[] = {"te", "st"};
				_expected = "stte";
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}
			case 3:
			{
				string parts[] = {"te", "s", "t"};
				_expected = "MANY";
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}
			case 4:
			{
				string parts[] = {"orr", "rd", "woo", "www"};
				_expected = "wwwwooorrrd";
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}
			case 5:
			{
				string parts[] = {"de", "de"};
				_expected = "aa";
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}
			/*case 6:
			{
				string parts[] = ;
				_expected = ;
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string parts[] = ;
				_expected = ;
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string parts[] = ;
				_expected = ;
				_received = _obj.restore(vector <string>(parts, parts+sizeof(parts)/sizeof(string))); break;
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
