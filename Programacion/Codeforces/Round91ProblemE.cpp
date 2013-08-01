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

#define MAXN 3*100010

set<int> ln;
int n,m;
int v[MAXN];
int dif[MAXN];
int c[MAXN];
int left[MAXN];

void dfs(int t) {
	if (t>10000) return;
	if (t!=0) ln.insert(t);
	
	dfs(t*10+4);
	dfs(t*10+7);
}	

void init(int id, int l, int r, int i, int t) {
	if (l==r && l==i) {
		v[id] = t;
		set<int>::iterator it = lower_bound(ln.begin(),ln.end(),t);
		dif[id] = (*it) - t;
		if (dif[id]==0) c[id] = 1;
		else c[id] = 0;
		return;
	}
	if (i>r || i<l) return;
	int h = (l+r)/2;
	update(2*id,l,h,i,t);
	update(2*id+1,h+1,r,i,t);
	dif[id] = min(dif[2*id],dif[2*id+1]);
	c[id] = c[2*id]+c[2*id+1];
}

int query(int id, int l, int r, int ll, int rr) {
	if (r<ll || l>rr) return 0;
	if (l>=ll && r<=rr) return c[id];
	int h = (l+r)/2;
	return query(2*id,l,h,ll,rr)+query(2*id+1,h+1,r,ll,rr);
} 

int update(int id, int l, int r, int ll, int rr, int t) {
	if (l>rr || r<l) return 1000000;
	if (l>=ll && r<=rr) {
		if (dif[id]-t>0) {
			dif[id] -= t;
			left[id] += t;
		}
		else {
			if (l==r) {
				v[id] += t;
				set<int>::iterator it = lower_bound(ln.begin(),ln.end(),v[id]);
				dif[id] = (*it) - t;
				if (dif[id]==0) c[id] = 1;
				else c[id] = 0;
			}
			else {
				int h = (l+r)/2;
				update(2*id,l,h,ll,rr,t+left[id]);
				

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	dfs(0);
	ln.insert(1000000);
	for (int i=0; i<n; i++) {
		int a;
		scanf("%d",&a);
		init(1,1,n,i+1,a);
	}
	
	for (int i=0; i<m; i++) {
		string s;
		cin>>s;
		if (s=="count") {
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",query(1,1,n,a,b));
		}
		else {
			int a,b,d;
			scanf("%d%d%d",&a,&b,&d);
			update(1,1,n,a,b,d);
		}
	}

    return 0;

}
