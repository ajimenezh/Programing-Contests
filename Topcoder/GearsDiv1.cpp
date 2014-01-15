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

const int maxnode=100000+5;
const int maxedge=100000+5;
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

class GearsDiv1 {
	public:
	int getmin(string color, vector <string> graph) ;
};

int GearsDiv1::getmin(string color, vector <string> graph) {
    int m = 1000000;
    char col[] = {'R','G','B'};
    for (int i=0; i<3; i++) {
        int t = color.size();
        init(t+2,t,t+1);
        for (int j=0; j<t; j++) if (color[j]!=col[i]) {
            for (int k=j+1; k<t; k++) if (color[k]!=col[i] && graph[j][k]=='Y') {
                if (color[j]==col[(i+1)%3]) add_edge(j,k,1,0);
                if (color[j]==col[(i-1+3)%3]) add_edge(k,j,1,0);
            }
        }
        for (int j=0; j<t; j++) {
            if (color[j]==col[(i+1)%3]) add_edge(t,j,1,0);
            if (color[j]==col[(i-1+3)%3]) add_edge(j,t+1,1,0);
        }
        m = min(m, dinic());
    }
    return m;
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
		cout << "Testing GearsDiv1 (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381066345;
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
		GearsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string color = "RGB";
				string graph[] = {"NYY","YNY","YYN"};
				_expected = 1;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				string color = "RGBR";
				string graph[] = {"NNNN","NNNN","NNNN","NNNN"};
				_expected = 0;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				string color = "RGBR";
				string graph[] = {"NYNN","YNYN","NYNY","NNYN"};
				_expected = 1;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				string color = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG";
				string graph[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
				                  "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
				                  "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
				                  "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
				                  "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
				                  "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
				                  "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
				                  "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
				                  "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
				                  "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
				                  "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
				                  "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
				                  "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
				                  "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
				                  "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
				                  "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
				                  "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
				                  "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
				                  "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
				                  "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
				                  "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
				                  "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
				                  "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
				                  "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
				                  "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
				                  "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
				                  "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
				                  "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
				                  "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
				                  "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"};
				_expected = 3;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			/*case 4:
			{
				string color = ;
				string graph[] = ;
				_expected = ;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string color = ;
				string graph[] = ;
				_expected = ;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string color = ;
				string graph[] = ;
				_expected = ;
				_received = _obj.getmin(color, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
