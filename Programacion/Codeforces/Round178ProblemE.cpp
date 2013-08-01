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

vector<int> e[5010];
int n;
bool forb[5010];
int x[5010];
int y[5010];
int si[5010];
long long sp[1010];
int w[5010];
long long dist[5010];
bool vis[5010];
int comp[5010];
int siz[2];

long long dfs(int u, int v, int k) {
	vis[u] = 1;
	comp[u] = k;
	si[u] = 1;
	sp[u] = 0;
	for (int i=0; i<e[u].size(); i++) if (!forb[e[u][i]]) {
		int p;
		if (u==x[e[u][i]]) p = y[e[u][i]];
		else p = x[e[u][i]];
		
		if (p==v) continue;
		
		sp[u] += dfs(p,u,k);
		sp[u] += (long long)w[e[u][i]]*si[p];
		si[u] += si[p];
	}
	
	return sp[u];
}

void dfs2(int u, int v, int wp) {
	if (v==-1) {
		for (int i=0; i<e[u].size(); i++) if (!forb[e[u][i]]) {
			int p;
			if (u==x[e[u][i]]) p = y[e[u][i]];
			else p = x[e[u][i]];
			
			if (p==v) continue;
			
			dfs2(p,u,w[e[u][i]]);
		}
	}
	else {
		
		dist[u] = (long long)wp*(siz[comp[u]]-si[u]);
		dist[u] += (long long)(dist[v]-sp[u]-(long long)si[u]*wp) + sp[u];
		
		for (int i=0; i<e[u].size(); i++) if (!forb[e[u][i]]) {
			int p;
			if (u==x[e[u][i]]) p = y[e[u][i]];
			else p = x[e[u][i]];
			
			if (p==v) continue;
			
			dfs2(p,u,w[e[u][i]]);
		}
	}
}
		

long long solve() {
	for (int i=0; i<n; i++) vis[i] = 0;
	for (int i=0; i<n; i++) comp[i] = 0;
	int k = 0;
	int n1,n2;
	for (int i=0; i<n; i++) if (!vis[i]) {
		dist[i] = dfs(i,-1,++k);
		siz[k] = si[i];
		if (k==1) n1 = si[i];
		else n2 = si[i];
		dfs2(i,-1,0);
	}
	
	//for (int i=0; i<n; i++) {
	//	cout<<i+1<<" "<<comp[i]<<" "<<dist[i]<<" "<<sp[i]<<endl;
	//}cout<<endl;
	
	long long d1 = 1LL<<60;
	long long d2 = 1LL<<60;
	long long s1 = 0;
	long long s2 = 0;
	
	long long s = 0;
	
	for (int i=0; i<n; i++) {
		if (comp[i]==1) {
			d1 = min(d1,dist[i]);
			s1 += dist[i];
		}
		else {
			d2 = min(d2,dist[i]);
			s2 += dist[i];
		}
	}
	
	s1/=2;
	s2/=2;
	
	long long wf = 0;
	for (int i=0; i<n-1; i++) if (forb[i]) wf = w[i];
	
	//cout<<d1<<" "<<d2<<" "<<s1<<" "<<s2<<" "<<n1<<" "<<n2<<" "<<wf<<endl<<endl;
	
	s = s1 + s2 + (long long)n1*n2*wf + (long long)n1*d2 + (long long)n2*d1;

	return s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n-1; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--; b--;
		x[i] = a;
		y[i] = b;
		w[i] = c;
		e[a].push_back(i);
		e[b].push_back(i);
	}
	
	long long ans = 1LL<<60;
	for (int i=0; i<n-1; i++) {
		forb[i] = 1;
		ans = min(solve(),ans);
		forb[i] = 0;
	}
	
	cout<<ans<<endl;

    return 0;

}
