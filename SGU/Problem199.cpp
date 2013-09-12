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

int n;
int x[100010];
pair<int,int> w[100010];
int y[100010];
int dp[100010];
int q[100010];
int last[100010];
int s[100010];
map<int,int> m;

bool cmp(int i, int j) {
	if (y[i]==y[j]) return w[i].first>w[j].first;
	return y[i]<y[j];
}

int v[300010];
int pre[300010];
void update(int id, int l, int r, int t, int val,int ind) {
	if (l>t || r<t) return;
	if (l==r && l==t) {
		if (v[id]<val) {
			v[id] = val;
			pre[id] = ind;
		}
		return;
	}
	int h = (l+r)/2;
	update(2*id,l,h,t,val,ind);
	update(2*id+1,h+1,r,t,val,ind);
	if (v[2*id]>v[2*id+1]) {
		v[id] = v[2*id];
		pre[id] = pre[2*id];
	}
	else {
		v[id] = v[2*id+1];
		pre[id] = pre[2*id+1];
	}
}

pair<int,int> get(int id, int l, int r, int ll, int rr) {
	if (ll>rr) return mp(-1,0);
	if (l>rr || r<ll) return mp(-1,0);
	if (l>=ll && r<=rr) return make_pair(v[id],pre[id]);
	int h = (l+r)/2;
	pair<int,int> t1 = get(2*id,l,h,ll,rr);
	pair<int,int> t2 = get(2*id+1,h+1,r,ll,rr);
	if (t1.first>t2.first) return t1;
	else return t2;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
	for (int i=0; i<n; i++) w[i] = mp(x[i],i+1);
	for (int i=0; i<n; i++) q[i] = i;
	sort(q,q+n,cmp);
	for (int i=0; i<n; i++) x[i] = w[q[i]].first;
	for (int i=0; i<n; i++) q[i] = w[q[i]].second;
	
	int ans = 0;
	
	for (int i=0; i<n; i++) s[i] = x[i];
	sort(s,s+n);
	int cnt = 0;
	for (int i=0; i<n; i++) if (i==0 || s[i]!=s[i-1]) m[s[i]] = ++cnt;
	for (int i=0; i<n; i++) x[i] = m[x[i]];
	
	for (int i=0; i<n; i++) {
		
		pii p = get(1,1,n,1,x[i]-1);
		dp[i] = 1;
		last[i] = i;
		if (p.first>0) {
			dp[i] = p.first+1;
			last[i] = p.second;
		}
		
		update(1,1,n,x[i],dp[i],i);
	}
	
	int p;
	for (int i=0; i<n; i++) {
		if (ans<dp[i]) {
			ans = dp[i];
			p = i;
		}
	}
	
	cout<<ans<<endl;
	while (true) {
		cout<<q[p]<<" ";
		if (p==last[p]) break;
		p = last[p];
	}

    return 0;

}
