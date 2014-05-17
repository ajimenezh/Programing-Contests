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


class SharksDinner {
	public:
	int minSurvivors(vector <int> size, vector <int> speed, vector <int> intelligence) ;
};

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

int SharksDinner::minSurvivors(vector <int> size, vector <int> speed, vector <int> intelligence) {
	int m = speed.size();
	init(2*m+2, 2*m, 2*m+1);
	for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) if (i!=j) {
            if (size[i]>=size[j] && speed[i]>=speed[j] && intelligence[i]>=intelligence[j]) {
                if (size[i]==size[j] && speed[i]==speed[j] && intelligence[i]==intelligence[j]) {
                    if (i>j) add_edge(i, m+j, 1, 0);
                }
                else add_edge(i, m+j, 1, 0);
            }
        }
        add_edge(2*m, i, 2, 0);
        add_edge(i+m, 2*m+1, 1, 0);
	}
	return m - dinic();
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
		cout << "Testing SharksDinner (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393696797;
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
		SharksDinner _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int size[] = { 1, 4, 3 };
				int speed[] = { 2, 3, 1 };
				int intelligence[] = { 1, 5, 2 };
				_expected = 1;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
			}
			case 1:
			{
				int size[] = { 4, 10, 5, 8, 8 };
				int speed[] = { 5, 10, 7, 7, 10 };
				int intelligence[] = { 5, 8, 10, 7, 3 };
				_expected = 2;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
			}
			case 2:
			{
				int size[] = { 1, 2, 3, 4, 100 };
				int speed[] = { 4, 3, 2, 1, 100 };
				int intelligence[] = { 2, 4, 1, 3, 100 };
				_expected = 3;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
			}
			case 3:
			{
				int size[] = { 4, 4, 4, 4 };
				int speed[] = { 3, 3, 3, 3 };
				int intelligence[] = { 8, 8, 8, 8 };
				_expected = 1;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
			}
			/*case 4:
			{
				int size[] = ;
				int speed[] = ;
				int intelligence[] = ;
				_expected = ;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int size[] = ;
				int speed[] = ;
				int intelligence[] = ;
				_expected = ;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int size[] = ;
				int speed[] = ;
				int intelligence[] = ;
				_expected = ;
				_received = _obj.minSurvivors(vector <int>(size, size+sizeof(size)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(intelligence, intelligence+sizeof(intelligence)/sizeof(int))); break;
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
