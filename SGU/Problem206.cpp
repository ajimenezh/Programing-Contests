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

#define MAXN 65
#define MAXM 810

#define INF 1000000000

int n, m;
int a[MAXN], b[MAXN], w[MAXM];
int to[MAXM], id[MAXM], next[MAXM], head[MAXM];
int nedge;

void addedge(int u, int v, int c, int ind) {
	to[nedge] = v; id[nedge] = ind; next[nedge] = head[u]; head[u] = nedge++;
	to[nedge] = u; id[nedge] = ind; next[nedge] = head[v]; head[v] = nedge++;
}

int depth[MAXN], par[MAXN];

void dfs(int u, int v) {
	if (v==-1) depth[u] = 1;
	else depth[u] = depth[v]+1;
	
	for (int i=head[u]; i!=-1; i = next[i]) {
		if (to[i]!=v) {
			par[to[i]] = i^1;
			dfs(to[i],u); 
		}
	}
}
		
int graph[MAXM][MAXM];
int fx[MAXM], fy[MAXM], visx[MAXM], visy[MAXM];
int match[MAXM];
int s[MAXM];
int N;

bool find(int i) {
	if (visx[i]) return false;
	visx[i] = true;
	for (int j=0; j<N; j++) {
		if (fx[i]+fy[j]==graph[i][j]) {
			visy[j] = 1;
			if (match[j]==-1 || find(match[j])) {
				match[j] = i;
				return true;
			}
		}
		else {
			s[j] = min(s[j], fx[i]+fy[j]-graph[i][j]);
		}
	}
	return false;
}

void kuhn(int _N) {
	N = _N;
	for (int i=0; i<N; i++) {
		fx[i] = -INF;
		for (int j=0; j<N; j++) fx[i] = max(fx[i], graph[i][j]);
		fy[i] = 0;
	}
	for (int i=0; i<N; i++) match[i] = -1;
	for (int i=0; i<N; i++) {
		while (true) {
			for (int j=0; j<N; j++) visx[j] = 0;
			for (int j=0; j<N; j++) visy[j] = 0;
			for (int j=0; j<N; j++) s[j] = INF;
			if (find(i)) break;
			int delta = INF;
			for (int j=0; j<N; j++) {
				if (!visy[j]) {
					delta = min(delta, s[j]);
				}
			}
			for (int j=0; j<N; j++) {
				if (visx[j]) {
					fx[j] -= delta;
				}
				if (visy[j]) {
					fy[j] += delta;
				}
			}
		}
	}
	for (int i=0; i<n-1; i++) {
		cout<<w[i]-fx[i]<<endl;
	}
	for (int i=0; i<m-n+1; i++) {
		cout<<w[n-1+i]+fy[i]<<endl;
	}
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) head[i] = -1;
	for (int i=0; i<n-1; i++) {
		scanf("%d%d%d",a+i,b+i,w+i);
		a[i]--; b[i]--;
		addedge(a[i],b[i],w[i], i);
	}
	for (int i=n-1; i<m; i++) {
		scanf("%d%d%d",a+i,b+i,w+i);
		a[i]--; b[i]--;
	}
	
	dfs(0,-1);
	
	for (int i=n-1; i<m; i++) {
		int u = a[i];
		int v = b[i];
		while (u!=v) {
			if (depth[u]<depth[v]) {
				u ^= v;
				v ^= u;
				u ^= v;
			}
			int p = id[par[u]];
			if (w[p] >= w[i]) {
				graph[p][i-n+1] = w[p] - w[i];
			}
			u = to[par[u]];
		}
	}
	
	//for (int i=0; i<n-1; i++) {
	//	for (int j=0; j<(m-n+1); j++) cout<<graph[i][j]<<" ";
	//	cout<<endl;
	//}
	
	kuhn(max(n-1, m-n+1));

    return 0;

}
