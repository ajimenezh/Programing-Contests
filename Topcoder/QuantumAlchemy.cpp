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


class QuantumAlchemy {
	public:
	int minSteps(string initial, vector <string> reactions) ;
};

map<char,string> next;
int cnt[28];

int QuantumAlchemy::minSteps(string initial, vector <string> reactions) {
    for (int i=0; i<initial.length(); i++) cnt[initial[i]-'A']++;
    for (int i=0; i<reactions.size(); i++) {
        char c = reactions[i][reactions[i].length()-1];
        string s = reactions[i].substr(0,reactions[i].length()-3);
        next[c] = s;
    }

    int tot = 0;
    if (cnt['X'-'A']>0) return 0;
    string cur = "X";
    while (true) {
        string tmp = "";
        bool done  = 0;
        for (int i=0; i<cur.length(); i++) {
            if (next.find(cur[i])!=next.end()) {
                string to = next[cur[i]];
                done = 1;
                tmp += to;
                tot++;
            }
            else return -1;
        }
        if (!done) {
            if (cur.length()>0) return -1;
            else break;
        }
        cur = "";
        for (int i=0; i<tmp.length(); i++) {
            if (cnt[tmp[i]-'A']>0) {
                cnt[tmp[i]-'A']--;
            }
            else cur += tmp[i];
        }
    }
    return tot;
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
		cout << "Testing QuantumAlchemy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390915128;
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
		QuantumAlchemy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "ABCDE";
				string reactions[] = {"ABC->F", "FE->X"};
				_expected = 2;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}
			case 1:
			{
				string initial = "AABBB";
				string reactions[] = {"BZ->Y", "ZY->X", "AB->Z"};
				_expected = 4;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}
			case 2:
			{
				string initial = "AAABB";
				string reactions[] = {"BZ->Y", "ZY->X", "AB->Z"};
				_expected = -1;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}
			case 3:
			{
				string initial = "AAXB";
				string reactions[] = {"BZ->Y", "ZY->X", "AB->Z"};
				_expected = 0;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}
			case 4:
			{
				string initial = "ABCDEFGHIJKLMNOPQRSTUVWYZABCDEFGHIJKLMNOPQRSTUVWYZ";
				string reactions[] = {"ABCE->Z", "RTYUIO->P", "QWER->T", "MN->B"};
				_expected = -1;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}
			/*case 5:
			{
				string initial = ;
				string reactions[] = ;
				_expected = ;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string initial = ;
				string reactions[] = ;
				_expected = ;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string initial = ;
				string reactions[] = ;
				_expected = ;
				_received = _obj.minSteps(initial, vector <string>(reactions, reactions+sizeof(reactions)/sizeof(string))); break;
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
