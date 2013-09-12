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
int par[100010];
int x[100010], y[100010], c[100010];
int p[100010];
int v[100010];
bool use[100010];
int cnt;
int t;
int si[100010];
int point[100010], next[100010], head[100010];
int fr[100010];
int low[100010], dfn[100010];
bool vis[100010];
int edge[100010];

void add(int xx, int yy, int ind) {
	point[++cnt] = yy; edge[cnt] = ind; next[cnt] = head[xx]; head[xx] = cnt;
}

bool cmp(int i, int j) {
	return c[p[i]]<c[p[j]];
}

int get(int a) {
	if (a==par[a]) return a;
	par[a] = get(par[a]);
	return par[a];
}

void merge(int xx, int yy) {
	xx = get(xx); yy = get(yy);
	if (si[xx]>si[yy]) {
		si[yy]++;
		par[xx] = yy;
	}
	else {
		si[xx]++;
		par[yy] = xx;
	}
}

void tarjan(int q) {
	vis[q] = 1;
	dfn[q] = low[q] = ++t;
	for (int i=head[q]; i; i=next[i]) {
		if (!vis[point[i]]) {
			fr[point[i]] = edge[i];
			tarjan(point[i]);
			low[q] = min(low[q],low[point[i]]);
		}
		else if (fr[q]!=edge[i]) {
			low[q] = min(low[q],dfn[point[i]]);
		}
	}
	//cout<<q<<" "<<fr[q]<<" "<<low[q]<<" "<<dfn[q]<<endl;
	if (fr[q]&&low[q]==dfn[q]) v[fr[q]] = 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<=n; i++) par[i] = i;
	for (int i=1; i<=m; i++) p[i] = i;
	for (int i=1; i<=m; i++) scanf("%d%d%d",x+i,y+i,c+i);
	sort(p+1,p+m+1,cmp);
	
	for (int i=1; i<=m; i++) {//cout<<i<<" "<<p[i]<<" "<<c[p[i]]<<" "<<x[p[i]]<<" "<<y[p[i]]<<endl;
		if (i!=1 && c[p[i]]==c[p[i-1]]) continue;
		int k = i;
		while (k<=m && c[p[i]]==c[p[k]]) {
			use[k] = 1;
			if (get(x[p[k]])==get(y[p[k]])) {
				v[p[k]] = 2;
				use[k] = 0;
			}
			k++;
		}
		k--;

		cnt = 0;
		t = 0;
		for (int j=i; j<=k; j++) if (use[j]) {
			int xx = get(x[p[j]]);
			int yy = get(y[p[j]]);
			head[xx] = 0;
			head[yy] = 0;
			vis[xx] = 0; vis[yy] = 0;
			fr[xx] = 0; fr[yy] = 0;
		}
		for (int j=i; j<=k; j++) if (use[j]) {
			add(get(x[p[j]]),get(y[p[j]]),p[j]);
			add(get(y[p[j]]),get(x[p[j]]),p[j]);
		}
		for (int j=i; j<=k; j++) if (use[j]) {
			int xx = get(x[p[j]]);
			int yy = get(y[p[j]]); 
			if (!vis[xx]) tarjan(xx);
			if (!vis[yy]) tarjan(yy);
		}
		for (int j=i; j<=k; j++) if (use[j]) {
			int xx = get(x[p[j]]);
			int yy = get(y[p[j]]);
			if (xx!=yy) merge(xx,yy);
		}
	}
	
	for (int i=1; i<=m; i++) {
		if (v[i]==0) cout<<"at least one"<<endl;
		else if (v[i]==1) cout<<"any"<<endl;
		else cout<<"none"<<endl;
	}
	
    return 0;

}
