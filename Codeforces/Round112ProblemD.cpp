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

#define MAXN 100010

int n;
vector<int> e[MAXN];
pair<int,int> edge[MAXN];
int depth[MAXN];
int where[MAXN];
int k;
int root;
int next[MAXN];
int to[MAXN];

void dfs(int p, int q, int t,int r) {
	depth[p] = t;
	where[p] = r;
	if (r==0) {
		for (int i=0; i<(int)e[p].size(); i++) {
			dfs(e[p][i],p,t+1,++k);
			to[k] = e[p][i];
		}
	}
	else {
		next[p] = -1;
		for (int i=0; i<(int)e[p].size(); i++) if (e[p][i]!=q) {
			dfs(e[p][i],p,t+1,k);
			next[p] = e[p][i];
		}
	}
}

struct bit{
	vector<int> v;
	map<int,int> id;
	int N;
	void init(int c) {
		N = 0;
		while (c!=-1) {
			N++;
			id[c] = N;
			c = next[c];
		}
		v = vector<int> (N+1,0);
	}
	void update(int t, int x) {
		for (int i=id[t]; i<=N; i += i & -i) v[i] += x;
	}
	int get(int t) {
		int y = 0;
		for (int i=id[t]; i>=1; i -= i & -i) y += v[i];
		return y;
	}
}bt[MAXN];

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
		

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
		edge[i] = make_pair(a,b);
	}
	
	int p = -1;
	for (int i=0; i<n; i++) {
		if (p==-1 && e[i].size()==1) p = i;
		else if (e[i].size()>2) p = i;
	}
	
	root = p; ;
	dfs(p,-1,0,0);
	
	for (int i=1; i<=k; i++) bt[i].init(to[i]);
	
	int m;
	cin>>m;
	
	for (int i=0; i<m; i++) {
		int typ;
		scanf("%d",&typ);
		if (typ==1) {
			int ind;
			scanf("%d",&ind);
			int u = edge[ind-1].first;
			int v = edge[ind-1].second;
			
			if (depth[v]<depth[u]) swap(u,v);
			
			bt[where[v]].update(v,-1);
		}
		else if (typ==2) {
			int ind;
			scanf("%d",&ind);
			int u = edge[ind-1].first;
			int v = edge[ind-1].second;
			
			if (depth[v]<depth[u]) swap(u,v);
			
			bt[where[v]].update(v,1);
		} 
		else {
			int u,v;
			scanf("%d%d",&u,&v);
			u--; v--;
			int sum = 0;
			if (u==root) {
				sum = bt[where[v]].get(v);
				if (sum==0) printf("%d\n",depth[v]);
				else printf("-1\n");
			}
			else if (v==root) {
				sum = bt[where[u]].get(u);
				if (sum==0) printf("%d\n",depth[u]);
				else printf("-1\n");
			}
			else if (where[v]==where[u]) {
				if (depth[v]<depth[u]) swap(u,v);
				
				sum = bt[where[v]].get(v) - bt[where[u]].get(u);
				
				if (sum==0) printf("%d\n",depth[v]-depth[u]);
				else printf("-1\n");
			}
			else {
				sum = bt[where[v]].get(v) + bt[where[u]].get(u);
				if (sum==0) printf("%d\n",depth[v]+depth[u]);
				else printf("-1\n");
			}
		}
	}
				

    return 0;

}
