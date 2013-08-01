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

#define INF 1000000005

int n;
vector<int> e[10010];
vector<int> w[10010];
int to[10010][2];
int dist[10010][2];
int d[10010];

void dfs(int u, int v) {
	
	dist[u][0] = -1;
	dist[u][1] = -1;
	
	for (int i=0; i<e[u].size(); i++) {
		int p = e[u][i];
		int c = w[u][i];
		if (p==v) continue;
		
		dfs(p,u);
		
		if (dist[u][0] < dist[p][0]+c) {
			
			dist[u][1] = dist[u][0];
			to[u][1] = to[u][0];
			
			dist[u][0] = dist[p][0]+c;
			to[u][0] = p;
		}
		else if (dist[u][1] < dist[p][0] + c) {
			dist[u][1] = dist[p][0]+c;
			to[u][1] = p;
		}
	}
	dist[u][0] = max(dist[u][0],0);
	dist[u][1] = max(dist[u][1],0);
}

void dfs2(int u, int v, int k) {
	if (v==-1) {
		;
	}
	else {
		if (u==to[v][0]) {
			if (dist[v][1]+k>dist[u][0]) {
				dist[u][0] = dist[v][1]+k;
				to[u][0] = -1;
			}
			else if (dist[v][1]+k>dist[u][1]) {
				dist[u][1] = dist[v][1]+k;
				to[u][1] = -1;
			}
		}
		else {
			if (dist[v][0]+k>dist[u][0]) {
				dist[u][0] = dist[v][0]+k;
				to[u][0] = -1;
			}
			else if (dist[v][1]+k>dist[u][0]) {
				dist[u][1] = dist[v][0]+k;
				to[u][1] = -1;
			}
		}
	}
	
	for (int i=0; i<e[u].size(); i++) {
		int p = e[u][i];
		int c = w[u][i];
		if (p==v) continue;
		
		dfs2(p,u,c);
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		e[a].push_back(i+1);
		w[a].push_back(b);
		e[i+1].push_back(a);
		w[i+1].push_back(b);
	}
	
	dfs(0,-1);
	dfs2(0,-1,0);
	
	for (int i=0; i<n; i++) printf("%d\n",dist[i][0]);

    return 0;

}
