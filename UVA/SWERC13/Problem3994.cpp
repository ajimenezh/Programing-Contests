#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

const int maxnode=100000+5;
const int maxedge=100000+5;
const int INF=1000000000;

int N,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],q[maxnode],work[maxnode];

void init(int _n, int _src, int _dest) {
    N = _n;
    src = _src;
    dest = _dest;
    for (int i=0; i<N; i++) head[i] = -1;
    nedge = 0;
}

void add_edge(int u, int v, int c1, int c2) {
    point[nedge] = v; capa[nedge]=c1; flow[nedge] = 0; next[nedge]=head[u]; head[u] = (nedge++);
    point[nedge] = u; capa[nedge]=c2; flow[nedge] = 0; next[nedge]=head[v]; head[v] = (nedge++);
}

bool bfs() {
    for (int i=0; i<N; i++) dist[i] = -1;
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
        for (int i = 0; i<N; i++) work[i] = head[i];

        f += dfs(src,INF);
    }
    return f;
}

int n,m;
int p, w;
int a[101][101];
int h[101][101];
int v[101][101];

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int c;
	cin>>c;
	int cs = 1;
	while (c--) {
		cin>>n>>m;
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) a[i][j] = 0;
		cin>>p;
		for (int i=0; i<p; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--; y--;
			a[x][y] = 1;
		}
		cin>>w;
		for (int i=0; i<w; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--; y--;
			a[x][y] = 2;
		}
		int k = -1;
		for (int i=0; i<n; i++) {
			k++;
			for (int j=0; j<m; j++) {
				if (a[i][j]!=2) h[i][j] = k;
				else if (j!=0 && a[i][j-1]!=2) k++;
			}
		}
		int t = ++k;
		k = -1;
		for (int i=0; i<m; i++) {
			k++;
			for (int j=0; j<n; j++) {
				if (a[j][i]!=2) v[j][i] = k;
				else if (j!=0 && a[j-1][i]!=2) k++;
			}
		}
		init(t+k+2,t+k,t+k+1);
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (a[i][j]==1) {
			add_edge(h[i][j],t+v[i][j],1,0);
		}
		for (int i=0; i<t; i++) add_edge(src,i,1,0);
		for (int i=0; i<k; i++) add_edge(t+i,dest,1,0);
		int ans = dinic();
		
		printf("%d\n", ans);
	}

    return 0;

}
