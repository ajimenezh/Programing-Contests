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
vector<int> e[510];
int depth[510];
bool vis[510];
int ans;

void dfs(int u, int v) {
	if (v==-1) depth[u] = 1;
	else depth[u] = 1 + depth[v];
	vis[u] = 1; 
	
	for (int i=0; i<e[u].size();i++) {
		int p = e[u][i];
		if (p==v) continue;
		if (vis[p]) {
			if (depth[p]>depth[u]+1) ans = min(ans, depth[p] - depth[u] + 1);
			//if (depth[u]>depth[p]+1) ans = min(ans, depth[u] - depth[p] + 1);
		}
		else dfs(p,u);
	}
}

int q[510];
int dist[510];
int in,fn;
int pre[510];
void bfs(int p) {
	for (int i=0; i<n; i++) dist[i] = -1;
	in = 0; fn = 0;
	q[fn++] = p;
	dist[p] = 0;
	pre[p] = -1;
	while (in<fn) {
		p = q[in++];
		for (int i=0; i<e[p].size(); i++) {
			int u = e[p][i];
			if (u==pre[p]) continue;
			if (dist[u]!=-1) {
				ans = min(ans, dist[u] + dist[p] + 1);
			}
			else {
				dist[u] = dist[p] + 1;
				q[fn++] = u;
				pre[u] = p;
			}
		}
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	int k = 1;
	while (tt--) {
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; i++) e[i].clear();
		for (int i=0; i<m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		ans = 10000;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) vis[j] = 0;
			//dfs(i,-1);
			bfs(i);
		}
		if (ans<10000) printf("Case %d: %d\n",k++,ans);
		else printf("Case %d: impossible\n",k++);
	}

    return 0;

}
