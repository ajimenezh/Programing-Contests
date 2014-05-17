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


class Pathfinding {
	public:
	int getDirections(int x, int y) ;
};

pair<int,int> p[36];
set<int> vx,vy;
int dist[36][36];
int m;

int Pathfinding::getDirections(int x, int y) {

    vx.insert(0);
    vx.insert(1);
    vx.insert(-1);
    vx.insert(x);
    vx.insert(x+1);
    vx.insert(x-1);

    vy.insert(0);
    vy.insert(1);
    vy.insert(-1);
    vy.insert(y);
    vy.insert(y+1);
    vy.insert(y-1);

    rep(it, vx) {
        rep(it2, vy) {
            p[m++] = make_pair(*it, *it2);
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            if (p[i]==p[j]) dist[i][j] = 0;
            else {
                if (p[i].first==p[j].first && p[i].second!=p[j].second) {
                    if (p[i].second<p[j].second) {
                        if (p[i].first%2==0) dist[i][j] = p[j].second - p[i].second;
                        else dist[i][j] = 1000000000;
                    }
                    else {
                        if (p[i].first%2!=0) dist[i][j] = -p[j].second + p[i].second;
                        else dist[i][j] = 1000000000;
                    }
                }
                else if (p[i].first!=p[j].first && p[i].second==p[j].second) {
                    if (p[i].first<p[j].first) {
                        if (p[i].second%2==0) dist[i][j] = p[j].first - p[i].first;
                        else dist[i][j] = 1000000000;
                    }
                    else {
                        if (p[i].second%2!=0) dist[i][j] = -p[j].first + p[i].first;
                        else dist[i][j] = 1000000000;
                    }
                }
                else {
                    dist[i][j] = 1000000000;
                }
            }

        }
    }

    for (int k=0; k<m; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                if (dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    int u,v;
    for (int i=0; i<m; i++) {
        if (p[i]==make_pair(0,0)) u = i;
        if (p[i]==make_pair(x,y)) v = i;
    }
    return dist[u][v];
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
		cout << "Testing Pathfinding (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390999116;
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
		Pathfinding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 0;
				int y = -4;
				_expected = 8;
				_received = _obj.getDirections(x, y); break;
			}
			case 1:
			{
				int x = 5;
				int y = -4;
				_expected = 9;
				_received = _obj.getDirections(x, y); break;
			}
			case 2:
			{
				int x = 5;
				int y = 4;
				_expected = 9;
				_received = _obj.getDirections(x, y); break;
			}
			case 3:
			{
				int x = -1;
				int y = -4;
				_expected = 7;
				_received = _obj.getDirections(x, y); break;
			}
			case 4:
			{
				int x = 0;
				int y = 0;
				_expected = 0;
				_received = _obj.getDirections(x, y); break;
			}
			/*case 5:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.getDirections(x, y); break;
			}*/
			/*case 6:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.getDirections(x, y); break;
			}*/
			/*case 7:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.getDirections(x, y); break;
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
