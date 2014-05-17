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


class Paintball {
	public:
	vector <string> getLeaderboard(vector <string> players, vector <string> messages) ;
};

string team[55];
int points[55];
map<string, int> id;
string name[55];
int cnt;
map<string ,bool> vis;

string tostr(int k) {
    if (k==0) return "0";
    string s;
    int n = abs(k);
    while (n>0) {
        s += char(n%10+'0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    if (k<0) s = '-' + s;
    return s;
}

vector <string> Paintball::getLeaderboard(vector <string> players, vector <string> messages) {
    for (int i=0; i<players.size(); i++) {
        stringstream ss(players[i]);
        string a, b;
        ss>>a>>b;
        if (id.find(b)==id.end()) {
            name[cnt] = a;
            id[a] = cnt++;
        }
        int k = id[a];
        team[k] = b;
    }
    for (int i=0; i<messages.size(); i++) {
        stringstream ss(messages[i]);
        string a,b,c;
        ss>>a>>b>>c;
        int t1 = id[a];
        int t2 = id[c];
        if (team[t1]==team[t2]) {
            points[t1]--;
        }
        else {
            points[t1]++;
            points[t2]--;
        }
    }
    vector<string> res;
    string str;
    vector<pair<int,string> > v;
    for (int i=0; i<cnt; i++) {
        if (vis[team[i]]==0) {
            int tot = 0;
            for (int j=0; j<cnt; j++) {
                if (team[i]==team[j]) tot += points[j];
            }
            vis[team[i]] = 1;
            v.push_back(make_pair(-tot, team[i]));
        }
    }
    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++) {
        str = "";
        str = v[i].second + " " + tostr(-v[i].first);
        res.push_back(str);
        vector<pair<int,string> > w;
        for (int j=0; j<cnt; j++) if (team[j]==v[i].second) {
            w.push_back(make_pair(-points[j], name[j]));
        }
        sort(w.begin(), w.end());
        for (int j=0; j<w.size(); j++) {
            str = "  ";
            str += w[j].second + " " + tostr(-w[j].first);
            res.push_back(str);
        }
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
		cout << "Testing Paintball (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394024129;
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
		Paintball _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string players[] = {"A RED", "B BLUE"};
				string messages[] = {"A SPLATTERED B"};
				string __expected[] = {"RED 1", "  A 1", "BLUE -1", "  B -1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			case 1:
			{
				string players[] = {"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"};
				string messages[] = {"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"};
				string __expected[] = {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", "  HOMER -1", "  MARGE -1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			case 2:
			{
				string players[] = {"TODD STRIKEFORCE",
				                    "BART OMEGA",
				                    "DATA STRIKEFORCE",
				                    "MILHOUSE OMEGA",
				                    "NELSON DISCOVERYCHANNEL",
				                    "MARTIN DISCOVERYCHANNEL"};
				string messages[] = {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"};
				string __expected[] = {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			case 3:
			{
				string players[] = {"DR COHO", "ST COHO", "PE COHO"};
				string messages[] = {"DR SPLATTERED ST",
				                     "ST SPLATTERED PE"};
				string __expected[] = {"COHO -2", "  PE 0", "  DR -1", "  ST -1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			case 4:
			{
				string players[] = {"A B", "AA AA", "AAA AAA"};
				string messages[] = {"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA",
				                    "AA SPLATTERED AAA", "AA SPLATTERED AAA"};
				string __expected[] = {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			/*case 5:
			{
				string players[] = ;
				string messages[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string players[] = ;
				string messages[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string players[] = ;
				string messages[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getLeaderboard(vector <string>(players, players+sizeof(players)/sizeof(string)), vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
