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


class GogoXCake {
	public:
	string solve(vector <string> cake, vector <string> cutter) ;
};

bool vis[55][55];
vector<string> a,b;

bool check(int u, int v) {
    for (int i=u; i<u+b.size(); i++) {
        for (int j=v; j<v+b[0].length(); j++) {
            if (i>=a.size() || j>a[0].length()) return false;
            if (b[i-u][j-v]=='.') vis[i][j] = 1;
            if (b[i-u][j-v]=='.' && a[i][j]!=b[i-u][j-v]) return false;
        }
    }
    return true;
}

string GogoXCake::solve(vector <string> cake, vector <string> cutter) {

    a = cake;
    b = cutter;

	while (true) {
        bool done = 0;

        for (int i=0; i<a.size(); i++) {
            for (int j=0; j<a[0].length(); j++) if (cake[i][j]=='.' && !vis[i][j]) {
                done = 1;
                if (!check(i,j)) return "NO";
            }
        }

        if (!done) break;
	}

	return "YES";

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
		cout << "Testing GogoXCake (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384449573;
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
		GogoXCake _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cake[] = {"X.X"
				                ,"..."
				                ,"..."
				                ,"X.X"};
				string cutter[] = {".X"
				                  ,".."
				                  ,"X."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 1:
			{
				string cake[] = {"..XX"
				                ,"...X"
				                ,"X..."
				                ,"XX.."};
				string cutter[] = {".."
				                  ,".."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 2:
			{
				string cake[] = {"...X..."};
				string cutter[] = {"..."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 3:
			{
				string cake[] = {".X."
				                ,"X.X"
				                ,".X."};
				string cutter[] = {"."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 4:
			{
				string cake[] = {"XXXXXXX"
				                ,"X.....X"
				                ,"X.....X"
				                ,"X.....X"
				                ,"XXXXXXX"};
				string cutter[] = {".X."
				                  ,"XXX"
				                  ,".X."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 5:
			{
				string cake[] = {".."
				                ,"X."
				                ,".X"};
				string cutter[] = {".."
				                  ,".X"
				                  ,"X."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 6:
			{
				string cake[] = {"X.."
				                ,".XX"
				                ,".XX"};
				string cutter[] = {".XX"
				                  ,".XX"
				                  ,"X.."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			/*case 7:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
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
