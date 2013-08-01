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

int n,m;

#define INF 1000000000

const int N = 400+5; // max nodes
const int M = 2*10000+5; // max edges

int nodes, nedge, src, dest;
int point[M], next[M], flow[M], capa[M], cost[M];
int head[N], dist[N], expand[N], prev[N], edge[N];
bool changed[N];
vector<int> vv[2];

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
	int t = 2;
	while (t--) {
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
		mflow ++;
		mcost += d*dist[dest];
		for (int k = dest; k != src; k = prev[k]) {
			vv[t].push_back(k);
			flow[edge[k]] += d;
			flow[edge[k]^1] -= d;
		}
   }
   return mp(mflow,mcost);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	init(n,0,n-1);
	
	for (int i=0; i<m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--; b--;
		addEdge(a,b,1,c);
		addEdge(b,a,1,c);
	}
	
	if (ford().first<2) {
		cout<<"No solution"<<endl;
		return 0;
	}
	
	reverse(vv[1].begin(),vv[1].end());
	cout<<"1 ";
	for (int i=0; i<vv[1].size(); i++) cout<<vv[1][i]+1<<" "; cout<<endl;
	
	reverse(vv[0].begin(),vv[0].end());
	cout<<"1 ";
	for (int i=0; i<vv[0].size(); i++) cout<<vv[0][i]+1<<" "; cout<<endl;

    return 0;

}
