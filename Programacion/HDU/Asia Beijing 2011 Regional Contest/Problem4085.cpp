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

#define INF 1000000000

const int N = 50+5; // max nodes
const int M = 10000+5; // max edges

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
int d[51][51];
int id[51];
int dp[1<<11][51];

int steiner(int n, int m) {
	if (m<2) return 0;
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			dp[1<<i][j] = d[id[i]][j];
		}
	}
	for (int i=1; i<(1<<m); i++) if (((i-1)&i)!=0) {
		for (int j=0; j<n; j++) {
			dp[i][j] = INF;
			for (int k=(i-1)&i; k>0; k = (k-1)&i) {
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i^k][j]);
			}
		}
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+d[k][j]);
			}
		}
	}

	return dp[(1<<m)-1][id[0]];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	while (tt--) {
		scanf("%d%d%d",&n,&m,&k);
		
		init(n+2,n,n+1);
		
		for (int i=0; i<k; i++) addEdge(src,i,1,0);
		for (int i=n-k; i<n; i++) addEdge(i,dest,1,0);
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) d[i][j] = INF;
			d[i][i] = 0;
		}
		
		for (int i=0; i<m; i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--; b--;
			addEdge(a,b,1000,c);
			addEdge(b,a,1000,c);
			d[a][b] = min(d[a][b],c);
			d[b][a] = min(d[b][a],c);
		}
		
		pair<int,int> p = ford();
		
		if (p.first!=k) {
			cout<<"No solution"<<endl;
		}
		else {
			for (int i=0; i<k; i++) id[i] = i; 
			for (int i=0; i<k; i++) id[k+i] = n-i-1;
			
			int tmp = steiner(n,2*k);
			
			cout<<tmp<<endl;
		}
	}

    return 0;

}
