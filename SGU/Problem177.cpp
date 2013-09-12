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
pair<pii,pii> d[5001];
int w[5001];
int v[2050];
int t[2050];

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void init(int id, int l, int r) {
	if (l==r) {
		v[id] = 1;
		t[id] = 0;
		return;
	}
	int h = (l+r)>>1;
	init(2*id,l,h); init(2*id+1,h+1,r);
	v[id] = 0;
	t[id] = 0;
}

void update(int id, int l, int r, int ll, int rr, int c, int tm) {
	if (l>rr || r<ll) return;
	if (l>=ll && r<=rr) {
		t[id] = tm;
		v[id] = c;
		return;
	}
	int h = (l+r)>>1;
	update(2*id,l,h,ll,rr,c,tm);
	update(2*id+1,h+1,r,ll,rr,c,tm);
}

int get(int id, int l, int r, int c, int tm) {
	if (l==r) {
		if (tm>t[id]) return c==1;
		else return v[id]==1;
	}
	
	if (tm>t[id]) {
		int tmp = 0;
		int h = (l+r)>>1;
		tmp += get(2*id,l,h,c,tm);
		tmp += get(2*id+1,h+1,r,c,tm);
		return tmp;
	}
	else {
		int tmp = 0;
		int h = (l+r)>>1;
		tmp += get(2*id,l,h,v[id],t[id]);
		tmp += get(2*id+1,h+1,r,v[id],t[id]);
		return tmp;
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x1,y1,x2,y2;
		char c;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2); 
		cin>>c;
		
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		
		d[i] = mp(mp(x1,y1),mp(x2,y2));
		w[i] = (c=='w'?1:2);
	}
	
	int res = 0;
	for (int i=1; i<=n; i++) {
		init(1,1,n);
		for (int j=0; j<m; j++) {
			if (i>=d[j].first.first && i<=d[j].second.first) {
				update(1,1,n,d[j].first.second,d[j].second.second,w[j],j+1);
			}
		}
		res += get(1,1,n,1,-1);
	}
	
	cout<<res<<endl;

    return 0;

}
