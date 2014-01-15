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


class RotatingBot {
	public:
	int minArea(vector <int> moves) ;
};

vector<pair<int,int> > v;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool table[100][100];

int RotatingBot::minArea(vector <int> moves) {
    int x = 0, y = 0;
    int n = moves.size();
    v.push_back(make_pair(0,0));
    for (int i=0; i<moves.size(); i++) {
        x += dx[i%4]*moves[i];
        y += dy[i%4]*moves[i];
        v.push_back(make_pair(x,y));
    }
    int m = 10;
    for (int i=0; i<n+1; i++) m = min(m, v[i].first);
    for (int i=0; i<n+1; i++) v[i].first += -m;
    m = 10;
    for (int i=0; i<n+1; i++) m = min(m, v[i].second);
    for (int i=0; i<n+1; i++) v[i].second += -m;
    int w = 0, h = 0;
    for (int i=0; i<n+1; i++) {
        w = max(w, v[i].first);
        h = max(h, v[i].second);
    }

    x = v[0].first;
    y = v[0].second;
    table[x][y] = 1;
    for (int i=0; i<moves.size(); i++) {
        for (int j=0; j<moves[i]; j++) {
            x += dx[i%4];
            y += dy[i%4];
            if (table[x][y]) return -1;
            table[x][y] = 1;
        }
        if (i!=moves.size()-1) {
            if (i%4==0 && x!=w && !table[x+dx[i%4]][y+dy[i%4]]) return -1;
            if (i%4==1 && y!=0 && !table[x+dx[i%4]][y+dy[i%4]]) return -1;
            if (i%4==2 && x!=0 && !table[x+dx[i%4]][y+dy[i%4]]) return -1;
            if (i%4==3 && y!=h && !table[x+dx[i%4]][y+dy[i%4]]) return -1;
        }
    }

    return (w+1)*(h+1);
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
		cout << "Testing RotatingBot (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383501819;
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
		RotatingBot _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int moves[] = {15};
				_expected = 16;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 1:
			{
				int moves[] = {3,10};
				_expected = 44;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 2:
			{
				int moves[] = {1,1,1,1};
				_expected = -1;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 3:
			{
				int moves[] = {9,5,11,10,11,4,10};
				_expected = 132;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 4:
			{
				int moves[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
				_expected = 420;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 5:
			{
				int moves[] = {8,6,6,1};
				_expected = -1;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 6:
			{
				int moves[] = {8,6,6};
				_expected = 63;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 7:
			{
				int moves[] = {5,4,5,3,3};
				_expected = 30;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			/*case 8:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
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
