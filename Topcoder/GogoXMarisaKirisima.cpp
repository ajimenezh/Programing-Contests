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


class GogoXMarisaKirisima {
	public:
	int solve(vector <string> choices) ;
};

vector<int> e[55];
bool vis[55][55];
int n;
int pre[55];
int dist[55];

bool bfs(int a, int b,bool flag) {
    for (int i=0; i<n; i++) dist[i] = -1;
    for (int i=0; i<n; i++) pre[i] = -1;

    queue<int> q;

    dist[a] = 0;
    q.push(a);

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (p==b) break;
        for (int i=0; i<e[p].size(); i++) {
            if (dist[e[p][i]] == -1) {
                dist[e[p][i]] = dist[p] + 1;
                pre[e[p][i]] = p;
                q.push(e[p][i]);
            }
        }
    }

    if (dist[b]==-1) return false;

    int p = b;

    if (flag==0) return true;
    while (pre[p]!=-1) {
        int t = pre[p];
        vis[t][p] = 1;
        p = t;
    }

    return true;
}

int GogoXMarisaKirisima::solve(vector <string> choices) {
	n = choices.size();
	int k = 0;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) vis[i][j] = 1;
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (choices[i][j]=='Y') {
            e[i].push_back(j);
            vis[i][j] = 0;
        }
	}

	int ans = 0;

	if (bfs(0,n-1,1)) ans++;
	else return 0;

	while (true) {
        bool done = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) if (!vis[i][j]) {
                if (bfs(0,i,0) && bfs(j,n-1,0)) {
                    done = 1;
                    vis[i][j] = 1;
                    ans ++;
                    bfs(0,i,1);
                    bfs(j,n-1,1);
                }
            }
        }

        if (!done) break;
	}

	return ans;

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
		cout << "Testing GogoXMarisaKirisima (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384451537;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GogoXMarisaKirisima _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string choices[] = {"NYN"
				                   ,"YNY"
				                   ,"NNN"};
				_expected = 2;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 1:
			{
				string choices[] = {"NNY"
				                   ,"YNY"
				                   ,"YNN"};
				_expected = 2;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 2:
			{
				string choices[] = {"NN"
				                   ,"NN"};
				_expected = 0;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 3:
			{
				string choices[] = {"NYYY"
				                   ,"NNNY"
				                   ,"NNNY"
				                   ,"NNNN"};
				_expected = 3;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			/*case 4:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
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
