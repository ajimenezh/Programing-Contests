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


class FindingSquareInTable {
	public:
	int findMaximalSquare(vector <string> table) ;
};

set<long long> all;

void check(long long t, long long &res) {
    if (all.find(t)==all.end()) return;
    if (t>res) res = t;
    return;
}

int FindingSquareInTable::findMaximalSquare(vector <string> table) {
	for (int i=0; i<100000; i++) all.insert((long long)i*i);

	long long res = -1;
	for (int i=0; i<table.size(); i++) {
        for (int j=0; j<table[0].length(); j++) {
            check(table[i][j]-'0', res);
            for (int k=-i; k+i<table.size(); k++) {
                for (int p=-j; p+j<table[0].length(); p++) {
                    if (k==0 && p==0) continue;
                    int x = i;
                    int y = j;
                    long long t = 0;
                    while (x<table.size() && y<table[0].length()) {
                        t = t*10 + table[x][y]-'0';
                        check(t, res);
                        x += k;
                        y += p;
                    }
                }
            }
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
		cout << "Testing FindingSquareInTable (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397044978;
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
		FindingSquareInTable _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"0"};
				_expected = 0;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"00000",
				                  "00000",
				                  "00200",
				                  "00000",
				                  "00000"};
				_expected = 0;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"3791178",
				                  "1283252",
				                  "4103617",
				                  "8233494",
				                  "8725572",
				                  "2937261"};
				_expected = 320356;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"135791357",
				                  "357913579",
				                  "579135791",
				                  "791357913",
				                  "913579135"};
				_expected = 9;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 4:
			{
				string table[] = {"553333733",
				                  "775337775",
				                  "777537775",
				                  "777357333",
				                  "755553557",
				                  "355533335",
				                  "373773573",
				                  "337373777",
				                  "775557777"};
				_expected = -1;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 5:
			{
				string table[] = {"257240281",
				                  "197510846",
				                  "014345401",
				                  "035562575",
				                  "974935632",
				                  "865865933",
				                  "684684987",
				                  "768934659",
				                  "287493867"};
				_expected = 95481;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 6:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
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
