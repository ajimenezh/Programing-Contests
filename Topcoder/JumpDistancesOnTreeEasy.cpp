
#line 3 "JumpDistancesOnTreeEasy.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

vector<int> e[55];
vector<int> e2[55];
vector<pair<int,int> > used[55];
bool vis[55];
int q[55];
int n;
int depth[55];
int par[55];
int rk[55];
int sz[55];

void dfs(int p) {
    for (int i=0; i<e[p].size(); i++) {

        depth[e[p][i]] = depth[p] + 1;
        dfs(e[p][i]);

    }

}

int find(int x) {
    if (x == par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rk[x] > rk[y]) {
        par[y] = x;
        sz[x]++;
    }
    else if (rk[x] < rk[y]) {
        par[x] = y;
        sz[y]++;
    }
    else {
        par[y] = x;
        sz[x]++;
        rk[x]++;
    }
}

class JumpDistancesOnTreeEasy {
	public:
	string isPossible(vector <int> p, vector <int> S) {

		n = p.size()+1;
		for (int i=0; i<p.size(); i++) {
            e[p[i]].push_back(i+1);
		}

		dfs(0);

		for (int i=0; i<n; i++) {
            par[i] = i;
            rk[i] = 0;
            sz[i] = 0;
		}

        bool good = true;
		for (int i=0; i<S.size(); i++) {

            bool found = false;
            for (int x=0; x<n; x++) {
                for (int y=x+1; y<n; y++) {

                    int d = 0;

                    int xx = x;
                    int yy = y;

                    while (xx != yy) {

                        if (depth[xx] > depth[yy]) {
                            d++;
                            xx = p[xx-1];
                        }
                        else if (depth[xx] < depth[yy]) {
                            d++;
                            yy = p[yy-1];
                        }
                        else {
                            xx = p[xx-1];
                            yy = p[yy-1];
                            d += 2;
                        }

                    }

                    if (S[i] == d) {

                        found = true;

                        xx = x;
                        yy = y;

                        while (xx != yy) {

                            if (depth[xx] > depth[yy]) {
                                merge(xx, p[xx-1]);
                                xx = p[xx-1];
                            }
                            else if (depth[xx] < depth[yy]) {
                                merge(yy, p[yy-1]);
                                yy = p[yy-1];
                            }
                            else {
                                merge(xx, p[xx-1]);
                                xx = p[xx-1];
                                merge(yy, p[yy-1]);
                                yy = p[yy-1];
                            }

                        }

                        e2[x].push_back(y);
                        e2[y].push_back(x);

                        used[i].push_back(make_pair(x, y));

                    }

                }
            }

            if (!found) {
                good = false;
            }
vector<int> e[55];
		}

		int in = 0;
		int fn = 0;
		q[fn++] = 0;
		while (in < fn) {

            int p = q[in++];
            vis[p] = 1;

            for (int i=0; i<e2[p].size(); i++) if (!vis[e2[p][i]]) {
                q[fn++] = e2[p][i];
            }

		}

		for (int i=0; i<S.size(); i++) {
            bool found = false;
            for (int j=0; j<used[i].size(); j++) {
                if (vis[used[i][j].first] && vis[used[i][j].second]) {
                    found = true;
                }
            }
            if (!found) {
                good = false;
            }
		}

		for (int i=0; i<n; i++) {
            if (sz[find(i)] != 1 && find(i) != find(0)) {
                good = false;
            }
		}

		return good ? "Possible" : "Impossible";
	}
};

// BEGIN CUT HERE
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
		cout << "Testing JumpDistancesOnTreeEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507980344;
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
		JumpDistancesOnTreeEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,1,0,4,4};
				int S[] = {2,4};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1,1,0,4,4};
				int S[] = {1,2,3,4,5};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0,1,1,0,4,4};
				int S[] = {3,4};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,1,2,3,4,0,6,7,8,9};
				int S[] = {2,4,6,8,10};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {0};
				int S[] = {1};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			/*case 5:
			{
				int p[] = ;
				int S[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int S[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int S[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(S, S+sizeof(S)/sizeof(int))); break;
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

// END CUT HERE
