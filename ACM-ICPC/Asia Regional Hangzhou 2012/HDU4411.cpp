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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define INF 1000000

const int N = 10000+5; // max nodes
const int M = 100000+5; // max edges

int nodes, nedge, src, dest;
int point[M], next[M], flow[M], capa[M], cost[M];
int head[N], dist[N], expand[N], prev[N], edge[N];
bool changed[N];

void init (int _nodes, int _src, int _dest) {
	nodes = _nodes;
	src = _src;
	dest = _dest;
	nedge = 0;
	for (int i = 0; i<nodes; i++) head[i] = -1;
}

void addEdge (int u, int v, int c, int w) {
	point[nedge]=v, capa[nedge]=c, cost[nedge]=w,  flow[nedge]=0, next[nedge]=head[u], head[u]=(nedge++);
	point[nedge]=u, capa[nedge]=0, cost[nedge]=-w, flow[nedge]=0, next[nedge]=head[v], head[v]=(nedge++);
}

pii ford() {
	int mflow = 0, mcost = 0;
	while (1) {
		for (int i=0; i<nodes; i++) dist[i] = INF, prev[i] = -1, changed[i] = 0;
		dist[src] = 0;
		changed[src] = 1;
		expand[src] = INF;
		while (1) {
			bool ok = 1;
			for (int i=0; i<nodes; i++) if (changed[i]) {
				changed[i] = 0;
				for (int k = head[i]; k>=0; k=next[k]) {
					if (flow[k] < capa[k] && dist[i]+cost[k] < dist[point[k]]) {
						dist[point[k]] = dist[i]+cost[k];
						changed[point[k]] = 1;
						prev[point[k]] = i;
						edge[point[k]] = k;
						expand[point[k]] = min(expand[i], capa[k]-flow[k]);
						ok = 0;
					}
				}
			}
			if (ok) break;
		}
		if (prev[dest] < 0) break;
		int d = expand[dest];
		mflow += d;
		mcost += d*dist[dest];
		for (int k = dest; k != src; k = prev[k]) {
			flow[edge[k]] += d;
			flow[edge[k]^1] -= d;
		}
   }
   return mp(mflow,mcost);
}

int n,m,k;
int d[110][110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d%d",&n,&m,&k) && n) {
        n++;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) d[i][j] = INF;
        for (int i=0; i<m; i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            d[x][y] = min(d[x][y],z);
            d[y][x] = min(d[y][x],z);
        }
        for (int t=0; t<n; t++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    d[i][j] = min(d[i][t] + d[t][j], d[i][j]);
                }
            }
        }

        init(2*n+2,2*n,2*n+1);

        addEdge(src,0,k,0);
        addEdge(0,dest,k,0);

        for (int i=1; i<n; i++) {
            addEdge(0,i,1,d[0][i]);
            addEdge(i+n,dest,1,d[i][0]);
            addEdge(i,i+n,1,-INF);
        }

        for (int i=1; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                addEdge(i+n,j,1,d[i][j]);
                //addEdge(j+n,i,1,d[i][j]);
            }
        }

        pair<int,int> p = ford();

        cout<<p.second + INF*(n-1)<<"\n";
    }

    return 0;

}
