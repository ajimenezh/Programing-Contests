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


class SkiResorts {
	public:
	long long minCost(vector <string> road, vector <int> altitude) ;
};

long long dist[51][51];
int d[51];
int n;
vector<int> e[51];
priority_queue<pair<long long,int> > q;

long long SkiResorts::minCost(vector <string> road, vector <int> altitude) {
	n = road.size();
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (road[i][j]=='Y') e[i].push_back(j);
	}
	for (int i=0; i<n; i++) d[i] = altitude[i];

	for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j] = 1LL<<60;

    for (int i=0; i<n; i++) {
        dist[0][i] = abs(d[i]-d[0]);
         q.push(make_pair(-dist[i][0],i));
    }
    while (!q.empty()) {
        int p = q.top().second;
        int x = p/n;
        int y = p%n;
        q.pop();
        if (x==n-1) {
            return dist[x][y];
        }
        for (int i=0; i<e[x].size(); i++) {
            int u = e[x][i];
            for (int k=0; k<n; k++) {
                if (d[k]<=d[y]) {
                    if (dist[u][k]>dist[x][y]+abs(d[k]-d[u])) {
                        dist[u][k]=dist[x][y]+abs(d[k]-d[u]);
                        q.push(make_pair(-dist[u][k],u*n+k));
                    }
                }
            }
        }
    }
    return -1;
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
		cout << "Testing SkiResorts (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381414658;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SkiResorts _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string road[] = {"NYN",
				                 "YNY",
				                 "NYN"};
				int altitude[] = {30, 20, 10};
				_expected = 0LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 1:
			{
				string road[] = {"NY",
				                 "YN"};
				int altitude[] = {10, 20};
				_expected = 10LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 2:
			{
				string road[] = {"NYN",
				                 "YNN",
				                 "NNN"};
				int altitude[] = {573, 573, 573};
				_expected = -1LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 3:
			{
				string road[] = {"NNYNNYYYNN",
				                 "NNNNYNYNNN",
				                 "YNNNNYYNNN",
				                 "NNNNNNYNYY",
				                 "NYNNNNNNYY",
				                 "YNYNNNNYNN",
				                 "YYYYNNNYNN",
				                 "YNNNNYYNNN",
				                 "NNNYYNNNNN",
				                 "NNNYYNNNNN"};
				int altitude[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
				_expected = 12LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			/*case 4:
			{
				string road[] = ;
				int altitude[] = ;
				_expected = LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string road[] = ;
				int altitude[] = ;
				_expected = LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string road[] = ;
				int altitude[] = ;
				_expected = LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
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
