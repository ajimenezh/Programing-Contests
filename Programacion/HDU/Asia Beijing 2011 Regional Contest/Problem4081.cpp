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

int n, m;
int x[1010], y[1010];
int p[1010];
pair<double,pair<int,int> > ed[1000010];
int par[1010];
int rank[1010];
double best[1010][1010];
vector<int> e[1010];

void init() {
	for (int i=0; i<n; i++) par[i] = i;
	for (int i=0; i<n; i++) rank[i] = 0;
}

int get(int a) {
	if (a==par[a]) return a;
	par[a] = get(par[a]);
	return par[a];
}

bool merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (rank[a]>rank[b]) {
		par[a] = b;
		rank[b]++;
	}
	else {
		par[b] = a;
		rank[a]++;
	}
	return true;
}

double sqr(int a) {
	return (double)a*(double)a;
}

double dist(int i, int j) {
	return sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]));
}

void dfs(int u, int v,double cur, int src) {
	for (int i=0; i<e[u].size(); i++) {
		int p = e[u][i];
		if (v==p) continue;
		dfs(p,u,max(cur,dist(u,p)),src);
	}
	best[src][u] = cur;
	best[u][src] = cur;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	scanf("%d",&tt);
	while (tt--) {
		scanf("%d",&n);
		for (int i=0; i<n; i++) scanf("%d%d%d",x+i,y+i,p+i);
		m = n*(n-1)/2;
		int k = 0;
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
			ed[k++] = make_pair(dist(i,j),make_pair(i,j));
		}
		sort(ed,ed+m);
		double len = 0;
		init();
		for (int i=0; i<n; i++) e[i].clear();
		for (int i=0; i<m; i++) {
			if (merge(ed[i].second.first,ed[i].second.second)) {
				len += ed[i].first;
				e[ed[i].second.first].push_back(ed[i].second.second);
				e[ed[i].second.second].push_back(ed[i].second.first);
			}
		}
		for (int i=0; i<n; i++) dfs(i,-1,0,i);
		
		//for (int i=0; i<n; i++) {
		//	for (int j=0; j<n; j++) cout<<best[i][j]<<" "; cout<<endl;
		//}
		
		double ans = 0;
		
		for (int i=0; i<m; i++) {
			double a = (double)(p[ed[i].second.first] + p[ed[i].second.second]);
			double b = len - best[ed[i].second.first][ed[i].second.second];
			//cout<<a<<" "<<b<<endl;
			double p = a/b;
			if (ans<p) ans = p;
		}
		
		printf("%.2f\n",ans);
	}

    return 0;

}
