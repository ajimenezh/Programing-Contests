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
#define next NEXT

const int maxnode=250;
const int maxedge=2000;
const int INF=1000000000;

int n,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],q[maxnode],work[maxnode];

void init(int _n, int _src, int _dest) {
    n = _n;
    src = _src;
    dest = _dest;
    for (int i=0; i<n; i++) head[i] = -1;
    nedge = 0;
}

void add_edge(int u, int v, int c1, int c2) {
    point[nedge] = v; capa[nedge]=c1; flow[nedge] = 0; next[nedge]=head[u]; head[u] = (nedge++);
    point[nedge] = u; capa[nedge]=c2; flow[nedge] = 0; next[nedge]=head[v]; head[v] = (nedge++);
}

bool bfs() {
    for (int i=0; i<n; i++) dist[i] = -1;
    dist[src] = 0;
    int fn = 0;
    q[fn++]=src;
    int in=0;
    while (fn!=in)
    {
        for (int k=q[in], i=head[k]; i>=0; i=next[i])
        {
            if (flow[i]<capa[i] && dist[point[i]]<0)
            {
                dist[point[i]] = dist[k]+1;
                q[fn++] = point[i];
            }
        }
        in++;
    }
    return dist[dest]>=0;
}

int dfs(int x, int f) {
    if (!f) return 0;
    if (x == dest) return f;

    int res = 0;
    for (int i = work[x]; i>=0; i = next[i])
    {
        int v = point[i],temp;

        if (flow[i] < capa[i] && dist[v] == (dist[x] + 1))
        {
            temp=dfs(v,min(f,capa[i]-flow[i]));
            if (temp>0)
            {
                flow[i] += temp;
                flow[i^1] -= temp;
                res += temp;
                f -= temp;
                if (f==0) break;
            }
        }
    }
    return res;
}

int dinic() {
    int f = 0;
    while (bfs())
    {
        for (int i = 0; i<n; i++) work[i] = head[i];

        f += dfs(src,INF);
    }
    return f;
}


class PrinceOfPersia {
	public:
	int minObstacles(vector <string> maze) ;
};

int N,M;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool vis[11][11];
vector <string> maze;

int PrinceOfPersia::minObstacles(vector <string> _maze) {
    maze = _maze;
	N = maze.size();
	M = maze[0].length();
	int p = -1, s = -1;
	for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (maze[i][j]=='P') {
                if (p==-1) p = i*M + j;
                else s = i*M + j;
            }
        }
	}
    if (abs(p%M-s%M)==1 && abs(p/M-s/M)==0) return -1;
    if (abs(p%M-s%M)==0 && abs(p/M-s/M)==1) return -1;
	init(2*M*N, N*M+p, s);
	for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x<0 || x>=N || y<0 || y>=M) continue;
                if (maze[x][y]=='#') continue;

                add_edge(N*M+i*M+j, x*M+y, 1000000, 0);
            }
            add_edge(i*M+j, N*M+i*M+j, 1, 0);
        }
	}

	int flow = dinic();
	return flow;
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
		cout << "Testing PrinceOfPersia (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393761621;
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
		PrinceOfPersia _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {"P....",
				                 "...##",
				                 "##...",
				                 "....P"};
				_expected = 1;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 1:
			{
				string maze[] = {".....",
				                 ".P.P.",
				                 "....."};
				_expected = 3;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 2:
			{
				string maze[] = {".P",
				                 "P."};
				_expected = 0;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 3:
			{
				string maze[] = {"####",
				                 "#PP#",
				                 "####"};
				_expected = -1;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			/*case 4:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.minObstacles(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
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
