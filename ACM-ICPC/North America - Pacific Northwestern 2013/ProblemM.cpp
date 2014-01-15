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

int m,n,A,B;
int a[12], b[12];
int c[12][12];

#define INF 10000000

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

void addedge (int u, int v, int c, int w) {
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

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        scanf("%d%d%d%d",&m,&n,&A,&B);
        for (int i=0; i<n; i++) cin>>a[i];
        for (int j=0; j<n; j++) cin>>b[j];

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) cin>>c[i][j];
        }

        int ans = 0;

        init(2*n+m+2,2*n+m,2*n+m+1);

        for (int i=0; i<n; i++) addedge(src,i,a[i],0);
        for (int i=0; i<n; i++) addedge(i+n,dest,b[i],0);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                addedge(i,2*n+j,INF,A*c[j][i]);
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                addedge(2*n+i,n+j,INF,B*c[i][j]);
            }
        }

        pair<int,int> p = ford();

        cout<<p.second<<endl;

    }

    return 0;

}
