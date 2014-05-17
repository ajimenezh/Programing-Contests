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


class VolleyballTournament {
	public:
	string reconstructResults(int wonMatches, int lostMatches, int wonSets, int lostSets) ;
};

string s;

bool check1(int k, int tot) {
    int cnt = 0;
    if (tot==0) {
        for (int i=0; i<k; i++) {
            s += "3-0";
            if (i!=k-1) s += ",";
        }
    }
    else {
        if (tot==1) {
            s += "3-1";
            if (k!=1) s += ",";
            for (int i=0; i<k-1; i++) {
                s += "3-0";
                if (i!=k-2) s += ",";
            }
        }
        else {
            if (k*2==tot) {
                 for (int i=0; i<k; i++) {
                    s += "3-2";
                    if (i!=k-1) s += ",";
                }
            }
            else if ((k-1)*2+1==tot) {
                s += "3-1";
                if (k!=1) s += ",";
                 for (int i=0; i<k-1; i++) {
                    s += "3-2";
                    if (i!=k-2) s += ",";
                }
            }
            else return false;
        }
    }
    return true;
}

bool check2(int k, int tot) {
    int cnt = 0;
    if (tot==0) {
        for (int i=0; i<k; i++) {
            s += "0-3";
            if (i!=k-1) s += ",";
        }
    }
    else {
        if (tot==1) {
            s += "1-3";
            if (k!=1) s += ",";
            for (int i=0; i<k-1; i++) {
                s += "0-3";
                if (i!=k-2) s += ",";
            }
        }
        else {
            if (k*2==tot) {
                 for (int i=0; i<k; i++) {
                    s += "2-3";
                    if (i!=k-1) s += ",";
                }
            }
            else if ((k-1)*2+1==tot) {
                s += "1-3";
                if (k!=1) s += ",";
                for (int i=0; i<k-1; i++) {
                    s += "2-3";
                    if (i!=k-2) s += ",";
                }
            }
            else return false;
        }
    }
    return true;
}

string VolleyballTournament::reconstructResults(int wonMatches, int lostMatches, int wonSets, int lostSets) {
    int w = wonMatches;
    int l = lostMatches;
    int ws = wonSets - 3*w;
    int ls = lostSets - 3*l;

    if (!check2(l,ws)) return "AMBIGUITY";
    if (w!=0) s += ",";
    if (!check1(w,ls)) return "AMBIGUITY";
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
		cout << "Testing VolleyballTournament (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390914069;
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
		VolleyballTournament _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int wonMatches = 3;
				int lostMatches = 3;
				int wonSets = 9;
				int lostSets = 9;
				_expected = "0-3,0-3,0-3,3-0,3-0,3-0";
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
			}
			case 1:
			{
				int wonMatches = 0;
				int lostMatches = 3;
				int wonSets = 6;
				int lostSets = 9;
				_expected = "2-3,2-3,2-3";
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
			}
			case 2:
			{
				int wonMatches = 3;
				int lostMatches = 0;
				int wonSets = 9;
				int lostSets = 3;
				_expected = "AMBIGUITY";
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
			}
			case 3:
			{
				int wonMatches = 1;
				int lostMatches = 1;
				int wonSets = 4;
				int lostSets = 4;
				_expected = "1-3,3-1";
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
			}
			/*case 4:
			{
				int wonMatches = ;
				int lostMatches = ;
				int wonSets = ;
				int lostSets = ;
				_expected = ;
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
			}*/
			/*case 5:
			{
				int wonMatches = ;
				int lostMatches = ;
				int wonSets = ;
				int lostSets = ;
				_expected = ;
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
			}*/
			/*case 6:
			{
				int wonMatches = ;
				int lostMatches = ;
				int wonSets = ;
				int lostSets = ;
				_expected = ;
				_received = _obj.reconstructResults(wonMatches, lostMatches, wonSets, lostSets); break;
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
