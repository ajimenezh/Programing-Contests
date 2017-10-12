
#line 3 "ApocalypseEasy.cpp"
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

class MaxFlow {
public:
    struct edge {
        edge(int a, int b, int c) : to(a), cap(b), rev(c) {}
        int to;
        int cap;
        int rev;
    };
    static const int MV = 10000;
    vector<edge> e[MV];
    bool vis[MV];

    void add_edge(int from, int to, int c) {
        e[from].push_back(edge(to, c, e[to].size()));
        e[to].push_back(edge(from, 0, e[from].size()-1));
    }

    int dfs(int p, int dst, int flow) {
        if (p == dst) return flow;
        vis[p] = 1;

        int tmp;

        for (int i=0; i<e[p].size(); i++) if (!vis[e[p][i].to] && e[p][i].cap > 0) {

            tmp = dfs(e[p][i].to, dst, min(flow, e[p][i].cap));

            if (tmp > 0) {
                e[p][i].cap -= tmp;
                e[e[p][i].to][e[p][i].rev].cap += tmp;
                return tmp;
            }

        }

        return 0;

    }

    int max_flow(int src, int dst) {

        int flow = 0;
        int tmp;

        while (true) {

            for (int i=0; i<MV; i++) vis[i] = false;

            tmp = dfs(src, dst, 1000000000);

            if (tmp == 0) {
                return flow;
            }

            flow += tmp;

        }

        return 0;
    }
};

int d[55][55];
vector<int> e[55];

class ApocalypseEasy {
	public:
	int maximalSurvival(vector <int> p, vector <int> position, int t) {

        int n = p.size() + 1;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) if (i != j) d[i][j] = 1000000000;
        }

        for (int i=0; i<p.size(); i++) {
            e[i+1].push_back(p[i]);
            e[p[i]].push_back(i+1);
            d[i+1][p[i]] = d[p[i]][i+1] = 1;
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }

        MaxFlow mf;

        for (int i=0; i<position.size(); i++) {
            mf.add_edge(2*n, position[i], 1);

        }

        for (int i=0; i<n; i++) {
            bool found = false;
            for (int j=0; j<position.size(); j++) if (position[j] == i) found = true;
            if (!found) {
                mf.add_edge(n+i, 2*n+1, 1);
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) if (i != j && d[i][j] <= t) {
                mf.add_edge(i, j+n, 1);
            }
        }

        return mf.max_flow(2*n, 2*n+1);

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
		cout << "Testing ApocalypseEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507823998;
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
		ApocalypseEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,2};
				int position[] = {2,3};
				int t = 1;
				_expected = 1;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 1:
			{
				int p[] = {0,1,2};
				int position[] = {2,3};
				int t = 2;
				_expected = 2;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 2:
			{
				int p[] = {0,0,0,1,2,3};
				int position[] = {1,2,3};
				int t = 1;
				_expected = 3;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 3:
			{
				int p[] = {0,1,2,3,4,5,6,7,8,9};
				int position[] = {0,1,2,3,4,5,6};
				int t = 50;
				_expected = 4;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 4:
			{
				int p[] = {0,0,0,0,0};
				int position[] = {0,1,2};
				int t = 2;
				_expected = 3;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 5:
			{
				int p[] = {0};
				int position[] = {0,1};
				int t = 1;
				_expected = 0;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			/*case 6:
			{
				int p[] = ;
				int position[] = ;
				int t = ;
				_expected = ;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int position[] = ;
				int t = ;
				_expected = ;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}*/
			/*case 8:
			{
				int p[] = ;
				int position[] = ;
				int t = ;
				_expected = ;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
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

// END CUT HERE
