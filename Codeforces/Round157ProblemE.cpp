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

int n,mm;
vector<int> e[100010];
int nd[100010];
int m[100010];
int si[100010];	
int k;
vector<pair<int,int> > intv[100010];
int c[100010];
int v[300100];
int cnt[300100];
bool flag[300100];
void doit(int id, int l, int r) {
	if (v[id]>0) {
		cnt[id] = r-l+1;
	}
	else {
		if (l==r) {
			cnt[id] = 0;
		}
		else {
			cnt[id] = cnt[2*id] + cnt[2*id+1];
		}
	}
}

void update(int id, int l, int r, int ll, int rr, int t) {
	if (l>rr || r<ll) return;
	if (l>=ll && r<=rr) {
		v[id] += t;
		doit(id,l,r);
		return;
	}
	
	int h = (l+r)/2;
	update(2*id,l,h,ll,rr,t);
	update(2*id+1,h+1,r,ll,rr,t);
	
	doit(id,l,r);
}

int query(int id, int l, int r) {
	return cnt[id];
}
		

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}

void dfs(int u, int v) {
	si[u] = 1;
	m[u] = -1;
	rep(it,e[u]) {
		int p = *it;
		if (p==v) continue;
		dfs(p,u);
		si[u] += si[p];
		if (m[u]==-1) m[u] = m[p];
	}
	nd[u] = ++k;
	if (m[u]==-1) m[u] = k;
}

void dfs2(int u, int v) {
	for (int i=0; i<intv[u].size(); i++) {
		update(1,1,n,intv[u][i].first+1, intv[u][i].second+1,1);
	}
	if (intv[u].size()!=0) update(1,1,n,m[u]+1,nd[u]+1,1);

	c[u] = query(1,1,n);
	if (c[u]>0) c[u]--;
	
	rep(it,e[u]) {
		int p = *it;
		if (p==v) continue;
		dfs2(p,u);
	}
	
	for (int i=0; i<intv[u].size(); i++) {
		update(1,1,n,intv[u][i].first+1, intv[u][i].second+1,-1);
	}
	if (intv[u].size()!=0) update(1,1,n,m[u]+1,nd[u]+1,-1);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>mm;
	for (int i=0; i<n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	k = 0;
	dfs(0,-1);
	
	for (int i=0; i<mm; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		intv[a].push_back(make_pair(m[b],nd[b]));
		intv[b].push_back(make_pair(m[a],nd[a]));
	}
	
	dfs2(0,-1);
	
	for (int i=0; i<n; i++) printf("%d ",c[i]);
	
    return 0;

}
