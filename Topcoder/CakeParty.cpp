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


class CakeParty {
	public:
	string makeMove(vector <int> pieces) ;
};

int f(int a, int b) {
    int c1 = 0;
    int aa = a;
    while (aa>0) {
        c1++;
        aa /= 10;
    }
    int c2 = 0;
    int bb = b;
    while (bb>0) {
        c2++;
        bb /= 10;
    }
    if (c1==c2) return a;
    stringstream ss;
    ss<<a;
    string s1 = ss.str();
    int k = 1;
    for (int i=0; i<c1; i++) k *= 10;
    stringstream ss2;
    ss2<<k;
    string s2 = ss.str();
    if (s2<s1) return k;
    else return a;
}

string CakeParty::makeMove(vector <int> pieces) {

	int sum = 0;
	int n = pieces.size();
	for (int i=0; i<n; i++) sum += pieces[i];
	int m = 0;
	for (int i=0; i<n; i++) m = max(m, pieces[i]);

	if (sum==0) return "CAKE 0 PIECES 1";

    string str;
    int p;
	for (int i=0; i<n; i++) if (pieces[i]==m) {
        stringstream ss;
        ss<<i;
        string s = ss.str();
        if (str=="") {
            str = s;
            p = i;
        }
        else {
            if (s<str) {
                p = i;
                str = s;
            }
        }
	}

    if (n==1) {
        stringstream ss;
        ss<<"CAKE 0 PIECES ";
        ss<<pieces[0];
        return ss.str();
    }

    m = 0;
    for (int i=0; i<n; i++) if (i!=p) m = max(m, pieces[i]);
    int m2 = 0;
    for (int i=0; i<n; i++) if (pieces[i]!=m) m2 = max(m2, pieces[i]);
    int cnt = 0;
    for (int i=0; i<n; i++) if (pieces[i]==m) cnt++;

    if (m==pieces[p]) {
        stringstream ss;
        ss<<"CAKE ";
        ss<<p;
        ss<<" PIECES ";
        ss<<1;
        return ss.str();
    }
    else {
        if (cnt%2==1) {
            stringstream ss;
            ss<<"CAKE ";
            ss<<p;
            ss<<" PIECES ";
            ss<<pieces[p]-m;
            return ss.str();
        }
        else {
            stringstream ss;
            ss<<"CAKE ";
            ss<<p;
            ss<<" PIECES ";
            ss<<f(pieces[p]-m+1, pieces[p]);
            return ss.str();
        }
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
		cout << "Testing CakeParty (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388837823;
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
		CakeParty _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int pieces[] = {47};
				_expected = "CAKE 0 PIECES 47";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			case 1:
			{
				int pieces[] = {3,3};
				_expected = "CAKE 0 PIECES 1";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			case 2:
			{
				int pieces[] = {3,5};
				_expected = "CAKE 1 PIECES 2";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			case 3:
			{
				int pieces[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = "CAKE 0 PIECES 1";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			case 4:
			{
				int pieces[] = {3,3,112};
				_expected = "CAKE 2 PIECES 110";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			case 5:
			{
				int pieces[] = {3,3,1};
				_expected = "CAKE 0 PIECES 1";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			case 6:
			{
				int pieces[] = {4,7,4,7,4,7,4,7,47,47,47,47};
				_expected = "CAKE 10 PIECES 1";
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}
			/*case 7:
			{
				int pieces[] = ;
				_expected = ;
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int pieces[] = ;
				_expected = ;
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int pieces[] = ;
				_expected = ;
				_received = _obj.makeMove(vector <int>(pieces, pieces+sizeof(pieces)/sizeof(int))); break;
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
