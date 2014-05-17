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


class LateForConcert {
	public:
	double bestRoute(vector <string> cityMap, int timeLeft, double speedingTicket, double redLight) ;
};

double dp[51][51][101][4];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int last[] = {2, 3, 0, 1};
int n,m;
int tim;
double ti;
double r;
vector<string> mapa;

double solve(int x, int y, int t, int l) {
    if (t<0) return 100000000.0;
    if (t==0) {
        if (mapa[x][y]=='C') return 0.0;
        else return 100000000.0;
    }
    if (mapa[x][y]=='C') return 100000000.0;
    if (dp[x][y][t][l]>=-0.5) return dp[x][y][t][l];

    double tmp = 100000000.0;
    for (int k=0; k<4; k++) if (k!=l) {
        int xx = x+dx[k];
        int yy = y+dy[k];
        if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
        if (mapa[xx][yy]=='.') {
            tmp = min(tmp, solve(xx, yy, t-1, last[k]));
        }
        if (mapa[xx][yy]=='T') {
            tmp = min(tmp, 0.7*r + solve(xx, yy, t-1, last[k]));
            tmp = min(tmp, solve(xx, yy, t-2, last[k]));
        }
        if (mapa[xx][yy]=='S') {
            tmp = min(tmp, ti + solve(xx, yy, t-1, last[k]));
        }
        if (mapa[xx][yy]=='C') {
            tmp = min(tmp, solve(xx, yy, t-1, last[k]));
        }
    }
    dp[x][y][t][l] = tmp;
    return tmp;
}

double LateForConcert::bestRoute(vector <string> cityMap, int timeLeft, double speedingTicket, double redLight) {
	ti = speedingTicket;
	r = redLight;
	tim = timeLeft;
	n = cityMap.size();
	m = cityMap[0].length();
	mapa = cityMap;

	int x,y;
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mapa[i][j]=='Y') {
                x = i;
                y = j;
                mapa[x][y] = '.';
                break;
            }
        }
	}

	for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int t=0; t<=tim; t++) for (int l=0; l<4; l++) dp[i][j][t][l] = -1.0;
	double res = min(solve(x,y,tim,0), solve(x,y,tim,1));
	if (res>=10000000) return -1;
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
		cout << "Testing LateForConcert (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394112052;
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
		LateForConcert _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cityMap[] = {"XXXXXXXX",
				                    "XY...S.X",
				                    "XXXXXX.X",
				                    "C..S.TT."};
				int timeLeft = 14;
				double speedingTicket = 60;
				double redLight = 93;
				_expected = 185.1;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}
			case 1:
			{
				string cityMap[] = {"XX..XX",
				                    "Y....C"};
				int timeLeft = 9;
				double speedingTicket = 52;
				double redLight = 874;
				_expected = 0.0;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}
			case 2:
			{
				string cityMap[] = {"YTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTC"};
				int timeLeft = 67;
				double speedingTicket = 123.4;
				double redLight = 42.192;
				_expected = 886.032;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}
			case 3:
			{
				string cityMap[] = {"C.......",
				                    "SXXSXXX.",
				                    "TSSTY..."};
				int timeLeft = 12;
				double speedingTicket = 1.23456789;
				double redLight = 123.456789;
				_expected = 0.0;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}
			case 4:
			{
				string cityMap[] = {"Y..",
				                    "...",
				                    "..C"};
				int timeLeft = 3;
				double speedingTicket = 1.0;
				double redLight = 1.0;
				_expected = -1.0;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}
			/*case 5:
			{
				string cityMap[] = ;
				int timeLeft = ;
				double speedingTicket = ;
				double redLight = ;
				_expected = ;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}*/
			/*case 6:
			{
				string cityMap[] = ;
				int timeLeft = ;
				double speedingTicket = ;
				double redLight = ;
				_expected = ;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}*/
			/*case 7:
			{
				string cityMap[] = ;
				int timeLeft = ;
				double speedingTicket = ;
				double redLight = ;
				_expected = ;
				_received = _obj.bestRoute(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), timeLeft, speedingTicket, redLight); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
